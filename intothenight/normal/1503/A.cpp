#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](int __tc_num){
		int n;
		string s;
		cin >> n >> s;
		int zero = count(s.begin(), s.end(), '0'), one = n - zero;
		if(zero & 1 || ~s.front() & 1 | ~s.back() & 1){
			cout << "NO\n";
			return 0;
		}
		string a(n, '?'), b(n, '?');
		int it_zero = 0, it_one = 0;
		for(auto i = 0; i < n; ++ i){
			if(s[i] & 1){
				if(it_one < one / 2){
					a[i] = b[i] = '(';
				}
				else{
					a[i] = b[i] = ')';
				}
				++ it_one;
			}
			else{
				if(it_zero & 1){
					a[i] = '(', b[i] = ')';
				}
				else{
					a[i] = ')', b[i] = '(';
				}
				++ it_zero;
			}
		}
		cout << "YES\n" << a << "\n" << b << "\n";
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