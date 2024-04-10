#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
mt19937_64 rngll(chrono::high_resolution_clock::now().time_since_epoch().count());
using randint_t = uniform_int_distribution<int>;
using randll_t = uniform_int_distribution<long long>;
using randd_t = uniform_real_distribution<double>;
// return x with probability p, y with probability 1-p
template<class T>
T pick(T x, T y, double p = 0.5){
	assert(-0.0001 <= p && p <= 1.0001);
	return randd_t(0, 1)(rng) <= p ? x : y;
}



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](auto __tc_num)->int{
		int n;
		cin >> n;
		vector<int> a(n);
		iota(a.begin(), a.end(), 1);
		set<vector<int>> res;
		do{
			while(true){
				ranges::shuffle(a, rng);
				bool ok = true;
				for(auto i = 2; i < n; ++ i){
					if(a[i - 2] + a[i - 1] == a[i]){
						ok = false;
						break;
					}
				}
				if(ok){
					res.insert(a);
					break;
				}
			}
		}while((int)res.size() < n);
		for(auto p: res){
			ranges::copy(p, ostream_iterator<int>(cout, " "));
			cout << "\n";
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