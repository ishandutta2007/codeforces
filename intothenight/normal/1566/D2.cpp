#include <bits/stdc++.h>
using namespace std;
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](auto __tc_num)->int{
		int n, m;
		cin >> n >> m;
		vector<int> a(n * m);
		for(auto i = 0; i < n * m; ++ i){
			cin >> a[i];
		}
		vector<int> order(n * m);
		iota(order.begin(), order.end(), 0);
		sort(order.begin(), order.end(), [&](int i, int j){
			return a[i] != a[j] ? a[i] < a[j] : i > j;
		});
		vector<vector<int>> filled(n, vector<int>(m));
		map<int, array<int, 2>> range;
		for(auto l = 0; l < n * m; ){
			int r = l;
			while(r < n * m && a[order[l]] == a[order[r]]){
				++ r;
			}
			range[a[order[l]]] = {l, r};
			l = r;
		}
		int res = 0;
		for(auto i = 0; i < n * m; ++ i){
			auto [l, r] = range[a[i]];
			array<int, 2> mx{numeric_limits<int>::min(), -1};
			for(auto x = l; x < r; ++ x){
				if(!filled[x / m][x % m]){
					ctmax(mx, array{-(x / m), x % m});
				}
			}
			auto [x, y] = mx;
			x = -x;
			filled[x][y] = true;
			for(auto j = 0; j < y; ++ j){
				res += filled[x][j];
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

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////