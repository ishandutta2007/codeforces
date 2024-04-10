#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(n, vector<int>(m)), b;
	vector<int> cnt(m);
	b = a;
	map<int, int> mp;
	int mod = (int)1e9 + 7;
	mt19937 gen(time(NULL));
	int gop = ((gen() << 31) | gen()) % mod;
	for(int i = 0; i < n; ++i){
		int val = 0;
		for(int j = 0; j < m; ++j){
			cin >> a[i][j];
			val *= gop, val %= mod;
			val += a[i][j];
		}
		++mp[val];
	}
	int dif = 0;
	for(int i = 0; i < n; ++i){
		int val = 0;
		for(int j = 0; j < m; ++j){
			cin >> b[i][j];
			if(i && b[i][j] < b[i - 1][j]){
				++cnt[j];
			}
			val *= gop, val %= mod;
			val += b[i][j];
			if(a[i][j] != b[i][j]){
				dif = 1;
			}
		}
		if(!mp[val]){
			cout << -1;
			return 0;
		}
		--mp[val];
	}
	if(!dif){
		cout << 0; return 0;
	}
	vector<int> chk(n), ans, pchk(m);
	priority_queue<pair<int, int>> pq;
	for(int i = 0; i < m; ++i){
		pq.push({-cnt[i], i});
	}
	while(!pq.empty()){
		int top = pq.top().second; pq.pop();
		if(pchk[top]){
			continue;
		}
		pchk[top] = 1;
		for(int i = 1; i < n; ++i){
			if(b[i][top] < b[i - 1][top] && !chk[i - 1]){
				cout << -1; return 0;
			}
		}
		ans.push_back(top);
		for(int i = 1; i < n; ++i){
			if(b[i][top] != b[i - 1][top] && !chk[i - 1]){
				chk[i - 1] = 1;
				for(int j = 0; j < m; ++j){
					if(b[i - 1][j] > b[i][j]){
						--cnt[j];
						pq.push({-cnt[j], j});
					}
				}
			}
		}
	}
	reverse(ans.begin(), ans.end());
	cout << (int)ans.size() << '\n';
	for(auto&i:ans){
		cout << i + 1 << ' ';
	}
	return 0;
}