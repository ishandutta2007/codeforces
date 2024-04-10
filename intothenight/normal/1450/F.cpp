#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](int __tc_num){
		int n;
		cin >> n;
		vector<int> a(n), cnt(n);
		for(auto i = 0; i < n; ++ i){
			cin >> a[i], -- a[i];
			++ cnt[a[i]];
		}
		if(2 * *max_element(cnt.begin(), cnt.end()) <= n + 1){
			fill(cnt.begin(), cnt.end(), 0);
			++ cnt[a.front()], ++ cnt[a.back()];
			int k = 1;
			for(auto i = 1; i < n; ++ i){
				if(a[i - 1] == a[i]){
					++ cnt[a[i - 1]], ++ cnt[a[i]];
					++ k;
				}
			}
			cout << max(k - 1, *max_element(cnt.begin(), cnt.end()) - 2) << "\n";
		}
		else{
			cout << "-1\n";
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