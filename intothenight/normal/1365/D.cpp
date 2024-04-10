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
template<typename T, typename U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<typename T, typename U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }
template<typename T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;



int SOLVE(){
	static const vector<pair<int, int>> dr{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
	int n, m;
	cin >> n >> m;
	vector<string> a(n);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i];
	}
	if(a[n - 1][m - 1] == 'B'){
		cout << "No\n";
		return 0;
	}
	for(auto i = 0; i < n; ++ i){
		for(auto j = 0; j < m; ++ j){
			if(i < n - 1){
				string s = {a[i][j], a[i + 1][j]};
				if(s == "GB" || s == "BG"){
					cout << "No\n";
					return 0;
				}
			}
			if(j < m - 1){
				string s = {a[i][j], a[i][j + 1]};
				if(s == "GB" || s == "BG"){
					cout << "No\n";
					return 0;
				}
			}
			if(a[i][j] == 'B'){
				for(auto &[dx, dy]: dr){
					int nx = i + dx, ny = j + dy;
					if(0 <= nx && nx < n && 0 <= ny && ny < m && a[nx][ny] == '.'){
						a[nx][ny] = '#';
					}
				}
			}
		}
	}
	vector<vector<int>> visited(n, vector<int>(m));
	function<void(int, int)> dfs = [&](int x, int y){
		visited[x][y] = true;
		for(auto &[dx, dy]: dr){
			int nx = x + dx, ny = y + dy;
			if(0 <= nx && nx < n && 0 <= ny && ny < m && !visited[nx][ny] && a[nx][ny] != '#'){
				dfs(nx, ny);
			}
		}
	};
	if(a[n - 1][m - 1] != '#') dfs(n - 1, m - 1);
	for(auto i = 0; i < n; ++ i){
		for(auto j = 0; j < m; ++ j){
			if(a[i][j] == 'G' && !visited[i][j]){
				cout << "No\n";
				return 0;
			}
		}
	}
	cout << "Yes\n";
	return 0;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int ttt;
	cin >> ttt;
	while(ttt --){
		SOLVE();
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