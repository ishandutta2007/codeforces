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
		array<int, 2> minpos{numeric_limits<int>::max()}, maxpos{numeric_limits<int>::min()};
		map<array<int, 2>, int> mp;
		for(auto i = 0; i < n; ++ i){
			int l, r, c;
			cin >> l >> r >> c;
			ctmin(minpos, array{l, c});
			ctmax(maxpos, array{r, -c});
			if(mp.contains({l, r})){
				ctmin(mp[{l, r}], c);
			}
			else{
				mp[{l, r}] = c;
			}
			if(mp.contains({minpos[0], maxpos[0]})){
				cout << min(minpos[1] - maxpos[1], mp[{minpos[0], maxpos[0]}]) << "\n";
			}
			else{
				cout << minpos[1] - maxpos[1] << "\n";
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

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////