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
	int n, m;
	cin >> n >> m;
	vector<string> a(n);
	for(auto &s: a){
		cin >> s;
	}
	static const vector<pair<int, int>> dr{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
	auto get = [&](int i, int j, int t)->pair<int, int>{
		auto [di, dj] = dr[t];
		return {i + di, j + dj};
	};
	vector<vector<int>> deg(n, vector<int>(m));
	for(auto i = 0; i < n; ++ i){
		for(auto j = 0; j < m; ++ j){
			if(a[i][j] == 'X'){
				for(auto [di, dj]: dr){
					int ni = i + di, nj = j + dj;
					if(a[ni][nj] == '.'){
						++ deg[i][j];
					}
				}
				if(deg[i][j] & 1){
					cout << "NO\n";
					return 0;
				}
			}
		}
	}
	auto inrange = [&](int i, int j)->bool{
		return 0 <= min(i, j) && i < n && j < m;
	};
	vector<vector<int>> res(n, vector<int>(m, -1));
	for(auto i = 0; i < n; ++ i){
		for(auto j = 0; j < m; ++ j){
			if(a[i][j] == '.' && !~res[i][j]){
				res[i][j] = 1;
				y_combinator([&](auto self, int i, int j)->void{
					for(auto t = 0; t < 4; ++ t){
						auto [di, dj] = dr[t];
						int ni = i + di, nj = j + dj;
						if(inrange(ni, nj) && a[ni][nj] == 'X'){
							if(deg[ni][nj] == 2){
								int tt = 0;
								while(true){
									if(tt == (t ^ 2)){
										++ tt;
										continue;
									}
									auto [nni, nnj] = get(ni, nj, tt);
									if(a[nni][nnj] == '.'){
										break;
									}
									++ tt;
								}
								auto [nni, nnj] = get(ni, nj, tt);
								if(!~res[nni][nnj]){
									res[nni][nnj] = res[i][j] ^ 5;
									self(nni, nnj);
								}
							}
							else{
								for(auto tt = 0; tt < 4; ++ tt){
									if(tt != (t ^ 2)){
										auto [nni, nnj] = get(ni, nj, tt);
										if(!~res[nni][nnj]){
											res[nni][nnj] = t == tt ? res[i][j] : res[i][j] ^ 5;
											self(nni, nnj);
										}
									}
								}
							}
						}
					}
				})(i, j);
			}
		}
	}
	cout << "YES\n";
	for(auto i = 0; i < n; ++ i){
		for(auto j = 0; j < m; ++ j){
			if(a[i][j] == 'X'){
				res[i][j] = 0;
				for(auto [di, dj]: dr){
					int ni = i + di, nj = j + dj;
					if(a[ni][nj] == '.'){
						res[i][j] += res[ni][nj];
					}
				}
			}
			cout << res[i][j] << " ";
		}
		cout << "\n";
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