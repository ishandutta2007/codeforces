#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](auto __tc_num)->int{
		int n;
		cin >> n;
		vector<int> a(n);
		for(auto i = 0; i < n; ++ i){
			cin >> a[i];
		}
		int g = 0;
		for(auto bit = 0; bit < 30; ++ bit){
			int cnt = 0;
			for(auto i = 0; i < n; ++ i){
				cnt += a[i] >> bit & 1;
			}
			g = gcd(cnt, g);
		}
		if(g == 0){
			for(auto x = 1; x <= n; ++ x){
				cout << x << " ";
			}
			cout << "\n";
		}
		else{
			for(auto x = 1; x <= n; ++ x){
				if(g % x == 0){
					cout << x << " ";
				}
			}
			cout << "\n";
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