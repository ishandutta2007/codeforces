#include <bits/stdc++.h>
using namespace std;
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, m;
	cin >> n >> m;
	vector<array<int, 2>> a(n);
	for(auto &[x, y]: a){
		cin >> x >> y;
	}
	const int block = sqrt(m);
	vector<vector<int>> cnt(block, vector<int>(block)), range(n);
	vector<int> small(m), last(n);
	for(auto i = 0; i < m; ++ i){
		int op, k;
		cin >> op >> k, -- k;
		auto [x, y] = a[k];
		const int len = x + y;
		if(len < block){
			if(op == 1){
				for(auto j = x; j < len; ++ j){
					++ cnt[len][(i + j) % len];
				}
			}
			else{
				for(auto j = x; j < len; ++ j){
					-- cnt[len][(last[k] + j) % len];
				}
			}
			last[k] = i;
		}
		else{
			range[k].push_back(i);
		}
		for(auto len = 1; len < block; ++ len){
			small[i] += cnt[len][i % len];
		}
	}
	vector<int> large(m + 1);
	for(auto i = 0; i < n; ++ i){
		if((int)range[i].size() & 1){
			range[i].push_back(m);
		}
		auto [x, y] = a[i];
		int len = x + y;
		for(auto t = 0; t < (int)range[i].size(); t += 2){
			int L = range[i][t], R = range[i][t + 1];
			for(auto l = L + x, r = L + len; l < R; l += len, r += len){
				++ large[l];
				-- large[min(r, R)];
			}
		}
	}
	for(auto i = 0; i < m; ++ i){
		large[i + 1] += large[i];
		cout << small[i] + large[i] << "\n";
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