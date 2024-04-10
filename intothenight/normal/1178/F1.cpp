#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> c(n), pos(n + 1);
	for(int i = 0; i < n; i ++){
		cin >> c[i];
		pos[c[i]] = i;
	}
	vector<vector<ll>> d(n, vector<ll>(n));
	function<ll(int, int)> solve = [&](int l, int r)->ll{
		if(l >= r){
			return 1;
		}
		if(d[l][r]){
			return d[l][r];
		}
		int p = l;
		for(int i = l + 1; i <= r; i ++){
			if(c[i] < c[p]){
				p = i;
			}
		}
		ll resL = 0, resR = 0;
		for(int i = l; i <= p; i ++){
			(resL += solve(l, i - 1) * solve(i, p - 1)) %= MOD;
		}
		for(int i = p; i <= r; i ++){
			(resR += solve(p + 1, i) * solve(i + 1, r)) %= MOD;
		}
		return d[l][r] = resL * resR % MOD;
	};
	cout << solve(0, n - 1);
	return 0;
}