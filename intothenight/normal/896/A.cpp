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
		long long k;
		cin >> n >> k, -- k;
		string f0("What are you doing at the end of the world? Are you busy? Will you save us?");
		string left("What are you doing while sending \"");
		string middle("\"? Are you busy? Will you send \"");
		string right("\"?");
		vector<long long> len(n + 1);
		const long long inf = numeric_limits<long long>::max() / 4;
		len[0] = (int)f0.size();
		for(auto i = 1; i <= n; ++ i){
			len[i] = min((int)left.size() + (int)middle.size() + (int)right.size() + 2 * len[i - 1], inf);
		}
		cout << y_combinator([&](auto self, int n, long long k)->char{
			if(len[n] <= k){
				return '.';
			}
			if(n == 0){
				return k < len[0] ? f0[k] : '.';
			}
			if(k < (int)left.size()){
				return left[k];
			}
			k -= (int)left.size();
			if(k < len[n - 1]){
				return self(n - 1, k);
			}
			k -= len[n - 1];
			if(k < (int)middle.size()){
				return middle[k];
			}
			k -= (int)middle.size();
			if(k < len[n - 1]){
				return self(n - 1, k);
			}
			k -= len[n - 1];
			if(k < (int)right.size()){
				return right[k];
			}
			k -= (int)right.size();
			return '.';
		})(n, k);
		return 0;
	};
	int __tc_cnt;
	cin >> __tc_cnt;
	for(auto __tc_num = 0; __tc_num < __tc_cnt; ++ __tc_num){
		__solve_tc(__tc_num);
	}
	cout << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////