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
		for(auto j = 0; j < m; ++ j){
			for(auto i = n - 1; i >= 0; -- i){
				if(a[i][j] == '*'){
					a[i][j] = '.';
					int k = i + 1;
					while(k < n && a[k][j] == '.'){
						++ k;
					}
					a[k - 1][j] = '*';
				}
			}
		}
		ranges::copy(a, ostream_iterator<string>(cout, "\n"));
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