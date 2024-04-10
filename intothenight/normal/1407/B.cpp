#include <bits/stdc++.h>
using namespace std;
template<typename T, typename U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<typename T, typename U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](int __tc_num){
		int n;
		cin >> n;
		vector<int> a(n);
		for(auto i = 0; i < n; ++ i){
			cin >> a[i];
		}
		vector<int> used(n), res(n);
		for(auto i = 0; i < n; ++ i){
			int g = 0;
			for(auto j = 0; j < i; ++ j){
				g = gcd(g, res[j]);
			}
			pair<int, int> cur{-1, -1};
			for(auto j = 0; j < n; ++ j){
				if(!used[j]){
					ctmax(cur, pair{gcd(g, a[j]), j});
				}
			}
			res[i] = a[cur.second];
			used[cur.second] = true;
			cout << a[cur.second] << " ";
		}
		cout << "\n";
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