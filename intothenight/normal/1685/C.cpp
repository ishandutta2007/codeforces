#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto check = [&](string s)->bool{
		int pref = 0;
		for(auto c: s){
			if(c == '('){
				pref += 1;
			}
			else{
				pref -= 1;
				if(pref < 0){
					return false;
				}
			}
		}
		assert(!pref);
		return true;
	};
	auto __solve_tc = [&](auto __tc_num)->int{
		int n;
		string s;
		cin >> n >> s, n <<= 1;
		if(check(s)){
			cout << "0\n";
			return 0;
		}
		{
			array<int, 2> left{0, 0};
			for(auto i = 0, pref = 0; i < n; ++ i){
				pref += s[i] == '(' ? 1 : -1;
				if(pref < 0){
					break;
				}
				left = max(left, array{pref, i + 1});
			}
			array<int, 2> right{0, n};
			for(auto i = n - 1, suff = 0; i >= 0; -- i){
				suff += s[i] == ')' ? 1 : -1;
				if(suff < 0){
					break;
				}
				right = max(right, array{suff, i});
			}
			int l = left[1], r = right[1];
			ranges::reverse(s | ranges::views::take(r) | ranges::views::drop(l));
			if(check(s)){
				cout << "1\n" << l + 1 << " " << r << "\n";
				return 0;
			}
			ranges::reverse(s | ranges::views::take(r) | ranges::views::drop(l));
		}
		array<int, 2> mx{0, 0};
		for(auto i = 0, pref = 0; i < n; ++ i){
			pref += s[i] == '(' ? 1 : -1;
			mx = max(mx, array{pref, i + 1});
		}
		int m = mx[1];
		vector<array<int, 2>> res;
		{
			int pref = 0;
			for(auto c: s | ranges::views::take(m)){
				pref += c == '(' ? 1 : -1;
				if(pref < 0){
					res.push_back({0, m});
					break;
				}
			}
		}
		{
			int pref = 0;
			for(auto c: s | ranges::views::reverse | ranges::views::take(n - m)){
				pref += c == ')' ? 1 : -1;
				if(pref < 0){
					res.push_back({m, n});
					break;
				}
			}
		}
		cout << (int)res.size() << "\n";
		for(auto [l, r]: res){
			cout << l + 1 << " " << r << "\n";
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