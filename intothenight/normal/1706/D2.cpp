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
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		copy_n(istream_iterator<int>(cin), n, a.begin());
		vector<int> p(n, 1);
		static vector<vector<int>> queue(100001);
		for(auto q = 0; q <= 100000; ++ q){
			queue[q].clear();
			queue[q].shrink_to_fit();
		}
		int minval = numeric_limits<int>::max();
		for(auto i = 0; i < n; ++ i){
			queue[a[i] / p[i]].push_back(i);
			ctmin(minval, a[i] / p[i]);
		}
		int res = numeric_limits<int>::max();
		for(auto q = 100000; q >= 0; -- q){
			while(!queue[q].empty()){
				int i = queue[q].back();
				queue[q].pop_back();
				ctmin(res, q - minval);
				p[i] = a[i] / (a[i] / p[i]) + 1;
				if(p[i] > min(a[i], k)){
					q = 0;
					break;
				}
				queue[a[i] / p[i]].push_back(i);
				ctmin(minval, a[i] / p[i]);
			}
			queue[q].shrink_to_fit();
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