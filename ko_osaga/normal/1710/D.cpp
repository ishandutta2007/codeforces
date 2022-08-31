#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;
const int MAXN = 2005;

int n;
char str[MAXN][MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t; cin >> t;
	while(t--){
		cin >> n;
		for(int i = 0; i < n; i++){
			string q; cin >> q;
			for(int j = i; j < n; j++){
				str[i][j] = str[j][i] = q[j - i];
			}
		}
		set<pi> s;
		for(int i = 0; i < n; i++){
			s.emplace(i, i);
		}
		vector<pi> ans;
		auto addEdge = [&](int s, int e){
	//		cout << "add edge" << s << " " << e << endl;
			ans.emplace_back(s, e);
		};
		for(int i = 1; i < n; i++){
			for(int j = 0; j + i < n; j++){
				if(str[j][j + i] == '0') continue;
				auto it = s.lower_bound(pi(j + 1, -1));
				assert(it != s.begin());
				it--;
				vector<pi> v;
		//		cout << "this session " << j << " " << j + i << endl;
				while(it != s.end() && it->first <= j + i){
				//	cout << it->first << " " << it->second << endl;
					v.push_back(*it);
					it = s.erase(it);
				}
				s.emplace(v[0].first, v.back().second);
				if(v[0].first != j) v[0].first = max(v[0].first, j);
				if(v.back().second != j + i) v.back().second = min(v.back().second, j + i);
				if(sz(v) == 1) continue;
				assert(sz(v) == 2 || sz(v) >= 4);
				if(sz(v) == 2){
					addEdge(v[0].first, v[1].second);
				}
				else if(sz(v) % 2 == 1){
					addEdge(v[0].first, v.back().second);
					addEdge(v[0].first, v[2].second);
					addEdge(v[0].first, v[3].second);
					addEdge(v[1].first, v[4].second);
					for(int i = 4; i + 2 < sz(v); i += 2){
						addEdge(v[i].first, v[i + 2].second);
					}
					for(int i = 5; i < sz(v); i += 2){
						addEdge(v[i - 2].first, v[i].second);
					}
				}
				else{
					addEdge(v[0].first, v.back().second);
					for(int i = 2; i < sz(v); i += 2){
						addEdge(v[i - 2].first, v[i].second);
					}
					for(int i = 1; i + 2 < sz(v); i += 2){
						addEdge(v[i].first, v[i + 2].second);
					}
				}
			}
		}
		assert(sz(ans) == n - 1);
		for(auto &[x, y] : ans) cout << x + 1 << " " << y + 1 << "\n";
	}
}