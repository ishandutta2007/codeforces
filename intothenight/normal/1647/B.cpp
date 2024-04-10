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
	auto __solve_tc = [&](auto __tc_num)->int{
		int n, m;
		cin >> n >> m;
		vector<string> a(n);
		for(auto i = 0; i < n; ++ i){
			cin >> a[i];
		}
		static const vector<pair<int, int>> dr{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
		vector<vector<int>> vis(n, vector<int>(m));
		for(auto i = 0; i < n; ++ i){
			for(auto j = 0; j < m; ++ j){
				if(!vis[i][j] && a[i][j] & 1){
					int cnt = 0;
					int xmin = numeric_limits<int>::max();
					int xmax = numeric_limits<int>::min();
					int ymin = numeric_limits<int>::max();
					int ymax = numeric_limits<int>::min();
					y_combinator([&](auto self, int i, int j)->void{
						++ cnt;
						ctmin(xmin, i);
						ctmax(xmax, i);
						ctmin(ymin, j);
						ctmax(ymax, j);
						vis[i][j] = true;
						for(auto [di, dj]: dr){
							int ni = i + di, nj = j + dj;
							if(0 <= min(ni, nj) && ni < n && nj < m && !vis[ni][nj] && a[ni][nj] & 1){
								self(ni, nj);
							}
						}
					})(i, j);
					if(cnt != (xmax - xmin + 1) * (ymax - ymin + 1)){
						cout << "No\n";
						return 0;
					}
				}
			}
		}
		cout << "Yes\n";
		return 0;
	};
	int __tc_cnt;
	cin >> __tc_cnt;
	for(auto __tc_num = 0; __tc_num < __tc_cnt; ++ __tc_num){
		__solve_tc(__tc_num);
	}
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////