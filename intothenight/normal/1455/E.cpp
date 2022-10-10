#include <bits/stdc++.h>
using namespace std;
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](int __tc_num){
		vector<array<long long, 2>> p(4);
		for(auto i = 0; i < 4; ++ i){
			for(auto j = 0; j < 2; ++ j){
				cin >> p[i][j];
			}
		}
		sort(p.begin(), p.end());
		long long res = numeric_limits<long long>::max();
		do{
			auto calc = [&](long long l){
				array<long long, 4> x{p[0][0], p[1][0] - l, p[2][0] - l, p[3][0]};
				array<long long, 4> y{p[0][1], p[1][1], p[2][1] - l, p[3][1] - l};
				sort(x.begin(), x.end()), sort(y.begin(), y.end());
				long long res = 0;
				for(auto v: x){
					res += abs(v - x[(int)x.size() / 2]);
				}
				for(auto v: y){
					res += abs(v - y[(int)y.size() / 2]);
				}
				return res;
			};
			long long low = 0, high = 2e9;
			while(high - low >= 3){
				long long mid1 = (2 * low + high) / 3, mid2 = (low + 2 * high) / 3;
				calc(mid1) >= calc(mid2) ? low = mid1 : high = mid2;
			}
			long long opt = low;
			for(auto i = low + 1; i < high; ++ i){
				if(calc(i) < calc(opt)){
					opt = i;
				}
			}
			ctmin(res, calc(opt));
		}while(next_permutation(p.begin(), p.end()));
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