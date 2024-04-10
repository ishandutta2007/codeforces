#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, m, qn;
	cin >> n >> m >> qn;
	vector<long long> light_val(n);
	for(auto &x: light_val){
		cin >> x;
	}
	vector<vector<int>> g(m);
	vector<int> heavy, heavy_id(m, -1);
	vector<long long> heavy_sum(m);
	vector<vector<int>> belong(n);
	const int th = sqrt(n);
	for(auto i = 0; i < m; ++ i){
		int k;
		cin >> k;
		g[i].resize(k);
		for(auto &u: g[i]){
			cin >> u, -- u;
			if(k >= th){
				heavy_sum[i] += light_val[u];
			}
			belong[u].push_back(i);
		}
		sort(g[i].begin(), g[i].end());
		if(k >= th){
			heavy_id[i] = (int)heavy.size();
			heavy.push_back(i);
		}
	}
	int k = (int)heavy.size();
	vector<vector<int>> inter(k, vector<int>(m));
	for(auto u = 0; u < n; ++ u){
		int p = partition(belong[u].begin(), belong[u].end(), [&](int i){ return ~heavy_id[i]; }) - belong[u].begin();
		for(auto l = 0; l < p; ++ l){
			for(auto r = 0; r < (int)belong[u].size(); ++ r){
				if(l != r){
					++ inter[heavy_id[belong[u][l]]][belong[u][r]];
				}
			}
		}
	}
	vector<long long> heavy_update(m);
	for(auto qi = 0; qi < qn; ++ qi){
		char type;
		cin >> type;
		if(type == '?'){
			int i;
			cin >> i, -- i;
			if((int)g[i].size() < th){
				long long res = 0;
				for(auto u: g[i]){
					res += light_val[u];
				}
				for(auto t = 0; t < k; ++ t){
					res += inter[t][i] * heavy_update[heavy[t]];
				}
				cout << res << "\n";
			}
			else{
				cout << heavy_sum[i] << "\n";
			}
		}
		else{
			int i, x;
			cin >> i >> x, -- i;
			if((int)g[i].size() < th){
				for(auto u: g[i]){
					light_val[u] += x;
				}
				for(auto t = 0; t < k; ++ t){
					heavy_sum[heavy[t]] += 1LL * x * inter[t][i];
				}
			}
			else{
				heavy_sum[i] += 1LL * x * (int)g[i].size();
				heavy_update[i] += x;
				for(auto t = 0; t < k; ++ t){
					heavy_sum[heavy[t]] += 1LL * x * inter[t][i];
				}
			}
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