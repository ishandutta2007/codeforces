#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll MOD = 998244353;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> c(m);
	vector<vector<int>> pos(n + 1);
	for(int i = 0; i < m; i ++){
		cin >> c[i];
		pos[c[i]].push_back(i);
	}
	for(int i = 1; i < n; i ++){
		for(int j = i + 1; j <= n; j ++){
			if(lower_bound(pos[i].begin(), pos[i].end(), pos[j].front()) != lower_bound(pos[i].begin(), pos[i].end(), pos[j].back())){
				cout << 0;
				return 0;
			}
		}
	}
	function<ll(int, int)> solve = [&](int l, int r)->ll{
		if(l >= r){
			return 1;
		}
		vector<int> arr;
		ll res = 1;
		for(int i = l; i <= r; i = pos[c[i]].back() + 1){
			arr.push_back(c[i]);
			for(int j = 0; j + 2 <= pos[c[i]].size(); j ++){
				(res *= solve(pos[c[i]][j] + 1, pos[c[i]][j + 1] - 1)) %= MOD;
			}
		}
		vector<vector<ll>> d(arr.size(), vector<ll>(arr.size()));
		function<ll(int, int)> psolve = [&](int l, int r)->ll{
			if(l >= r){
				return 1;
			}
			if(d[l][r]){
				return d[l][r];
			}
			int p = l;
			for(int i = l + 1; i <= r; i ++){
				if(arr[i] < arr[p]){
					p = i;
				}
			}
			ll resL = 0, resR = 0;
			for(int i = l; i <= p; i ++){
				(resL += psolve(l, i - 1) * psolve(i, p - 1)) %= MOD;
			}
			for(int i = p; i <= r; i ++){
				(resR += psolve(p + 1, i) * psolve(i + 1, r)) %= MOD;
			}
			return d[l][r] = resL * resR % MOD;
		};
		return res * psolve(0, arr.size() - 1) % MOD;
	};
	cout << solve(0, m - 1);
	return 0;
}