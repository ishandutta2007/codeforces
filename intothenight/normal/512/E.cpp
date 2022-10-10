#include <bits/stdc++.h>
using namespace std;
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	vector<vector<bool>> adjm(n, vector<bool>(n)), obj_adjm = adjm;
	for(auto u = 0; u < n; ++ u){
		adjm[u][(u + 1) % n] = adjm[(u + 1) % n][u] = true;
	}
	for(auto rep = 0; rep < n - 3; ++ rep){
		int u, v;
		cin >> u >> v, -- u, -- v;
		adjm[u][v] = adjm[v][u] = true;
	}
	for(auto rep = 0; rep < n - 3; ++ rep){
		int u, v;
		cin >> u >> v, -- u, -- v;
		obj_adjm[u][v] = obj_adjm[v][u] = true;
	}
	vector<array<int, 2>> res;
	auto flip = [&](int u, int v){
		assert(adjm[u][v]);
		res.push_back({u, v});
		int x = -1, y = -1;
		for(auto w = 0; w < n; ++ w){
			if(adjm[u][w] && adjm[v][w]){
				x = w;
				break;
			}
		}
		assert(~x);
		for(auto w = 0; w < n; ++ w){
			if(w != x && adjm[u][w] && adjm[v][w]){
				y = w;
				break;
			}
		}
		assert(~y);
		assert(!adjm[x][y]);
		adjm[u][v] = adjm[v][u] = !adjm[u][v];
		adjm[x][y] = adjm[y][x] = !adjm[x][y];
	};
	function<void(vector<int>)> solve = [&](vector<int> a){
		if((int)a.size() <= 3){
			return;
		}
		array<int, 3> best_split{numeric_limits<int>::max(), -1, -1};
		for(auto i = 0; i < (int)a.size(); ++ i){
			for(auto j = i + 1; j < (int)a.size(); ++ j){
				if(obj_adjm[a[i]][a[j]]){
					ctmin(best_split, array{abs((j - i) - ((int)a.size() - (j - i))), i, j});
				}
			}
		}
		auto [ignore, i, j] = best_split;
		for(auto k = i + 1; k < j; ++ k){
			for(auto l = i - 1; l >= 0; -- l){
				if(adjm[a[k]][a[l]]){
					flip(a[k], a[l]);
				}
			}
			for(auto l = (int)a.size() - 1; l > j; -- l){
				if(adjm[a[k]][a[l]]){
					flip(a[k], a[l]);
				}
			}
		}
		vector<int> left(a.begin() + i, a.begin() + j + 1);
		vector<int> right(a.begin() + j, a.end());
		right.insert(right.end(), a.begin(), a.begin() + i + 1);
		solve(left), solve(right);
	};
	vector<int> a(n);
	iota(a.begin(), a.end(), 0);
	solve(a);
	cout << (int)res.size() << "\n";
	for(auto [u, v]: res){
		cout << u + 1 << " " << v + 1 << "\n";
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