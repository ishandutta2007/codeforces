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
		string s, t;
		cin >> n >> s >> t;
		vector<int> poss, post;
		for(auto i = 0, cnts = 0, cntt = 0; i < n; ++ i){
			if(s[i] == 'b'){
				poss.push_back(cnts);
			}
			else{
				++ cnts;
			}
			if(t[i] == 'b'){
				post.push_back(cntt);
			}
			else{
				++ cntt;
			}
		}
		erase(s, 'b');
		erase(t, 'b');
		if(s != t){
			cout << "NO\n";
			return 0;
		}
		vector<array<int, 2>> cnt((int)s.size() + 1);
		for(auto i = 0; i < (int)s.size(); ++ i){
			cnt[i + 1] = cnt[i];
			++ cnt[i + 1][s[i] == 'c'];
		}
		assert((int)poss.size() == (int)post.size());
		for(auto i = 0; i < (int)poss.size(); ++ i){
			if(poss[i] == post[i]){
				continue;
			}
			if(cnt[poss[i]][poss[i] > post[i]] - cnt[post[i]][poss[i] > post[i]]){
				cout << "NO\n";
				return 0;
			}
		}
		cout << "YES\n";
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