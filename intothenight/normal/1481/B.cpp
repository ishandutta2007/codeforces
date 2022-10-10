#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](int __tc_num){
		int n, k;
		cin >> n >> k;
		vector<int> h(n);
		for(auto i = 0; i < n; ++ i){
			cin >> h[i];
		}
		if(k > 10000){
			cout << "-1\n";
			return 0;
		}
		for(auto rep = 0; rep < k; ++ rep){
			for(auto i = 0; i < n - 1; ++ i){
				if(h[i] < h[i + 1]){
					if(rep == k - 1){
						cout << i + 1 << "\n";
						return 0;
					}
					++ h[i];
					goto NEXT;
				}
			}
			cout << "-1\n";
			return 0;
			NEXT:;
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