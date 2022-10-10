#include <bits/stdc++.h>
using namespace std;
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](auto __tc_num)->int{
		int n;
		cin >> n;
		vector<int> a(n);
		vector<long long> pref(n + 1);
		for(auto i = 0; i < n; ++ i){
			cin >> a[i];
		}
		reverse(a.begin(), a.end());
		for(auto i = 0; i < n; ++ i){
			pref[i + 1] = pref[i] + a[i];
		}
		auto sum = [&](int l, int r)->long long{
			return pref[r] - pref[l];
		};
		vector<long long> dp(n + 1, numeric_limits<long long>::max());
		const long long minf = numeric_limits<long long>::min() / 2;
		for(auto len = 1; ; ++ len){
			static vector<long long> dp_next;
			dp_next.assign(n + 1, minf);
			for(auto i = len; i <= n; ++ i){
				dp_next[i] = dp_next[i - 1];
				if(auto s = sum(i - len, i); s < dp[i - len]){
					ctmax(dp_next[i], s);
				}
			}
			swap(dp, dp_next);
			if(dp[n] == minf){
				cout << len - 1 << "\n";
				return 0;
			}
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
len -> inc by one
sum -> strictly dec
*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////