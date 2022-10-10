#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](int __tc_num){
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		for(auto i = 0; i < n; ++ i){
			cin >> a[i];
		}
		for(auto rep = 0; rep < k; ++ rep){
			for(auto i = 0; i < n - 1; ++ i){
				if(a[i]){
					-- a[i], ++ a.back();
					goto NEXT;
				}
			}
			break;
			NEXT:;
		}
		for(auto x: a){
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