#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, m, qn;
	cin >> n >> m >> qn;
	vector<int> cnt(1 << n), w(n);
	for(auto i = 0; i < n; ++ i){
		cin >> w[i];
	}
	auto read = [&](){
		string t;
		cin >> t;
		int mask = 0;
		for(auto i = 0; i < n; ++ i){
			if(t[i] & 1){
				mask |= 1 << i;
			}
		}
		return mask;
	};
	for(auto i = 0; i < m; ++ i){
		++ cnt[read()];
	}
	vector<int> val(1 << n);
	for(auto mask = 0; mask < 1 << n; ++ mask){
		for(auto i = 0; i < n; ++ i){
			if(~mask & 1 << i){
				val[mask] += w[i];
			}
		}
	}
	vector<vector<int>> res(1 << n, vector<int>(101));
	for(auto x = 0; x < 1 << n; ++ x){
		for(auto y = 0; y < 1 << n; ++ y){
			if(val[x ^ y] <= 100){
				res[x][val[x ^ y]] += cnt[y];
			}
		}
		for(auto k = 1; k <= 100; ++ k){
			res[x][k] += res[x][k - 1];
		}
	}
	for(auto qi = 0; qi < qn; ++ qi){
		int mask = read(), k;
		cin >> k;
		cout << res[mask][k] << "\n";
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