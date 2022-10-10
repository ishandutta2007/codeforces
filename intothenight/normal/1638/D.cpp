#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif

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
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(n, vector<int>(m));
	for(auto i = 0; i < n; ++ i){
		for(auto j = 0; j < m; ++ j){
			cin >> a[i][j];
		}
	}
	vector<array<int, 3>> res;
	for(auto i = 0; i < n - 1; ++ i){
		for(auto j = 0; j < m - 1; ++ j){
			y_combinator([&](auto self, int i, int j)->void{
				int c = -1;
				for(auto di = 0; di < 2; ++ di){
					for(auto dj = 0; dj < 2; ++ dj){
						if(~a[i + di][j + dj]){
							c = a[i + di][j + dj];
						}
					}
				}
				if(!~c){
					return;
				}
				for(auto di = 0; di < 2; ++ di){
					for(auto dj = 0; dj < 2; ++ dj){
						if(~a[i + di][j + dj] && c != a[i + di][j + dj]){
							return;
						}
					}
				}
				res.push_back({i + 1, j + 1, c});
				for(auto di = 0; di < 2; ++ di){
					for(auto dj = 0; dj < 2; ++ dj){
						a[i + di][j + dj] = -1;
					}
				}
				for(auto di = -1; di <= 1; ++ di){
					for(auto dj = -1; dj <= 1; ++ dj){
						if(auto ni = i + di, nj = j + dj; 0 <= min(ni, nj) && ni < n - 1 && nj < m - 1){
							self(ni, nj);
						}
					}
				}
			})(i, j);
		}
	}
	for(auto i = 0; i < n; ++ i){
		for(auto j = 0; j < m; ++ j){
			if(~a[i][j]){
				cout << "-1\n";
				return 0;
			}
		}
	}
	cout << (int)res.size() << "\n";
	ranges::copy(res | ranges::views::reverse | ranges::views::join, ostream_iterator<int>(cout, " "));
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