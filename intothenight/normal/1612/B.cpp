#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](auto __tc_num)->int{
		int n, a, b;
		cin >> n >> a >> b;
		vector<int> l, r, both;
		for(auto x = 1; x <= n; ++ x){
			if(x == a){
				l.push_back(x);
			}
			else if(x == b){
				r.push_back(x);
			}
			else if(a <= x && x <= b){
				both.push_back(x);
			}
			else if(a <= x){
				l.push_back(x);
			}
			else if(x <= b){
				r.push_back(x);
			}
			else{
				cout << "-1\n";
				return 0;
			}
		}
		if((int)l.size() > n / 2 || (int)r.size() > n / 2){
			cout << "-1\n";
			return 0;
		}
		for(auto x: l){
			cout << x << " ";
		}
		for(auto x: both){
			cout << x << " ";
		}
		for(auto x: r){
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