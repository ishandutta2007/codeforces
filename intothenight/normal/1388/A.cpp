#include "bits/stdc++.h"
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	auto __solve_tc = [&](int __tc_num){
		int n;
		cin >> n;
		if(n <= 30){
			cout << "NO\n";
		}
		else if(n == 36){
			cout << "YES\n6 10 15 5\n";
		}
		else if(n == 40){
			cout << "YES\n6 10 15 9\n";
		}
		else if(n == 44){
			cout << "YES\n6 10 15 13\n";
		}
		else{
			cout << "YES\n6 10 14 " << n - 30 << "\n";
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
2*3=6
2*5=10
2*7=14

3*5=15

<= 30 -> NO

36 = 6 10 15 5
*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////