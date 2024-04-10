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
	const int mx = 1000;
	vector<int> cnt(mx + 1, numeric_limits<int>::max() / 2);
	cnt[0] = cnt[1] = 0;
	for(auto x = 1; x <= mx; ++ x){
		for(auto num = 1; num <= x; ++ num){
			if(x + x / num <= mx){
				ctmin(cnt[x + x / num], cnt[x] + 1);
			}
		}
	}
	const int mxval = ranges::max(cnt);
	auto __solve_tc = [&](auto __tc_num)->int{
		int n, k;
		cin >> n >> k;
		vector<vector<int>> a(mxval + 1);
		vector<int> b(n);
		for(auto i = 0; i < n; ++ i){
			cin >> b[i];
		}
		int sum = 0;
		for(auto i = 0; i < n; ++ i){
			int x;
			cin >> x;
			sum += x;
			a[cnt[b[i]]].push_back(x);
		}
		if(n * mxval <= k){
			cout << sum << "\n";
			return 0;
		}
		// k <= 12000
		vector<int> dp(k + 1, accumulate(a[0].begin(), a[0].end(), 0));
		for(auto x = 1; x <= mxval; ++ x){
			ranges::sort(a[x] | ranges::views::reverse);
			for(auto y = k; y >= 0; -- y){
				int pref = 0;
				for(auto i = 1; i <= (int)a[x].size() && i * x <= y; ++ i){
					pref += a[x][i - 1];
					ctmax(dp[y], dp[y - i * x] + pref);
				}
			}
		}
		cout << ranges::max(dp) << "\n";
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
1->0
2->1
5->3
7->4
*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////