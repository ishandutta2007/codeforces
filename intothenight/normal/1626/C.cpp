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
		vector<int> t(n), h(n);
		for(auto i = 0; i < n; ++ i){
			cin >> t[i];
		}
		for(auto i = 0; i < n; ++ i){
			cin >> h[i];
		}
		vector<long long> power(n);
		long long res = 0;
		for(auto i = 0; i < n; ++ i){
			for(auto j = i + 1; j < n; ++ j){
				ctmax(h[i], h[j] - (t[j] - t[i]));
			}
			int dist = t[i] - (i ? t[i - 1] : 0);
			long long prev = i ? power[i - 1] : 0;
			if(h[i] <= dist){
				power[i] = h[i];
				res += 1LL * h[i] * (h[i] + 1) / 2;
			}
			else{
				power[i] = prev + dist;
				res += (power[i] + power[i - 1] + 1) * dist / 2;
			}
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
2
4 5
2 2
*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////