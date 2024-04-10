#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](int __tc_num){
		int n;
		cin >> n;
		vector<int> x, y;
		for(auto i = 0; i < 2 * n; ++ i){
			int a, b;
			cin >> a >> b;
			if(!a){
				y.push_back(abs(b));
			}
			else{
				x.push_back(abs(a));
			}
		}
		sort(x.begin(), x.end());
		sort(y.begin(), y.end());
		double res = 0;
		cout << fixed << setprecision(15);
		for(auto i = 0; i < n; ++ i){
			res += hypot(x[i], y[i]);
		}
		cout << res << "\n";
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