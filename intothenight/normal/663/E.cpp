#include <bits/stdc++.h>
using namespace std;

template<class T, char Conv = '^'>
void fast_walsh_hadamard_transform(vector<T> &a, const bool invert = false){
	int n = (int)a.size();
	for(auto len = 1; len < n; len <<= 1){
		for(auto i = 0; i < n; i += len << 1){
			for(auto j = 0; j < len; ++ j){
				T u = a[i + j], v = a[i + j + len];
				if(Conv == '^') a[i + j] = u + v, a[i + j + len] = u - v;
				if(Conv == '|') a[i + j + len] += invert ? -u : u;
				if(Conv == '&') a[i + j] += invert ? -v : v;
			}
		}
	}
	if(Conv == '^' && invert){
		for(auto &x: a) x /= n;
	}
}
template<class T, char Conv = '^'>
vector<T> convolute(vector<T> p, vector<T> q){
	int n = max({(int)p.size(), (int)q.size() - 1, 1});
	if(__builtin_popcount(n) != 1) n = 1 << __lg(n) + 1;
	p.resize(n), q.resize(n);
	fast_walsh_hadamard_transform<T, Conv>(p), fast_walsh_hadamard_transform<T, Conv>(q);
	for(auto i = 0; i < n; ++ i) p[i] *= q[i];
	fast_walsh_hadamard_transform<T, Conv>(p, true);
	return p;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, m;
	cin >> n >> m;
	vector<string> a(n);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i];
	}
	vector<long long> appear(1 << n), c(1 << n);
	for(auto j = 0; j < m; ++ j){
		int mask = 0;
		for(auto i = 0; i < n; ++ i){
			mask |= a[i][j] - '0' << i;
		}
		++ appear[mask];
	}
	for(auto mask = 0; mask < 1 << n; ++ mask){
		c[mask] = min(__builtin_popcount(mask), n - __builtin_popcount(mask));
	}
	auto res = convolute(appear, c);
	cout << *min_element(res.begin(), res.end()) << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////