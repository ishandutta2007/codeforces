#include "bits/stdc++.h"
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	auto __solve_tc = [&](){
		int l, r;
		long long m;
		cin >> l >> r >> m;
		for(auto a = l; a <= r; ++ a){
			long long x = m / a * a; // x = m - (b - c)
			if(m - x <= r - l && x){
				cout << a << " " << r << " " << r - (m - x) << "\n";
				return 0;
			}
			x += a;
			if(x - m <= r - l){
				cout << a << " " << l << " " << l - (m - x) << "\n";
				return 0;
			}
		}
		return 0;
	};
	int __tc_cnt;
	cin >> __tc_cnt;
	for(auto __tc_it = 0; __tc_it < __tc_cnt; ++ __tc_it){
		__solve_tc();
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