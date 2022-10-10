#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](auto __tc_num)->int{
		string s;
		cin >> s;
		int n = (int)s.size();
		array<int, 26> cnt{};
		string order;
		for(auto i = n - 1; i >= 0; -- i){
			++ cnt[s[i] - 'a'];
			if(cnt[s[i] - 'a'] == 1){
				order.push_back(s[i]);
			}
		}
		reverse(order.begin(), order.end());
		vector<int> sz((int)order.size());
		for(auto i = 0; i < (int)order.size(); ++ i){
			if(cnt[order[i] - 'a'] % (i + 1)){
				cout << "-1\n";
				return 0;
			}
			int x = cnt[order[i] - 'a'] / (i + 1);
			for(auto j = 0; j <= i; ++ j){
				sz[j] += x;
			}
		}
		for(auto i = 0, t = 0; t < (int)sz.size(); ++ t){
			int j = i + sz[t];
			array<int, 26> cnt2{};
			for(auto k = i; k < j; ++ k){
				++ cnt2[s[k] - 'a'];
			}
			for(auto tt = t; tt < (int)sz.size(); ++ tt){
				if(cnt2[order[tt] - 'a'] != cnt[order[tt] - 'a'] / (tt + 1)){
					cout << "-1\n";
					return 0;
				}
			}
			if(t + 1 < (int)sz.size()){
				int k = j + sz[t + 1];
				for(auto l = j, p = i; l < k; ++ l){
					while(p < j && s[p] != s[l]){
						++ p;
					}
					if(p == j){
						cout << "-1\n";
						return 0;
					}
				}
			}
			i = j;
		}
		cout << s.substr(0, sz[0]) << " " << order << "\n";
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