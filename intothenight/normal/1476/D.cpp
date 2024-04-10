#include <bits/stdc++.h>
using namespace std;
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	string dr{"RL"};
	auto __solve_tc = [&](int __tc_num){
		int n;
		string s;
		cin >> n >> s;
		vector<int> res(n + 1);
		for(auto i = 0; i < n; ){
			int j = i + 1;
			while(j < n && s[j - 1] != s[j]){
				++ j;
			}
			if(s[i] == 'R'){
				for(auto k = i; k <= j; k += 2){
					ctmax(res[k], j - i + 1);
				}
				for(auto k = i + 1; k <= j; k += 2){
					ctmax(res[k], 1);
				}
			}
			else{
				for(auto k = i + 1; k <= j; k += 2){
					ctmax(res[k], j - i + 1);
				}
				for(auto k = i; k <= j; k += 2){
					ctmax(res[k], 1);
				}
			}
			i = j;
		}
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