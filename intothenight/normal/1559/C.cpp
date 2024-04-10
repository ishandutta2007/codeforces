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
		if(a[0]){
			cout << n + 1 << " ";
			for(auto x = 1; x <= n; ++ x){
				cout << x << " ";
			}
			cout << "\n";
		}
		else if(!a[n - 1]){
			for(auto x = 1; x <= n + 1; ++ x){
				cout << x << " ";
			}
			cout << "\n";
		}
		else{
			int p = n - 1;
			while(a[p]){
				-- p;
			}
			for(auto x = 1; x <= p + 1; ++ x){
				cout << x << " ";
			}
			cout << n + 1 << " ";
			for(auto x = p + 2; x <= n; ++ x){
				cout << x << " ";
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