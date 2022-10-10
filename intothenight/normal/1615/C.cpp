#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif

template<class T>
T &ctmin(T &x){
	return x;
}
template<class T, class Head, class ...Tail>
T &ctmin(T &x, const Head &h, const Tail &... t){
	return ctmin(x = min<T>(x, h), t...);
}
template<class T>
T &ctmax(T &x){
	return x;
}
template<class T, class Head, class ...Tail>
T &ctmax(T &x, const Head &h, const Tail &... t){
	return ctmax(x = max<T>(x, h), t...);
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](auto __tc_num)->int{
		int n;
		string a, b;
		cin >> n >> a >> b;
		int res = numeric_limits<int>::max();
		if(ranges::count(a, '0') == ranges::count(b, '0')){
			int cnt = 0;
			for(auto i = 0; i < n; ++ i){
				cnt += a[i] != b[i];
			}
			ctmin(res, cnt);
		}
		if(ranges::count(a, '1') - 1 == ranges::count(b, '0')){
			vector<int> pref(n + 1), suff(n + 1);
			for(auto i = 0; i < n; ++ i){
				pref[i + 1] = pref[i] + (a[i] == b[i]);
			}
			for(auto i = n - 1; i >= 0; -- i){
				suff[i] = suff[i + 1] + (a[i] == b[i]);
			}
			for(auto i = 0; i < n; ++ i){
				ctmin(res, pref[i] + suff[i + 1] + ((a[i] ^ 1) != b[i]));
			}
		}
		if(res == numeric_limits<int>::max()){
			res = -1;
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
9
001011011
011010101

apos[1]: 2, 4, 5, 7, 8
bpos[0]: 0, 3, 5, 7
*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////