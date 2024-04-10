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
		int n;
		cin >> n;
		vector<int> a(n);
		copy_n(istream_iterator<int>(cin), n, a.begin());
		vector<int> res(n);
		for(auto l = 0; l < n; ){
			int r = l;
			while(r < n && a[l] == a[r]){
				++ r;
			}
			if(r - l == 1){
				cout << "-1\n";
				return 0;
			}
			for(auto i = l; i < r; ++ i){
				if(i == l){
					res[i] = r - 1;
				}
				else{
					res[i] = i - 1;
				}
			}
			l = r;
		}
		for(auto i: res){
			cout << i + 1 << " ";
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