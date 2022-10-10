#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](auto __tc_num)->int{
		int n, k;
		long long x;
		string s;
		cin >> n >> k >> x >> s, -- x;
		vector<long long> pow;
		for(auto l = 0; l < n; ){
			if(s[l] == '*'){
				int r = l;
				while(r < n && s[r] == '*'){
					++ r;
				}
				pow.push_back(k * (r - l) + 1);
				l = r;
			}
			else{
				++ l;
			}
		}
		if(!pow.empty()){
			pow.erase(pow.begin());
		}
		pow.push_back(1);
		for(auto i = (int)size(pow) - 2; i >= 0; -- i){
			pow[i] = __builtin_mul_overflow_p(pow[i], pow[i + 1], 0LL) ? numeric_limits<long long>::max() : pow[i] * pow[i + 1];
		}
		string res;
		for(auto l = 0, cnt = 0; l < n; ){
			if(s[l] == '*'){
				int r = l;
				while(r < n && s[r] == '*'){
					++ r;
				}
				res += string(x / pow[cnt], 'b');
				x %= pow[cnt ++];
				l = r;
			}
			else{
				res += s[l];
				++ l;
			}
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
babbbbbbb
babbbbbbbbb
*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////