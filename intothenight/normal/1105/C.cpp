#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	const int mod = 1e9 + 7;
	int n, l, r;
	cin >> n >> l >> r;
	array<int, 3> coef{r / 3 - (l - 1) / 3, (r + 2) / 3 - (l + 1) / 3, (r + 1) / 3 - l / 3};
	array<int, 3> res{1, 0, 0};
	auto convolute = [&](auto p, auto q){
		array<int, 3> r{};
		for(auto i = 0; i < 3; ++ i){
			for(auto j = 0; j < 3; ++ j){
				(r[(i + j) % 3] += 1LL * p[i] * q[j] % mod) %= mod;
			}
		}
		return r;
	};
	for(; n; n >>= 1, coef = convolute(coef, coef)){
		if(n & 1){
			res = convolute(res, coef);
		}
	}
	cout << res[0] << "\n";
	return 0;
}

/*
(A+Bx+CX^2)^N
*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////