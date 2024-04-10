#include <bits/stdc++.h>
using namespace std;

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
template<typename Poly>
Poly operator+(const Poly &a, const Poly &b){
	Poly res(max(int(a.size()), int(b.size())));
	for(int i = 0; i < min(int(a.size()), int(b.size())); ++ i) res[i] = a[i] + b[i];
	for(int i = min(int(a.size()), int(b.size())); i < int(a.size()); ++ i) res[i] = a[i];
	for(int i = min(int(a.size()), int(b.size())); i < int(b.size()); ++ i) res[i] = b[i];	
	return res;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n, m, qq;
	cin >> n >> m >> qq;
	const int mx = 1e5;
	vector<int> a(n), b(m);
	vector<long long> cnta(mx + 1), cntb(mx + 1), cntmina(mx + 1), cntmaxa(mx + 1), cntminb(mx + 1), cntmaxb(mx + 1);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i];
		++ cnta[a[i]];
	}
	for(auto i = 1; i < n; ++ i){
		++ cntmina[min(a[i - 1], a[i])], ++ cntmaxa[max(a[i - 1], a[i])];
	}
	for(auto i = 0; i < m; ++ i){
		cin >> b[i];
		++ cntb[b[i]];
	}
	for(auto i = 1; i < m; ++ i){
		++ cntminb[min(b[i - 1], b[i])], ++ cntmaxb[max(b[i - 1], b[i])];
	}
	auto v = cnta * cntb, e0 = cnta * cntminb + cntmina * cntb, e1 = cnta * cntmaxb + cntmaxa * cntb, u0 = cntmina * cntminb, u1 = cntmaxa * cntmaxb;
	v.resize(mx << 1 | 1), e0.resize(mx << 1 | 1), e1.resize(mx << 1 | 1), u0.resize(mx << 1 | 1), u1.resize(mx << 1 | 1);
	vector<long long> prefv(int(v.size()) + 1), prefe0(int(e0.size()) + 1), prefe1(int(e1.size()) + 1), prefu0(int(u0.size()) + 1), prefu1(int(u1.size()) + 1);
	partial_sum(v.begin(), v.end(), prefv.begin() + 1);
	partial_sum(e0.begin(), e0.end(), prefe0.begin() + 1);
	partial_sum(e1.begin(), e1.end(), prefe1.begin() + 1);
	partial_sum(u0.begin(), u0.end(), prefu0.begin() + 1);
	partial_sum(u1.begin(), u1.end(), prefu1.begin() + 1);
	while(qq --){
		int x;
		cin >> x;
		cout << ((prefv[mx << 1 | 1] - prefv[x]) - (prefe0[mx << 1 | 1] - prefe0[x]) + (prefu0[mx << 1 | 1] - prefu0[x])) - (prefv[x] - prefe1[x] + prefu1[x]) << "\n";
	}
	return 0;
}

/*
V-E+I+U = C
C-I = V-E+U
0: >=, 1: <
ans = C0 + I1 - C1 - I0 = (V0-E0+U0) - (V1-E1+U1)
*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////