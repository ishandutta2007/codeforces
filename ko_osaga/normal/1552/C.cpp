#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;
const int mod = 1e9 + 7;
const int MAXN = 100005;

int a[22];

int main(){
	int t; scanf("%d",&t);
	while(t--){
		int n, k;
		cin >> n >> k;
		set<int> rems;
		for(int i = 1; i <= 2 * n; i++){
			rems.insert(i);
		}
		vector<pi> vect;
		for(int i = 0; i < k; i++){
			int s, e; cin >> s >> e;
			rems.erase(s);
			rems.erase(e);
			if(s > e) swap(s, e);
			vect.emplace_back(s, e);
		}
		{
			vector<int> foo;
			for(auto &i : rems) foo.push_back(i);
			for(int i = 0; i < sz(foo)/2; i++){
				vect.emplace_back(foo[i], foo[i + sz(foo)/2]);
			}
		}
		sort(all(vect));
		int ret = 0;
		for(int i = 0; i < sz(vect); i++){
			for(int j = 0; j < i; j++){
				if(vect[j].second > vect[i].first &&
					vect[i].second > vect[j].second) ret++;
			}
		}
		cout << ret << endl;
	}
}