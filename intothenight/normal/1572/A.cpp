#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](auto __tc_num)->int{
		int n;
		cin >> n;
		vector<vector<int>> rev(n);
		vector<int> indeg(n);
		for(auto u = 0; u < n; ++ u){
			int m;
			cin >> m;
			indeg[u] = m;
			for(auto i = 0; i < m; ++ i){
				int v;
				cin >> v, -- v;
				rev[v].push_back(u);
			}
		}
		int res = 0;
		vector<int> done(n);
		set<int> q;
		for(auto u = 0; u < n; ++ u){
			if(!indeg[u]){
				q.insert(u);
			}
		}
		while(!q.empty()){
			++ res;
			int last = -1;
			while(true){
				auto it = q.upper_bound(last);
				if(it == q.end()){
					break;
				}
				int u = *it;
				q.erase(it);
				last = u;
				done[u] = true;
				for(auto v: rev[u]){
					assert(!done[v]);
					-- indeg[v];
					if(!indeg[v]){
						q.insert(v);
					}
				}
			}
		}
		if(accumulate(done.begin(), done.end(), 0) == n){
			cout << res << "\n";
		}
		else{
			cout << "-1\n";
		}
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