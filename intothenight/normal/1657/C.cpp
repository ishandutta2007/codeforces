#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif

// p[0][i]: half length of even pal substring around i, p[1][i]: half length(rounded donw) of odd pal substring
// O(n)
template<class Char_Type>
array<vector<int>, 2> manacher(const vector<Char_Type> &s){
	int n = (int)s.size();
	array<vector<int>, 2> p = {vector<int>(n + 1), vector<int>(n)};
	for(auto z = 0; z < 2; ++ z){
		for(auto i = 0, l = 0, r = 0; i < n; ++ i){
			int t = r - i + !z;
			if(i < r) p[z][i] = min(t, p[z][l + t]);
			int L = i - p[z][i], R = i + p[z][i] - !z;
			while(L >= 1 && R + 1 < n && s[L - 1] == s[R + 1]) ++ p[z][i], -- L, ++ R;
			if(R > r) l = L, r = R;
		}
	}
	return p;
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](auto __tc_num)->int{
		int n;
		string s;
		cin >> n >> s;
		auto mc = manacher(vector<int>(s.begin(), s.end()));
		auto conv = [&](char c)->int{
			return c == '(' ? 1 : -1;
		};
		for(auto l = 0, res = 0; ; ){
			int r = l + 1, balance = conv(s[l]), minpref = min(balance, 0);
			while(r <= n){
				if(!balance && minpref >= 0 || r - l >= 2 && mc[r - l & 1][l + r >> 1] >= r - l >> 1){
					++ res;
					break;
				}
				if(r < n){
					balance += conv(s[r]);
					minpref = min(minpref, balance);
				}
				++ r;
			}
			if(r == n + 1){
				cout << res << " " << r - l - 1 << "\n";
				return 0;
			}
			l = r;
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