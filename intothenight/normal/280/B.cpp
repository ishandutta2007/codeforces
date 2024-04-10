#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	vector<int> a(n);
	copy_n(istream_iterator<int>(cin), n, a.begin());
	array<array<int, 2>, 30> cnt{};
	for(auto x: a){
		for(auto bit = 0; bit < 30; ++ bit){
			++ cnt[bit][x >> bit & 1];
		}
	}
	int obj = 0;
	for(auto bit = 29; bit >= 0; -- bit){
		if(cnt[bit][0] && cnt[bit][1]){
			obj = bit;
			break;
		}
	}
	int res = 0;
	for(auto i = 0; i < n; ++ i){
		if(a[i] & 1 << obj){
			int smax = -1;
			for(auto j = i - 1; j >= 0 && ~a[j] & 1 << obj; -- j){
				smax = max(smax, a[j]);
				res = max(res, a[i] ^ smax);
			}
			smax = -1;
			for(auto j = i + 1; j < n && ~a[j] & 1 << obj; ++ j){
				smax = max(smax, a[j]);
				res = max(res, a[i] ^ smax);
			}
		}
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