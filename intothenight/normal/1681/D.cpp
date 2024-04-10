#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif

template<class F>
struct y_combinator_result{
	F f;
	template<class T> explicit y_combinator_result(T &&f): f(forward<T>(f)){ }
	template<class ...Args> decltype(auto) operator()(Args &&...args){ return f(ref(*this), forward<Args>(args)...); }
};
template<class F>
decltype(auto) y_combinator(F &&f){
	return y_combinator_result<decay_t<F>>(forward<F>(f));
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	long long x;
	cin >> n >> x;
	long long obj = 1;
	for(auto rep = n - 1; rep; -- rep){
		obj *= 10;
	}
	map<long long, int> dp;
	auto res = y_combinator([&](auto self, long long x)->int{
		if(x >= obj){
			return 0;
		}
		if(dp.contains(x)){
			return dp[x];
		}
		int res = numeric_limits<int>::max() / 2;
		for(auto y = x; y; y /= 10){
			auto d = y % 10;
			if(d >= 2){
				res = min(res, self(x * d) + 1);
			}
		}
		return dp[x] = res;
	})(x);
	if(res == numeric_limits<int>::max() / 2){
		res = -1;
	}
	cout << res << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////