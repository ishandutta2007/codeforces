#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](int __tc_num){
		int n, m;
		cin >> n >> m;
		vector<int> cnt(m);
		for(auto i = 0; i < n; ++ i){
			int x;
			cin >> x;
			++ cnt[x % m];
		}
		int res = 0;
		for(auto x = 0; x <= m / 2; ++ x){
			if(x * 2 == m){
				if(cnt[x]){
					++ res;
				}
			}
			else{
				if(cnt[x] || cnt[(m - x) % m]){
					int a = cnt[x], b = cnt[(m - x) % m];
					++ res;
					if(a > b){
						swap(a, b);
					}
					res += max(0, b - (a + 1));
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