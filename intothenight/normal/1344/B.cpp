#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
#include "ext/rope"
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
mt19937 rng(high_resolution_clock::now().time_since_epoch().count());
mt19937_64 rngll(high_resolution_clock::now().time_since_epoch().count());
#define lambdify(x) [&](auto &&...args){ return x(forward<decltype(args)>(args)...); }
template<typename T> T ctmax(T &x, const T &y){ return x = max(x, y); }
template<typename T> T ctmin(T &x, const T &y){ return x = min(x, y); }
template<typename T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	vector<string> a(n);
	for(auto &s: a){
		cin >> s;
	}
	auto kill = [](){
		cout << -1;
		exit(0);
	};
	bool erow = false, ecol = false;
	for(auto i = 0; i < n; ++ i){
		int l = 0, r = m - 1;
		while(l < m && a[i][l] == '.'){
			++ l;
		}
		while(r >= 0 && a[i][r] == '.'){
			-- r;
		}
		if(l > r){
			erow = true;
		}
		for(auto j = l; j <= r; ++ j){
			if(a[i][j] == '.'){
				kill();
			}
		}
	}
	for(auto j = 0; j < m; ++ j){
		int l = 0, r = n - 1;
		while(l < n && a[l][j] == '.'){
			++ l;
		}
		while(r >= 0 && a[r][j] == '.'){
			-- r;
		}
		if(l > r){
			ecol = true;
		}
		for(auto i = l; i <= r; ++ i){
			if(a[i][j] == '.'){
				kill();
			}
		}
	}
	if(erow ^ ecol){
		kill();
	}
	int res = 0;
	vector<vector<int>> visited(n, vector<int>(m));
	static const vector<pair<int, int>> dr{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
	function<void(int, int)> dfs = [&](int x, int y){
		visited[x][y] = true;
		for(auto &[dx, dy]: dr){
			int nx = x + dx, ny = y + dy;
			if(0 <= nx && nx < n && 0 <= ny && ny < m && a[nx][ny] == '#' && !visited[nx][ny]){
				dfs(nx, ny);
			}
		}
	};
	for(auto i = 0; i < n; ++ i){
		for(auto j = 0; j < m; ++ j){
			if(a[i][j] == '#' && !visited[i][j]){
				++ res;
				dfs(i, j);
			}
		}
	}
	cout << res;
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////