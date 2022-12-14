#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 998244353;

pair<int, int> extgcd(int a, int b) {
   	if(!b) return {1, 0};
    pair<int, int> val = extgcd(b, a % b);
    return {val.second, val.first - (a / b) * val.second};
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m; cin >> n >> m;
	vector<vector<int>> a(n, vector<int>(m));
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			cin >> a[i][j];
		}
	}
	int ans = 0;
	int fact = 1;
	for(int i = 1; i <= n; ++i){
		fact = fact * i % mod;
	}
	for(int j = 0; j < m; ++j){
		vector<int> now;
		for(int i = 0; i < n; ++i){
			now.push_back(a[i][j] - 1);
		}
		sort(now.begin(), now.end());
		reverse(now.begin(), now.end());
		int way = 1, pos = 0;
		for(int i = n; i >= 1; --i){
			while(pos < n && now[pos] >= i) ++pos;
			way *= (pos - n + i); way %= mod;
			if(pos - n + i < 0){
				way = 0;
				break;
			}
		}
		ans += (fact - way + mod) % mod; ans %= mod;
	}
	cout << ans * (extgcd(fact, mod).first + mod) % mod << '\n';
	return 0;
}