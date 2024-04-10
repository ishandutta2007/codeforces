#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](int __tc_num){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> a(n);
		vector<vector<int>> id(m);
		for(auto d = 0; d < m; ++ d){
			int k;
			cin >> k;
			for(auto i = 0; i < k; ++ i){
				int ind;
				cin >> ind, -- ind;
				a[ind].push_back(d);
				id[d].push_back(ind);
			}
		}
		vector<int> res(m, -1);
		int p = 0;
		for(auto i = 1; i < n; ++ i){
			if((int)a[p].size() < (int)a[i].size()){
				p = i;
			}
		}
		sort(a[p].begin(), a[p].end(), [&](int d, int e){ return (int)id[d].size() < (int)id[e].size(); });
		if((int)a[p].size() > (m + 1) / 2 && (int)id[a[p][(m + 1) / 2]].size() == 1){
			cout << "NO\n";
			return 0;
		}
		for(auto t = 0; t < min((int)a[p].size(), (m + 1) / 2); ++ t){
			res[a[p][t]] = p;
		}
		for(auto d = 0; d < m; ++ d){
			if(!~res[d]){
				if(id[d][0] == p){
					res[d] = id[d][1];
				}
				else{
					res[d] = id[d][0];
				}
			}
		}
		cout << "YES\n";
		for(auto x: res){
			cout << x + 1 << " ";
		}
		cout << "\n";
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