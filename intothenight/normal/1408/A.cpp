#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](int __tc_num){
		int n;
		cin >> n;
		vector<int> a(n), b(n), c(n);
		for(auto i = 0; i < n; ++ i){
			cin >> a[i];
		}
		for(auto i = 0; i < n; ++ i){
			cin >> b[i];
		}
		for(auto i = 0; i < n; ++ i){
			cin >> c[i];
		}
		vector<int> res(n);
		res[0] = a[0];
		for(auto i = 1; i < n; ++ i){
			if(a[i] == res[i - 1]){
				res[i] = b[i];
			}
			else{
				res[i] = a[i];
			}
		}
		if(res[0] == res[n - 1]){
			res[n - 1] = c[n - 1];
			if(res[n - 1] == res[0] || res[n - 1] == res[n - 2]){
				res[n - 1] = a[n - 1] ^ b[n - 1] ^ c[n - 1] ^ res[0] ^ res[n - 2];
			}
		}
		for(auto x: res){
			cout << x << " ";
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