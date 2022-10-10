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
		int n, m;
		cin >> n >> m;
		vector<string> a(n);
		copy_n(istream_iterator<string>(cin), n, a.begin());
		int x = n, y = m;
		for(auto i = 0; i < n; ++ i){
			for(auto j = 0; j < m; ++ j){
				if(a[i][j] == 'R'){
					x = min(x, i);
					y = min(y, j);
				}
			}
		}
		a[x][y] == 'R' ? cout << "YES\n" : cout << "NO\n";
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