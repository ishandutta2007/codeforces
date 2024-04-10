#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif
template<class T> T &ctmin(T &x){ return x; }
template<class T, class Head, class ...Tail> T &ctmin(T &x, const Head &h, const Tail &... t){ return ctmin(x = min<T>(x, h), t...); }
template<class T> T &ctmax(T &x){ return x; }
template<class T, class Head, class ...Tail> T &ctmax(T &x, const Head &h, const Tail &... t){ return ctmax(x = max<T>(x, h), t...); }



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, m;
	cin >> n >> m;
	const int mx = 160000;
	vector<vector<int>> a(n, vector<int>(m));
	for(auto i = 0; i < n; ++ i){
		for(auto j = 0; j < m; ++ j){
			cin >> a[i][j], -- a[i][j];
		}
	}
	int res = 1;
	for(auto i = 0; i < n; ++ i){
		static array<vector<array<int, 2>>, mx> active;
		active.fill({});
		// active[x]: list of {j, i}, increasing j
		static array<int, 400> h;
		h.fill(i + 1);
		for(auto j = 0; j < m; ++ j){
			for(auto k = 0; k <= i; ++ k){
				int x = a[k][j];
				while(!active[x].empty() && active[x].back()[1] <= k){
					auto [cj, ci] = active[x].back();
					ctmin(h[cj], i - ci);
					active[x].pop_back();
				}
				if(!active[x].empty()){
					ctmin(h[active[x].back()[0]], i - k);
				}
				active[x].push_back({j, k});
			}
			int min_h = numeric_limits<int>::max();
			for(auto jl = j; min_h && jl >= 0; -- jl){
				ctmin(min_h, h[jl]);
				ctmax(res, min_h * (j - jl + 1));
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