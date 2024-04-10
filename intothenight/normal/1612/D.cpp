#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](auto __tc_num)->int{
		long long a, b, x;
		cin >> a >> b >> x;
		while(a != x && b != x){
			if(a < b){
				swap(a, b);
			}
			if(b < a - b){
				b = a - b;
			}
			if(x > a || a == b){
				cout << "NO\n";
				return 0;
			}
			auto dif = a - b;
			if((a - x) % dif == 0){
				cout << "YES\n";
				return 0;
			}
			a %= dif;
			b = dif;
			if(a < b){
				a += dif;
			}
		}
		cout << "YES\n";
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
24 28 20
*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////