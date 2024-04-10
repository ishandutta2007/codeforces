#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(n, vector<int>(m));
	for(auto i = 0; i < n; ++ i){
		for(auto j = 0; j < m; ++ j){
			int x;
			cin >> x, -- x;
			a[i][j] = x;
		}
	}
	vector<vector<int>> state(n, vector<int>(m));
	int cnt = 0;
	static const vector<pair<int, int>> dr{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
	auto update = [&](int i, int j, int x)->void{
		a[i][j] = x;
		for(auto ti = -1; ti <= 1; ++ ti){
			for(auto tj = -1; tj <= 1; ++ tj){
				int ci = i + ti, cj = j + tj;
				if(abs(ti) + abs(tj) >= 2 || min(ci, cj) < 0 || ci >= n || cj >= m){
					continue;
				}
				cnt -= state[ci][cj];
				state[ci][cj] = false;
				for(auto [di, dj]: dr){
					int ni = ci + di, nj = cj + dj;
					if(0 <= min(ni, nj) && ni < n && nj < m && a[ni][nj] < a[ci][cj]){
						state[ci][cj] = true;
						break;
					}
				}
				cnt += state[ci][cj];
			}
		}
	};
	for(auto i = 0; i < n; ++ i){
		for(auto j = 0; j < m; ++ j){
			update(i, j, a[i][j]);
		}
	}
	if(cnt == n * m - 1){
		cout << "0\n";
		return 0;
	}
	vector<array<int, 2>> bad;
	for(auto i = 0; i < n; ++ i){
		for(auto j = 0; j < m; ++ j){
			if(a[i][j] && !state[i][j]){
				for(auto di = -1; di <= 1; ++ di){
					for(auto dj = -1; dj <= 1; ++ dj){
						if(abs(di) + abs(dj) >= 2){
							continue;
						}
						int ni = i + di, nj = j + dj;
						if(0 <= min(ni, nj) && ni < n && nj < m){
							bad.push_back({ni, nj});
						}
					}
				}
				goto DONE;
			}
		}
	}
	DONE:;
	vector<array<int, 2>> res;
	for(auto [i1, j1]: bad){
		for(auto i2 = 0; i2 < n; ++ i2){
			for(auto j2 = 0; j2 < m; ++ j2){
				if(i1 == i2 && j1 == j2){
					continue;
				}
				int x = a[i1][j1], y = a[i2][j2];
				update(i1, j1, y);
				update(i2, j2, x);
				if(cnt == n * m - 1){
					res.push_back({min(x, y), max(x, y)});
				}
				update(i1, j1, x);
				update(i2, j2, y);
			}
		}
	}
	ranges::sort(res);
	res.erase(unique(res.begin(), res.end()), res.end());
	res.empty() ? cout << "2\n" : cout << "1 " << (int)res.size() << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////