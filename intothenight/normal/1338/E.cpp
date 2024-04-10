#include "bits/stdc++.h"
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	using bs = bitset<8000>;
	vector<bs> adj(n);
	for(auto i = 0; i < n; ++ i){
		string s;
		cin >> s;
		for(auto j = 0; j < n >> 2; ++ j){
			int x = s[j] <= '9' ? s[j] - '0' : s[j] - 'A' + 10;
			for(auto k = 0; k < 4; ++ k){
				if(x & 1 << 3 - k){
					adj[i].set((j << 2) + k);
				}
			}
		}
	}
	vector<int> indeg(n);
	for(auto u = 0; u < n; ++ u){
		for(auto v = 0; v < n; ++ v){
			if(adj[u][v]){
				++ indeg[v];
			}
		}
	}
	bs is_active;
	is_active.set();
	int tail_cnt = 0;
	while(1){
		int u = -1;
		for(auto v = 0; v < n; ++ v){
			if(is_active[v] && !indeg[v]){
				u = v;
				break;
			}
		}
		if(!~u){
			break;
		}
		++ tail_cnt;
		is_active.reset(u);
		for(auto v = 0; v < n; ++ v){
			if(is_active[v] && adj[u][v]){
				-- indeg[v];
			}
		}
	}
	long long res = 1LL * ((n - tail_cnt) * tail_cnt + tail_cnt * (tail_cnt - 1) / 2) * (1 + 614 * n);
	if(n ^ tail_cnt){
		int s = is_active._Find_first();
		vector<int> numb(n);
		int cnt = 0;
		for(auto u = s; !cnt || u ^ s; ){
			numb[u] = cnt ++;
			int nu = -1;
			for(auto v = 0; v < n; ++ v){
				if(is_active[v] && adj[v][u] && (!~nu || adj[nu][v])){
					nu = v;
				}
			}
			u = nu;
		}
		for(auto i = 0; i < n; ++ i){
			if(is_active[i]){
				for(auto j = i + 1; j < n; ++ j){
					if(is_active[j]){
						auto [u, v] = pair{i, j};
						if(!adj[u][v]){
							swap(u, v);
						}
						++ res;
						int x = numb[u] - numb[v] + cnt;
						if(x >= cnt) x -= cnt;
						if(x == indeg[v] - indeg[u]){
							res += 3;
						}
						else{
							res += 2;
						}
					}
				}
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