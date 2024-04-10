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
	static const vector<pair<int, int>> dr{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
	array<int, 2> start, end;
	vector<string> a(n);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i];
		for(auto j = 0; j < m; ++ j){
			if(a[i][j] == 'S'){
				start = {i, j};
			}
			else if(a[i][j] == 'E'){
				end = {i, j};
			}
		}
	}
	vector<vector<int>> dist(n, vector<int>(m, -1));
	deque<array<int, 2>> dq{{end[0], end[1]}};
	dist[end[0]][end[1]] = 0;
	while(!dq.empty()){
		auto [i, j] = dq.front();
		dq.pop_front();
		for(auto [di, dj]: dr){
			int ni = i + di, nj = j + dj;
			if(0 <= min(ni, nj) && ni < n && nj < m && a[ni][nj] != 'T' && !~dist[ni][nj]){
				dist[ni][nj] = dist[i][j] + 1;
				dq.push_back({ni, nj});
			}
		}
	}
	int obj = dist[start[0]][start[1]], res = 0;
	for(auto i = 0; i < n; ++ i){
		for(auto j = 0; j < m; ++ j){
			if(isdigit(a[i][j]) && ~dist[i][j] && obj >= dist[i][j]){
				res += a[i][j] - '0';
			}
		}
	}
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