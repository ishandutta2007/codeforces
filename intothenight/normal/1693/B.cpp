#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](auto __tc_num)->int{
		int n;
		cin >> n;
		vector<int> p(n, -1);
		vector<vector<int>> adj(n);
		for(auto u = 1; u < n; ++ u){
			cin >> p[u], -- p[u];
			adj[p[u]].push_back(u);
		}
		vector<array<int, 2>> a(n);
		for(auto &x: a | ranges::views::join){
			cin >> x;
		}
		int res = 0;
		vector<int> val(n);
		for(auto u = n - 1; u >= 0; -- u){
			for(auto v: adj[u]){
				val[u] = min(val[u] + val[v], a[u][1]);
			}
			if(val[u] < a[u][0]){
				val[u] = a[u][1];
				++ res;
			}
		}
		cout << res << "\n";
		return 0;
	};
	int __tc_cnt;
	cin >> __tc_cnt;
	for(auto __tc_num = 0; __tc_num < __tc_cnt; ++ __tc_num){
		__solve_tc(__tc_num);
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