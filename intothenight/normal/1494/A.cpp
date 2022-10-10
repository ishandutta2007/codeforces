#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](int __tc_num){
		string s;
		cin >> s;
		int n = (int)s.size();
		for(auto x = 0; x < 2; ++ x){
			for(auto y = 0; y < 2; ++ y){
				for(auto z = 0; z < 2; ++ z){
					int balance = 0;
					for(auto c: s){
						if(c == 'A'){
							balance += x ? 1 : -1;
						}
						else if(c == 'B'){
							balance += y ? 1 : -1;
						}
						else{
							balance += z ? 1 : -1;
						}
						if(balance < 0){
							goto NEXT;
						}
					}
					if(!balance){
						cout << "YES\n";
						return 0;
					}
					NEXT:;
				}
			}
		}
		cout << "NO\n";
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