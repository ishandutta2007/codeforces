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
		array<double, 4> p;
		array<int, 4> sp;
		const int scale = 8e4;
		for(auto i = 0; i < 4; ++ i){
			cin >> p[i];
			sp[i] = round(p[i] * scale);
		}
		int v = sp[3];
		cout << fixed << setprecision(15);
		cout << y_combinator([&](auto self, array<int, 2> sp)->double{
			double res = scale - sp[0] - sp[1];
			for(auto i = 0; i < 2; ++ i){
				if(sp[i]){
					array<int, 2> sp_next = sp;
					int x = min(v, sp[i]);
					sp_next[i] -= x;
					if(sp[!i]){
						sp_next[!i] += x >> 1;
					}
					res += sp[i] * (1 + self(sp_next));
				}
			}
			return res / scale;
		})(array{sp[0], sp[1]}) << "\n";
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