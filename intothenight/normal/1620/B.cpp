#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](auto __tc_num)->int{
		int w, h;
		cin >> w >> h;
		long long res = 0;
		for(auto rep = 2; rep; -- rep){
			int n;
			cin >> n;
			vector<int> a(n);
			for(auto i = 0; i < n; ++ i){
				cin >> a[i];
			}
			int m;
			cin >> m;
			vector<int> b(m);
			for(auto i = 0; i < m; ++ i){
				cin >> b[i];
			}
			ctmax(res, 1LL * h * max(a.back() - a.front(), b.back() - b.front()));
			swap(w, h);
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