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
		string s;
		cin >> n >> k >> s;
		const int mx = 26;
		array<int, mx> cnt{};
		for(auto c: s){
			++ cnt[c - 'a'];
		}
		int res = 0;
		{
			auto init = cnt;
			vector<int> len(k);
			int i = 0;
			for(auto c = 0; c < mx; ++ c){
				if(i < k && cnt[c] & 1){
					-- cnt[c];
					len[i] = 1;
					++ i;
				}
			}
			for(auto c = 0; i < k; ++ i){
				while(c < mx && !cnt[c]){
					++ c;
				}
				if(c < mx){
					-- cnt[c];
					len[i] = 1;
				}
			}
			i %= k;
			for(auto c = 0; c < mx; ++ c){
				while(cnt[c] >= 2){
					cnt[c] -= 2;
					len[i] += 2;
					i = (i + 1) % k;
				}
			}
			ctmax(res, ranges::min(len));
			cnt = init;
		}
		{
			vector<int> len(k);
			int i = 0;
			for(auto c = 0; c < mx; ++ c){
				if(i < k && cnt[c] & 1){
					-- cnt[c];
					len[i] = 1;
					++ i;
				}
			}
			i %= k;
			for(auto c = 0; c < mx; ++ c){
				while(cnt[c] >= 2){
					cnt[c] -= 2;
					len[i] += 2;
					i = (i + 1) % k;
				}
			}
			ctmax(res, ranges::min(len));
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