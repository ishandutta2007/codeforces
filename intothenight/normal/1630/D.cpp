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
		int n, m;
		cin >> n >> m;
		vector<int> a(n);
		for(auto i = 0; i < n; ++ i){
			cin >> a[i];
		}
		int g = 0;
		for(auto i = 0; i < m; ++ i){
			int x;
			cin >> x;
			g = gcd(g, x);
		}
		if(g == 1){
			long long res = 0;
			for(auto x: a){
				res += abs(x);
			}
			cout << res << "\n";
			return 0;
		}
		long long sum = 0;
		vector<int> state(g);
		vector<vector<int>> grp(g);
		for(auto r = 0; r < g; ++ r){
			for(auto i = r; i < n; i += g){
				sum += abs(a[i]);
				grp[r].push_back(abs(a[i]));
				if(a[i] < 0){
					state[r] ^= 1;
				}
			}
			ranges::sort(grp[r]);
		}
		long long res = numeric_limits<long long>::min();
		for(auto _: ranges::iota_view(0, 2)){
			long long cur = sum;
			for(auto i = 0; i < g; ++ i){
				if(state[i]){
					cur -= 2 * grp[i].front();
				}
			}
			ctmax(res, cur);
			for(auto &x: state){
				x ^= 1;
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
1
6 1
-1 3 5 5 -5 4 
3 

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////