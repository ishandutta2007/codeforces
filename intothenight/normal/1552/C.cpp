#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](auto __tc_num)->int{
		int n, k;
		cin >> n >> k;
		vector<bool> flag(n << 1);
		vector<array<int, 2>> c(k);
		for(auto i = 0; i < k; ++ i){
			int x, y;
			cin >> x >> y, -- x, -- y;
			if(x > y){
				swap(x, y);
			}
			c[i] = {x, y};
			flag[x] = flag[y] = true;
		}
		vector<int> rem;
		for(auto x = 0; x < n << 1; ++ x){
			if(!flag[x]){
				rem.push_back(x);
			}
		}
		for(auto i = 0; i < (int)rem.size() / 2; ++ i){
			c.push_back({rem[i], rem[i + (int)rem.size() / 2]});
		}
		sort(c.begin(), c.end());
		assert((int)c.size() == n);
		int res = 0;
		for(auto i = 0; i < n; ++ i){
			for(auto j = i + 1; j < n; ++ j){
				if(c[j][0] < c[i][1] && c[i][1] < c[j][1]){
					++ res;
				}
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