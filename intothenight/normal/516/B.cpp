#include <bits/stdc++.h>
using namespace std;



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
	auto inrange = [&](int i, int j){
		return 0 <= i && i < n && 0 <= j && j < m;
	};
	auto deg = [&](int i, int j){
		int d = 0;
		for(auto [di, dj]: dr){
			int ni = i + di, nj = j + dj;
			if(inrange(ni, nj) && a[ni][nj] == '.'){
				++ d;
			}
		}
		return d;
	};
	for(auto i = 0; i < n; ++ i){
		for(auto j = 0; j < m; ++ j){
			if(a[i][j] == '.'){
				function<void(int, int)> dfs = [&](int i, int j){
					if(deg(i, j) == 0){
						cout << "Not unique\n";
						exit(0);
					}
					if(deg(i, j) >= 2){
						return;
					}
					for(auto t = 0; t < 4; ++ t){
						auto [di, dj] = dr[t];
						int ni = i + di, nj = j + dj;
						if(inrange(ni, nj) && a[ni][nj] == '.'){
							if(t == 0){
								a[i][j] = '^', a[ni][nj] = 'v';
							}
							else if(t == 1){
								a[i][j] = '<', a[ni][nj] = '>';
							}
							else if(t == 2){
								a[i][j] = 'v', a[ni][nj] = '^';
							}
							else{
								a[i][j] = '>', a[ni][nj] = '<';
							}
							for(auto [ddi, ddj]: dr){
								int nni = ni + ddi, nnj = nj + ddj;
								if(inrange(nni, nnj) && a[nni][nnj] == '.'){
									dfs(nni, nnj);
								}
							}
							break;
						}
					}
				};
				dfs(i, j);
			}
		}
	}
	for(auto i = 0; i < n; ++ i){
		for(auto j = 0; j < m; ++ j){
			if(a[i][j] == '.'){
				goto FAIL;
			}
		}
	}
	for(auto s: a){
		cout << s << "\n";
	}
	return 0;
	FAIL:;
	cout << "Not unique\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////