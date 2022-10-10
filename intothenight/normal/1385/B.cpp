#include "bits/stdc++.h"
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	auto __solve_tc = [&](){
		int n;
		cin >> n;
		vector<int> a(2 * n);
		for(auto i = 0; i < 2 * n; ++ i){
			cin >> a[i];
		}
		vector<int> ded(2 * n), res;
		for(auto i = 0; i < 2 * n; ++ i){
			if(!ded[i]){
				res.push_back(a[i]);
				for(auto j = i + 1; j < 2 * n; ++ j){
					if(a[i] == a[j]){
						ded[j] = true;
					}
				}
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