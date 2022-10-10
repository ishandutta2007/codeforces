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
		int n;
		cin >> n;
		vector<int> a(n), b(n);
		copy_n(istream_iterator<int>(cin), n, a.begin());
		copy_n(istream_iterator<int>(cin), n, b.begin());
		vector<array<int, 4>> mapping{{0, n, 0, n}};
		int res = 0;
		#ifdef LOCAL
		const int mx = 3;
		#else
		const int mx = 30;
		#endif
		for(auto bit = mx - 1; bit >= 0; -- bit){
			static vector<array<int, 4>> mapping_next;
			mapping_next.clear();
			bool ok = true;
			for(auto [al, ar, bl, br]: mapping){
				int am = partition(a.begin() + al, a.begin() + ar, [&](int x){ return ~x & 1 << bit; }) - a.begin();
				int bm = partition(b.begin() + bl, b.begin() + br, [&](int x){ return ~x & 1 << bit; }) - b.begin();
				if(am - al != br - bm){
					ok = false;
					break;
				}
				if(al != am){
					mapping_next.push_back({al, am, bm, br});
				}
				if(am != ar){
					mapping_next.push_back({am, ar, bl, bm});
				}
			}
			if(ok){
				swap(mapping, mapping_next);
				res |= 1 << bit;
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
6
4 6 4 1 5 7 
1 6 6 4 4 5 


1 4 4 5 6 7
1 6 6 4 4 5
*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////