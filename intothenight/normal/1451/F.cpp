#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](int __tc_num){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> a(n, vector<int>(m));
		vector<int> h(n + m - 1);
		for(auto i = 0; i < n; ++ i){
			for(auto j = 0; j < m; ++ j){
				cin >> a[i][j];
				h[i + j] ^= a[i][j];
			}
		}
		if(any_of(h.begin(), h.end(), [&](int x){ return x; })){
			cout << "Ashish\n";
		}
		else{
			cout << "Jeel\n";
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