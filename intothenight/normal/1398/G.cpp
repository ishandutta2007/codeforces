#include "bits/stdc++.h"
using namespace std;
template<typename T, typename U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<typename T, typename U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }
 
 
typedef complex<double> cd;
const double PI = acos(-1);
template<typename IT>
void fft(IT begin, IT end, const bool invert = false){
	int n = distance(begin, end);
	for(int i = 1, j = 0; i < n; ++ i){
		int bit = n >> 1;
		for(; j & bit; bit >>= 1) j ^= bit;
		j ^= bit;
		if(i < j) swap(*(begin + i), *(begin + j));
	}
	for(int len = 1; len < n; len <<= 1){
		double theta = PI / len * (invert ? -1 : 1);
		cd w(cos(theta), sin(theta));
		for(int i = 0; i < n; i += len << 1){
			cd wj(1);
			for(int j = 0; j < len; ++ j, wj *= w){
				cd u = *(begin + i + j), v = wj * *(begin + i + j + len);
				*(begin + i + j) = u + v, *(begin + i + j + len) = u - v;
			}
		}
	}
	if(invert) for(auto it = begin; it != end; ++ it) *it /= n;
}
template<typename Poly>
Poly operator*(const Poly &a, const Poly &b){
	vector<cd> f(a.begin(), a.end()), g(b.begin(), b.end());
	int n = max(int(a.size()) + int(b.size()) - 1, 1);
	if(__builtin_popcount(n) != 1) n = 1 << __lg(n) + 1;
	f.resize(n), g.resize(n);
	fft(f.begin(), f.end()), fft(g.begin(), g.end());
	for(int i = 0; i < n; ++ i) f[i] *= g[i];
	fft(f.begin(), f.end(), true);
	Poly res(n);
	for(int i = 0; i < n; ++ i) res[i] = round(f[i].real());
	while(!res.empty() && !res.back()) res.pop_back();
	return res;
}

template<typename Arr, typename Action>
void for_each_divisor(const Arr &fact, Action f){
	long long d = 1;
	function<void(int)> solve = [&](int i){
		if(i == int(fact.size())){
			f(d);
			return;
		}
		solve(i + 1);
		auto [p, t] = fact[i];
		long long pd = d;
		for(int e = 1; e <= t; ++ e) d *= p, solve(i + 1);
		d = pd;
	};
	solve(0);
}
 
int main(){
	cin.tie(0)->sync_with_stdio(0);
	const int mx = 5e5;
	vector<int> lpf(mx + 1), prime;
	for(auto i = 2; i <= mx; ++ i){
		if(!lpf[i]) lpf[i] = i, prime.push_back(i);
		for(auto j = 0; j < int(prime.size()) && prime[j] <= i && i * prime[j] <= mx; ++ j){
			lpf[i * prime[j]] = prime[j];
		}
	}
	int n, x, y;
	cin >> n >> x >> y;
	vector<int> p(x + 1), q(x + 1);
	for(auto i = 0; i <= n; ++ i){
		int a;
		cin >> a;
		p[a] = q[x - a] = 1;
	}
	vector<int> t = p * q;
	t = {t.begin() + x, t.end()};
	int qq;
	cin >> qq;
	while(qq --){
		int x;
		cin >> x, x >>= 1;
		vector<array<int, 2>> fact;
		while(x > 1){
			int p = lpf[x];
			fact.push_back({p, 0});
			while(!(x % p)){
				x /= p;
				++ fact.back()[1];
			}
		}
		int res = -1;
		auto f = [&](int d){
			if(d > y && d - y < int(t.size()) && t[d - y]){
				ctmax(res, 2 * d);
			}
		};
		for_each_divisor(fact, f);
		cout << res << " ";
	}
	cout << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////