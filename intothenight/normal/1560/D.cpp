#include <bits/stdc++.h>
using namespace std;
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	vector<string> pool;
	for(auto k = 0; k <= 60; ++ k){
		pool.push_back(to_string(1LL << k));
	}
	auto __solve_tc = [&](auto __tc_num)->int{
		string s;
		cin >> s;
		int n = (int)s.size(), res = numeric_limits<int>::max();
		for(auto x: pool){
			int i = 0, cnt = 0;
			for(auto c: x){
				while(i < n && s[i] != c){
					++ i;
				}
				if(i == n){
					break;
				}
				++ cnt;
				++ i;
			}
			ctmin(res, n + (int)x.size() - cnt * 2);
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