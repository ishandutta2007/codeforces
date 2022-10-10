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
	int n;
	cin >> n;
	vector<vector<int>> a(n, vector<int>(n));
	for(auto i = 0; i < n; ++ i){
		for(auto j = 0; j < n; ++ j){
			cin >> a[i][j];
		}
	}
	const int inf = numeric_limits<int>::max() / 2;
	vector<vector<int>> dist(n, vector<int>(n, inf));
	for(auto u = 0; u < n; ++ u){
		dist[u][u] = 0;
	}
	vector<int> alive(n, false);
	vector<int> q(n);
	for(auto &u: q){
		cin >> u, -- u;
	}
	vector<long long> res;
	for(auto u: q | ranges::views::reverse){
		for(auto v = 0; v < n; ++ v){
			if(alive[v]){
				for(auto w = 0; w < n; ++ w){
					if(alive[w]){
						ctmin(dist[u][w], a[u][v] + dist[v][w]);
						ctmin(dist[w][u], a[v][u] + dist[w][v]);
					}
				}
			}
		}
		for(auto v = 0; v < n; ++ v){
			if(alive[v]){
				for(auto w = v + 1; w < n; ++ w){
					if(alive[w]){
						ctmin(dist[v][w], dist[v][u] + dist[u][w]);
						ctmin(dist[w][v], dist[w][u] + dist[u][v]);
					}
				}
			}
		}
		res.emplace_back();
		alive[u] = true;
		for(auto u = 0; u < n; ++ u){
			if(alive[u]){
				for(auto v = 0; v < n; ++ v){
					if(alive[v]){
						res.back() += dist[u][v];
					}
				}
			}
		}
	}
	ranges::copy(res | ranges::views::reverse, ostream_iterator<long long>(cout, " "));
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