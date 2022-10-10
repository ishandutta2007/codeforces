#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](auto __tc_num)->int{
		int n, init;
		cin >> n >> init, -- init;
		vector<int> a(n);
		copy_n(istream_iterator<int>(cin), n, a.begin());
		for(auto rep = 0; rep < 2; ++ rep){
			vector<long long> pref(n + 1);
			for(auto i = 0; i < n; ++ i){
				pref[i + 1] = pref[i] + a[i];
			}
			int l = init, r = init + 1;
			while(l > 0){
				int nl = l;
				long long minval = 0;
				while(nl >= 0 && pref[l] - pref[nl] <= 0){
					minval = min(minval, pref[l] - pref[nl]);
					-- nl;
				}
				if(!~nl){
					break;
				}
				int nr = r;
				while(nr < n && pref[nr] - pref[l] + minval < 0 && pref[nr + 1] - pref[l] >= 0){
					++ nr;
				}
				if(pref[nr] - pref[l] + minval < 0){
					break;
				}
				l = nl;
				r = nr;
			}
			while(r < n && pref[r + 1] - pref[l] >= 0){
				++ r;
			}
			if(r == n){
				cout << "YES\n";
				return 0;
			}
			init = n - 1 - init;
			ranges::reverse(a);
		}
		cout << "NO\n";
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