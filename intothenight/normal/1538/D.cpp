#include <bits/stdc++.h>
using namespace std;
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](int __tc_num){
		int a, b, k;
		cin >> a >> b >> k;
		array<int, 2> fact{};
		for(auto rep = 0; rep < 2; ++ rep){
			int t = a;
			for(auto x = 2; x * x <= t; ++ x){
				while(t % x == 0){
					++ fact[0];
					t /= x;
				}
			}
			if(t > 1){
				++ fact[0];
			}
			swap(a, b);
			swap(fact[0], fact[1]);
		}
		if(a == b){
			0 <= k && k <= fact[1] + fact[0] && k != 1 ? cout << "YES\n" : cout << "NO\n";
		}
		else if(a % b == 0 || b % a == 0){
			1 <= k && k <= fact[1] + fact[0] ? cout << "YES\n" : cout << "NO\n";
		}
		else{
			2 <= k && k <= fact[1] + fact[0] ? cout << "YES\n" : cout << "NO\n";
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