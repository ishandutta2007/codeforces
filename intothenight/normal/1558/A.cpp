#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](auto __tc_num)->int{
		int a, b;
		cin >> a >> b;
		int n = a + b, na = n + 1 >> 1, nb = n >> 1;
		vector<int> res;
		for(auto rep = 2; rep; -- rep){
			for(auto x = 0; x <= min(a, na); ++ x){
				// alice won a games during her serve
				int xx = a - x;
				int y = na - x;
				int yy = b - y;
				if(0 <= yy && yy <= min(nb, b)){
					res.push_back(y + xx);
				}
			}
			swap(na, nb);
		}
		sort(res.begin(), res.end());
		res.erase(unique(res.begin(), res.end()), res.end());
		cout << (int)res.size() << "\n";
		for(auto x: res){
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