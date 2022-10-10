#include <bits/stdc++.h>
using namespace std;

template<class F>
struct y_combinator_result{
	F f;
	template<class T> explicit y_combinator_result(T &&f): f(forward<T>(f)){ }
	template<class ...Args> decltype(auto) operator()(Args &&...args){ return f(ref(*this), forward<Args>(args)...); }
};
template<class F>
decltype(auto) y_combinator(F &&f){
	return y_combinator_result<decay_t<F>>(forward<F>(f));
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](auto __tc_num)->int{
		int n;
		cin >> n;
		cout << y_combinator([&](auto self, int n)->string{
			if(n <= 4){
				string res(n, 'a');
				iota(res.begin(), res.end(), 'a');
				return res;
			}
			string res = self((n - 2) / 3);
			char mx = *max_element(res.begin(), res.end());
			if((n - 2) % 3 == 0){
				res = res + char(mx + 1) + res + char(mx + 2) + res;
			}
			else if((n - 2) % 3 == 1){
				res = res + char(mx + 1) + res + char(mx + 2) + res + char(mx + 3);
			}
			else{
				res = res + char(mx + 1) + res + char(mx + 1) + char(mx + 2) + res + char(mx + 1);
			}
			assert(*max_element(res.begin(), res.end()) <= 'z');
			return res;
		})(n) << "\n";
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