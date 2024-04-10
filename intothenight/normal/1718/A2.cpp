#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif
template<class T> T &ctmin(T &x){ return x; }
template<class T, class Head, class ...Tail> T &ctmin(T &x, const Head &h, const Tail &... t){ return ctmin(x = min<T>(x, h), t...); }
template<class T> T &ctmax(T &x){ return x; }
template<class T, class Head, class ...Tail> T &ctmax(T &x, const Head &h, const Tail &... t){ return ctmax(x = max<T>(x, h), t...); }



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](auto __tc_num)->int{
		int n;
		cin >> n;
		vector<int> a(n);
		copy_n(istream_iterator<int>(cin), n, a.begin());
		vector<int> pref(n + 1);
		for(auto i = 0; i < n; ++ i){
			pref[i + 1] = pref[i] ^ a[i];
		}
		map<int, int> last;
		last[0] = 0;
		vector<int> dp(n + 1, numeric_limits<int>::max());
		dp[0] = 0;
		for(auto i = 1; i <= n; ++ i){
			ctmin(dp[i], dp[i - 1] + 1);
			if(last.contains(pref[i])){
				int j = last[pref[i]];
				ctmin(dp[i], dp[j] + i - j - 1);
			}
			last[pref[i]] = i;
		}
		cout << dp[n] << "\n";
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