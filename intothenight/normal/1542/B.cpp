#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](auto __tc_num)->int{
		int n, a, b;
		cin >> n >> a >> b;
		if(a == 1){
			(n - 1) % b == 0 ? cout << "Yes\n" : cout << "No\n";
		}
		else{
			int x = 1;
			while(x <= n){
				if((n - x) % b == 0){
					cout << "Yes\n";
					return 0;
				}
				if(__builtin_mul_overflow_p(x, a, 0)){
					break;
				}
				x *= a;
			}
			cout << "No\n";
		}
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