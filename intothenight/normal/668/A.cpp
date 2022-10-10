#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, m, qn;
	cin >> n >> m >> qn;
	vector<vector<int>> res(n, vector<int>(m, 1e9));
	vector<vector<array<int, 2>>> M(n, vector<array<int, 2>>(m));
	for(auto i = 0; i < n; ++ i){
		for(auto j = 0; j < m; ++ j){
			M[i][j] = {i, j};
		}
	}
	for(auto qi = 0; qi < qn; ++ qi){
		int type;
		cin >> type;
		if(type == 1){
			int r;
			cin >> r, -- r;
			rotate(M[r].begin(), M[r].begin() + 1, M[r].end());
		}
		else if(type == 2){
			int c;
			cin >> c, -- c;
			auto top = M[0][c];
			for(auto i = 0; i < n - 1; ++ i){
				M[i][c] = M[i + 1][c];
			}
			M[n - 1][c] = top;
		}
		else{
			int r, c, x;
			cin >> r >> c >> x, -- r, -- c;
			auto [i, j] = M[r][c];
			res[i][j] = x;
		}
	}
	for(auto i = 0; i < n; ++ i){
		for(auto j = 0; j < m; ++ j){
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