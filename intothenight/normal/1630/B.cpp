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
		int n, k;
		cin >> n >> k;
		vector<int> a(n), cnt(n);
		for(auto i = 0; i < n; ++ i){
			cin >> a[i], -- a[i];
			++ cnt[a[i]];
		}
		int xcur, ycur;
		auto bad = [&](int dif)->bool{
			int cur = 0;
			for(auto x = 0; x < dif; ++ x){
				cur += cnt[x];
			}
			for(auto x = 0; x + dif < n; ++ x){
				int y = x + dif;
				cur += cnt[y];
				if(cur >= n - cur + k){
					xcur = x;
					ycur = y;
					return false;
				}
				cur -= cnt[x];
			}
			return true;
		};
		int dif = *ranges::partition_point(ranges::iota_view(0, n - 1), bad);
		assert(!bad(dif));
		vector<array<int, 3>> res;
		for(auto i = 0; i < n; ++ i){
			int bal = xcur <= a[i] && a[i] <= ycur ? 1 : -1;
			int l = i, r = i + 1;
			while(!res.empty() && (bal <= 0 || res.back()[2] <= 0)){
				bal += res.back()[2];
				l = res.back()[0];
				res.pop_back();
			}
			res.push_back({l, r, bal});
		}
		while((int)res.size() > k){
			int r = res.back()[1];
			res.pop_back();
			res.back()[1] = r;
		}
		assert((int)res.size() == k);
		cout << xcur + 1 << " " << ycur + 1 << "\n";
		for(auto [l, r, b]: res){
			assert(b > 0);
			cout << l + 1 << " " << r << "\n";
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