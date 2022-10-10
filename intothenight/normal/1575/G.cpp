#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	const int mod = 1e9 + 7;
	auto add = [&](int x, int y)->int{
		x += y;
		if(x >= mod){
			x -= mod;
		}
		return x;
	};
	auto mul = [&](int x, int y)->int{
		return 1LL * x * y % mod;
	};
	const int mx = 1e5;
	vector<int> lpf(mx + 1), prime, phi(mx + 1, 1), sum(mx + 1);
	for(auto x = 2; x <= mx; ++ x){
		if(!lpf[x]){
			lpf[x] = x;
			prime.push_back(x);
		}
		if(x / lpf[x] % lpf[x]){
			phi[x] = phi[x / lpf[x]] * (lpf[x] - 1);
		}
		else{
			phi[x] = phi[x / lpf[x]] * lpf[x];
		}
		for(auto i = 0; i < (int)prime.size() && prime[i] <= lpf[x] && prime[i] * x <= mx; ++ i){
			lpf[prime[i] * x] = prime[i];
		}
	}
	vector<vector<int>> div(mx + 1);
	for(auto x = 1; x <= mx; ++ x){
		for(auto y = x; y <= mx; y += x){
			sum[y] = add(sum[y], phi[x]);
			div[y].push_back(x);
		}
	}
	int n;
	cin >> n;
	vector<int> a(n);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i];
	}
	int res = 0;
	vector<int> cnt(mx + 1);
	for(auto x = 1; x <= n; ++ x){
		int cur = 0;
		for(auto y = x; y <= n; y += x){
			for(auto d: div[a[y - 1]]){
				cur = add(cur, mul(phi[d], 2 * cnt[d] + 1));
				++ cnt[d];
			}
		}
		res = add(res, mul(phi[x], cur));
		for(auto y = x; y <= n; y += x){
			for(auto d: div[a[y - 1]]){
				-- cnt[d];
			}
		}
	}
	cout << res << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////