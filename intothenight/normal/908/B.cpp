#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, m;
	cin >> n >> m;
	vector<string> a(n);
	array<int, 2> s{}, e{};
	for(auto i = 0; i < n; ++ i){
		cin >> a[i];
		for(auto j = 0; j < m; ++ j){
			if(a[i][j] == 'S'){
				s = {i, j};
			}
			if(a[i][j] == 'E'){
				e = {i, j};
			}
		}
	}
	string ins;
	cin >> ins;
	vector<int> mapping{0, 1, 2, 3};
	static const vector<pair<int, int>> dr{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
	int res = 0;
	do{
		int x = s[0], y = s[1];
		for(auto d: ins){
			auto [dx, dy] = dr[mapping[d - '0']];
			x += dx, y += dy;
			if(x < 0 || n <= x || y < 0 || m <= y || a[x][y] == '#'){
				break;
			}
			if(x == e[0] && y == e[1]){
				goto OK;
			}
		}
		continue;
		OK:;
		++ res;
	}while(next_permutation(mapping.begin(), mapping.end()));
	cout << res << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////