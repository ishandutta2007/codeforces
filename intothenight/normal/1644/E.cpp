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
		int n;
		string s;
		cin >> n >> s;
		if(s[0] == 'R'){
			for(auto &c: s){
				c ^= 'R' ^ 'D';
			}
		}
		if(s == string((int)s.size(), 'D')){
			cout << n << "\n";
			return 0;
		}
		vector<int> temp;
		array<int, 2> sum{};
		for(auto i = 0; i < (int)s.size(); ){
			int j = i;
			while(j < (int)s.size() && s[i] == s[j]){
				++ j;
			}
			sum[(int)temp.size() & 1] += j - i;
			temp.push_back(j - i);
			i = j;
		}
		vector<array<int, 2>> high, low;
		{
			auto len = temp;
			len[0] += n - 1 - sum[0];
			if(sum[1] != n - 1){
				if((int)len.size() & 1){
					len.push_back(n - 1 - sum[1]);
				}
				else{
					len.back() += n - 1 - sum[1];
				}
			}
			if((int)len.size() & 1){
				len.push_back(0);
			}
			for(auto i = 0, x = 0, h = 0; i < (int)len.size(); ++ i){
				if(~i & 1){
					h += len[i];
					high.push_back({x, h});
				}
				else{
					x += len[i];
				}
			}
			high.push_back({n, -1});
		}
		{
			auto len = temp;
			len[1] += n - 1 - sum[1];
			if(sum[0] != n - 1){
				if(~(int)len.size() & 1){
					len.push_back(n - 1 - sum[0]);
				}
				else{
					len.back() += n - 1 - sum[0];
				}
			}
			if((int)len.size() & 1){
				len.push_back(0);
			}
			for(auto i = 0, x = 0, h = 0; i < (int)len.size(); ++ i){
				if(~i & 1){
					h += len[i];
					low.push_back({x, h});
				}
				else{
					x += len[i];
				}
			}
			if(low.empty() || low.back()[1] != n - 1){
				low.push_back({n - 1, n - 1});
			}
			low.push_back({n, -1});
		}
		long long res = 2 * n - 1;
		for(auto i = 0, j = 0, x = 0; i < (int)high.size() - 1 && j < (int)low.size() - 1; ){
			if(high[i + 1][0] <= low[j + 1][0]){
				res += 1LL * (high[i][1] - low[j][1]) * (high[i + 1][0] - x);
				++ i;
				x = high[i][0];
			}
			else{
				res += 1LL * (high[i][1] - low[j][1]) * (low[j + 1][0] - x);
				++ j;
				x = low[j][0];
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

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////