#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n, m, a, b, x, y, z;
	cin >> n >> m >> a >> b;
	vector<int> g(n * m);
	cin >> g[0] >> x >> y >> z;
	for(auto i = 1; i < n * m; ++ i){
		g[i] = (1LL * g[i - 1] * x + y) % z;
	}
	vector<vector<int>> h(n, vector<int>(m - b + 1));
	deque<array<int, 2>> q;
	auto insert = [&](int x, int i){
		while(!q.empty() && q.back()[0] >= x){
			q.pop_back();
		}
		q.push_back({x, i});
	};
	for(auto i = 0; i < n; ++ i){
		q.clear();
		for(auto j = 0; j < b - 1; ++ j){
			insert(g[i * m + j], j);
		}
		for(auto j = b - 1; j < m; ++ j){
			insert(g[i * m + j], j);
			while(j - q.front()[1] >= b){
				q.pop_front();
			}
			h[i][j - (b - 1)] = q.front()[0];
		}
	}
	long long res = 0;
	for(auto j = 0; j < m - b + 1; ++ j){
		q.clear();
		for(auto i = 0; i < a - 1; ++ i){
			insert(h[i][j], i);
		}
		for(auto i = a - 1; i < n; ++ i){
			insert(h[i][j], i);
			while(i - q.front()[1] >= a){
				q.pop_front();
			}
			res += q.front()[0];
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