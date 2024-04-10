#include <bits/stdc++.h>
using namespace std;

template<class F>
struct y_combinator_result{
	F f;
	template<class T> explicit y_combinator_result(T &&f): f(forward<T>(f)){ }
	template<class ...Args> decltype(auto) operator()(Args &&...args){ return f(ref(*this), forward<Args>(args)...); }
};
template<class F>
decltype(auto) y_combinator(F &&f){
	return y_combinator_result<decay_t<F>>(forward<F>(f));
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, k;
	cin >> n >> k;
	int cnt = 0;
	{
		int p = 1;
		while(p < n){
			p *= k;
			++ cnt;
		}
	}
	cout << cnt << "\n";
	vector<vector<int>> col(n, vector<int>(n, -1));
	y_combinator([&](auto self, int l, int r, int c)->void{
		if(r - l <= 1){
			return;
		}
		int sz = (r - l + k - 1) / k;
		vector<array<int, 2>> g;
		for(auto i = 0; i < k; ++ i){
			int left = clamp(l + i * sz, l, r);
			int right = clamp(l + (i + 1) * sz, l, r);
			self(left, right, c + 1);
			g.push_back({left, right});
		}
		for(auto i = 0; i < k; ++ i){
			for(auto j = i + 1; j < k; ++ j){
				for(auto u = g[i][0]; u < g[i][1]; ++ u){
					for(auto v = g[j][0]; v < g[j][1]; ++ v){
						col[u][v] = c;
					}
				}
			}
		}
	})(0, n, 0);
	for(auto u = 0; u < n; ++ u){
		for(auto v = u + 1; v < n; ++ v){
			cout << col[u][v] + 1 << " ";
		}
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