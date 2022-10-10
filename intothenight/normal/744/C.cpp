#include <bits/stdc++.h>
using namespace std;
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	vector<array<int, 3>> a;
	int rtot = 0, btot = 0;
	for(auto i = 0; i < n; ++ i){
		char type;
		int red, blue;
		cin >> type >> red >> blue;
		rtot += red, btot += blue;
		a.push_back({type == 'B', red, blue});
	}
	vector discount(1 << n, vector<array<int, 2>>{});
	discount[0].push_back({0, 0});
	for(auto mask = 1; mask < 1 << n; ++ mask){
		array<int, 2> cnt{};
		for(auto i = 0; i < n; ++ i){
			if(mask >> i & 1){
				++ cnt[a[i][0]];
			}
		}
		vector<array<int, 2>> cur;
		for(auto i = 0; i < n; ++ i){
			if(mask >> i & 1){
				-- cnt[a[i][0]];
				for(auto [x, y]: discount[mask ^ 1 << i]){
					cur.push_back({x + min(cnt[0], a[i][1]), y + min(cnt[1], a[i][2])});
				}
				++ cnt[a[i][0]];
			}
		}
		sort(cur.begin(), cur.end());
		for(auto [x, y]: cur){
			while(!discount[mask].empty() && discount[mask].back()[1] <= y){
				discount[mask].pop_back();
			}
			discount[mask].push_back({x, y});
		}
	}
	int res = numeric_limits<int>::max();
	for(auto [x, y]: discount.back()){
		ctmin(res, max({rtot - x, btot - y, 0}));
	}
	cout << res + n << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////