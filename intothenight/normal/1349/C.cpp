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
	int n, m, qq;
	cin >> n >> m >> qq;
	vector<string> a(n);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i];
	}
	static const vector<pair<int, int>> dr{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
	vector<vector<int>> dist(n, vector<int>(m, -1));
	auto inrange = [&](int x, int y){
		return 0 <= x && x < n && 0 <= y && y < m;
	};
	bool found = false;
	for(auto x = 0; x < n; ++ x){
		for(auto y = 0; y < m; ++ y){
			if(!~dist[x][y]){
				for(auto &[dx, dy]: dr){
					int nx = x + dx, ny = y + dy;
					if(inrange(nx, ny) && a[x][y] == a[nx][ny]){
						function<void(int, int)> dfs = [&](int x, int y){
							dist[x][y] = 0;
							for(auto &[dx, dy]: dr){
								int nx = x + dx, ny = y + dy;
								if(inrange(nx, ny) && !~dist[nx][ny] && a[nx][ny] == a[x][y]){
									dfs(nx, ny);
								}
							}
						};
						dfs(x, y);
						found = true;
						break;
					}
				}
			}
		}
	}
	queue<array<int, 2>> q;
	for(auto x = 0; x < n; ++ x){
		for(auto y = 0; y < m; ++ y){
			if(!dist[x][y]){
				q.push({x, y});
			}
		}
	}
	while(!q.empty()){
		auto [x, y] = q.front();
		q.pop();
		for(auto &[dx, dy]: dr){
			int nx = x + dx, ny = y + dy;
			if(inrange(nx, ny) && !~dist[nx][ny]){
				dist[nx][ny] = dist[x][y] + 1;
				q.push({nx, ny});
			}
		}
	}
	while(qq --){
		int x, y;
		long long p;
		cin >> x >> y >> p, -- x, -- y;
		if(!found || p < dist[x][y]){
			cout << a[x][y] << "\n";
		}
		else{
			p - dist[x][y] & 1 ? cout << char(!(a[x][y] - '0') + '0') << "\n" : cout << a[x][y] << "\n";
		}
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