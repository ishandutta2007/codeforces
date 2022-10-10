#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](int __tc_num){
		long long p, q, b;
		cin >> p >> q >> b;
		q /= gcd(p, q);
		while(true){
			long long g = gcd(q, b);
			if(g == 1){
				break;
			}
			while(q % g == 0){
				q /= g;
			}
		}
		q == 1 ? cout << "Finite\n" : cout << "Infinite\n";
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