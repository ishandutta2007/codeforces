#include <bits/stdc++.h>
using namespace std;
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](auto __tc_num)->int{
		int n, a, b;
		string s;
		cin >> n >> a >> b >> s;
		if(b >= 0){
			cout << (a + b) * n << "\n";
		}
		else{
			int cnt = 0;
			for(auto i = 0; i < n; ){
				int j = i;
				while(j < n && s[i] == s[j]){
					++ j;
				}
				++ cnt;
				i = j;
			}
			cout << a * n + b * (cnt + 2 >> 1) << "\n";
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