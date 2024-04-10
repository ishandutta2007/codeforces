#include "bits/stdc++.h"
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	auto __solve_tc = [&](){
		int n;
		string a, b;
		cin >> n >> a >> b;
		vector<int> res;
		for(auto i = n - 1; i >= 0; -- i){
			if(a[i] != b[i]){
				if(a[0] != a[i]){
					res.push_back(0);
					a[0] = (a[0] == '0') + '0';
				}
				res.push_back(i);
				for(auto j = 0; j <= i; ++ j){
					a[j] = (a[j] == '0') + '0';
				}
				reverse(a.begin(), a.begin() + i + 1);
			}
		}
		cout << int(res.size()) << " ";
		for(auto x: res){
			cout << x + 1 << " ";
		}
		cout << "\n";
		return 0;
	};
	int __tc_cnt;
	cin >> __tc_cnt;
	for(auto __tc_it = 0; __tc_it < __tc_cnt; ++ __tc_it){
		__solve_tc();
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