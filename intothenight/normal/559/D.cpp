#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	vector<array<long long, 2>> p(n);
	for(auto i = 0; i < n; ++ i){
		for(auto j = 0; j < 2; ++ j){
			cin >> p[i][j];
		}
	}
	for(auto i = 0; i < 200; ++ i){
		p.push_back(p[i]);
	}
	vector<long long> a((int)p.size());
	vector<long long> b((int)p.size());
	auto prod = [&](auto p, auto q){
		return p[0] * q[1] - p[1] * q[0];
	};
	auto count = [&](auto p, auto q){
		return gcd(p[0] - q[0], p[1] - q[1]);
	};
	for(auto i = 1; i < (int)p.size(); ++ i){
		a[i] = a[i - 1] + prod(p[i - 1], p[i]);
		b[i] = b[i - 1] + count(p[i - 1], p[i]);
	}
	cout << fixed << setprecision(15);
	vector<long double> pow2(201, 1), powinv2(200001, 1);
	for(auto i = 1; i <= 200; ++ i){
		pow2[i] = pow2[i - 1] * 2;
	}
	for(auto i = 1; i <= 200000; ++ i){
		powinv2[i] = powinv2[i - 1] / 2;
	}
	long double res = (a[n] - b[n]) / 2.0 + 1;
	for(auto i = 0; i < n; ++ i){
		for(auto cnt = 2; cnt < min(n, 60); ++ cnt){
			int j = i + cnt - 1;
			long double coef = n >= 100 ? powinv2[cnt] : (pow2[n - cnt] - 1) / (pow2[n] - 1 - n - 1LL * n * (n - 1) / 2);
			long double area = (a[j] - a[i] + prod(p[j], p[i])) / 2.0;
			long double boundary = b[j] - b[i] + count(p[j], p[i]);
			long double loss = area - boundary / 2 + count(p[j], p[i]);
			res -= loss * coef;
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