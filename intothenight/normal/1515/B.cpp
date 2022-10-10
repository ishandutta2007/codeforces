#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](int __tc_num){
		int n;
		cin >> n;
		if(n & 1){
			cout << "NO\n";
			return 0;
		}
		int sq = sqrt(n - 1);
		while((sq + 1) * (sq + 1) <= n){
			++ sq;
		}
		if(n == sq * sq){
			cout << "YES\n";
			return 0;
		}
		sq = sqrt(2 * n - 1);
		while((sq + 1) * (sq + 1) <= 2 * n){
			++ sq;
		}
		if(2 * n == sq * sq){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";
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