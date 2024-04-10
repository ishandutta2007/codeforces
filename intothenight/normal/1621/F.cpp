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
		int n, a, b, c;
		string s;
		cin >> n >> a >> b >> c >> s;
		int fone = 0;
		vector<int> fzero;
		vector<int> zero;
		for(auto l = 0; l < n; ){
			int r = l;
			while(r < n && s[l] == s[r]){
				++ r;
			}
			if(s[l] & 1){
				fone += r - l - 1;
			}
			else if(l == 0 || r == n){
				fzero.push_back(r - l - 1);
			}
			else{
				zero.push_back(r - l - 1);
			}
			l = r;
		}
		ranges::sort(fzero);
		ranges::sort(zero);
		long long res = 0;
		for(auto i = 0; i < (int)zero.size() && fone; ){
			int x = min(zero[i], fone);
			res += 1LL * (a + b) * x;
			zero[i] -= x;
			fone -= x;
			if(!zero[i]){
				++ i;
			}
		}
		for(auto i = 0; i < (int)fzero.size() && fone; ){
			int x = min(fzero[i], fone);
			res += 1LL * (a + b) * x;
			fzero[i] -= x;
			fone -= x;
			if(!fzero[i]){
				++ i;
			}
		}
		ranges::reverse(fzero);
		ranges::reverse(zero);
		long long extra = numeric_limits<long long>::min();
		for(auto d = 0; d < 2; ++ d){
			int rfone = fone;
			vector<int> rfzero = fzero;
			vector<int> rzero = zero;
			if(fone >= d){
				fone -= d;
				long long cur = d * b;
				if((!fzero.empty() && fzero.front()) || (!zero.empty() && zero.front())){
					cur += a;
				}
				ctmax(extra, cur);
				while(!zero.empty() && !zero.back()){
					zero.pop_back();
					cur += b - c;
				}
				while(!fzero.empty() && fone){
					-- fone;
					fzero.pop_back();
					cur += b - c;
				}
				ctmax(extra, cur);
			}
			fzero = rfzero;
			fone = rfone;
			zero = rzero;
		}
		cout << res + max(extra, 0LL) << "\n";
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