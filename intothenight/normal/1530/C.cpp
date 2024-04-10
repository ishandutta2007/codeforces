#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](auto __tc_num)->int{
		int n;
		cin >> n;
		vector<int> a(n), b(n);
		for(auto i = 0; i < n; ++ i){
			cin >> a[i];
		}
		for(auto i = 0; i < n; ++ i){
			cin >> b[i];
		}
		sort(a.begin(), a.end()), sort(b.begin(), b.end());
		vector<int> asuff(n + 1), bsuff(n + 1);
		for(auto i = n - 1; i >= 0; -- i){
			asuff[i] = asuff[i + 1] + a[i];
			bsuff[i] = bsuff[i + 1] + b[i];
		}
		for(auto len = 0; ; ++ len){
			if(asuff[min(n + len >> 2, n)] + 100 * (len - max((n + len >> 2) - n, 0)) >= bsuff[max(0, (n + len >> 2) - len)]){
				cout << len << "\n";
				return 0;
			}
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