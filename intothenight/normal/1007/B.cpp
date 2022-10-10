#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	array<vector<array<int, 2>>, 8> p;
	for(auto x = 1; x < 8; ++ x){
		for(auto mask = 1; mask < 8; ++ mask){
			for(auto mask2 = 1; mask2 < 8; ++ mask2){
				if(
					mask & 1 && x & 2 && mask2 & 4 ||
					mask & 1 && mask2 & 2 && x & 4 ||
					x & 1 && mask & 2 && mask2 & 4 ||
					x & 1 && mask2 & 2 && mask & 4 ||
					mask2 & 1 && x & 2 && mask & 4 ||
					mask2 & 1 && mask & 2 && x & 4
				){
					p[x].push_back({mask, mask2});
				}
			}
		}
	}
	const int mx = 1e5;
	vector<vector<int>> div(mx + 1);
	for(auto x = 1; x <= mx; ++ x){
		for(auto y = x; y <= mx; y += x){
			div[y].push_back(x);
		}
	}
	auto __solve_tc = [&](auto __tc_num)->int{
		int a, b, c;
		cin >> a >> b >> c;
		array<int, 8> l{}, r{};
		vector<int> d;
		d.insert(d.end(), div[a].begin(), div[a].end());
		d.insert(d.end(), div[b].begin(), div[b].end());
		d.insert(d.end(), div[c].begin(), div[c].end());
		sort(d.begin(), d.end());
		d.erase(unique(d.begin(), d.end()), d.end());
		for(auto &x: d){
			++ r[x = (a % x == 0) | (b % x == 0) << 1 | (c % x == 0) << 2];
		}
		int res = 0;
		for(auto x: d){
			++ l[x];
			for(auto [m1, m2]: p[x]){
				res += l[m1] * r[m2];
			}
			-- r[x];
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
128 * 64
*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////