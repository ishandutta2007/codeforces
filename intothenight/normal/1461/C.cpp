#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](int __tc_num){
		int n, m;
		cin >> n >> m;
		vector<int> a(n);
		for(auto i = 0; i < n; ++ i){
			cin >> a[i], -- a[i];
		}
		int p = n - 1;
		while(p >= 0 && a[p] == p){
			-- p;
		}
		double tot = 1;
		for(auto qi = 0; qi < m; ++ qi){
			int pos;
			double prob;
			cin >> pos >> prob, -- pos;
			if(pos >= p){
				tot *= 1 - prob;
			}
		}
		cout << fixed << setprecision(15);
		cout << (~p ? 1 - tot : 1.0) << "\n";
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