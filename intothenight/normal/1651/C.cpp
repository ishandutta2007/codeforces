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
		vector<int> a(n), b(n);
		for(auto i = 0; i < n; ++ i){
			cin >> a[i];
		}
		for(auto i = 0; i < n; ++ i){
			cin >> b[i];
		}
		array<long long, 4> opt;
		opt.fill(numeric_limits<long long>::max());
		for(auto i = 0; i < n; ++ i){
			ctmin(opt[0], abs(a.front() - b[i]));
			ctmin(opt[1], abs(a.back() - b[i]));
			ctmin(opt[2], abs(b.front() - a[i]));
			ctmin(opt[3], abs(b.back() - a[i]));
		}
		cout << min<long long>({
			abs(a.front() - b.front()) + abs(a.back() - b.back()),
			abs(a.front() - b.back()) + abs(a.back() - b.front()),
			abs(a.front() - b.front()) + opt[1] + opt[3],
			abs(a.front() - b.back()) + opt[1] + opt[2],
			abs(a.back() - b.front()) + opt[0] + opt[3],
			abs(a.back() - b.back()) + opt[0] + opt[2],
			accumulate(opt.begin(), opt.end(), 0LL)
		}) << "\n";
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