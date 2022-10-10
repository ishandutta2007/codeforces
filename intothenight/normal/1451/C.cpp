#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](int __tc_num){
		int n, k;
		string s, t;
		cin >> n >> k >> s >> t;
		array<int, 26> cnts{}, cntt{};
		for(auto c: s){
			++ cnts[c - 'a'];
		}
		for(auto c: t){
			++ cntt[c - 'a'];
		}
		int rem = 0;
		for(auto c = 0; c < 26; ++ c){
			if(cnts[c] % k != cntt[c] % k){
				cout << "No\n";
				return 0;
			}
			if(cnts[c] > cntt[c]){
				rem += (cnts[c] - cntt[c]) / k;
			}
			else if(rem * k + cnts[c] < cntt[c]){
				cout << "No\n";
				return 0;
			}
			else{
				rem -= (cntt[c] - cnts[c]) / k;
			}
		}
		cout << "Yes\n";
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