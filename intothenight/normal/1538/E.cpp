#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](int __tc_num){
		int n;
		cin >> n >> ws;
		string t;
		map<string, tuple<long long, string, string>> dp;
		long long res = -1;
		auto calc = [&](const string &s)->tuple<long long, string, string>{
			res = 0;
			for(auto i = 0; i + 4 <= (int)s.size(); ++ i){
				res += s.substr(i, 4) == "haha";
			}
			return {res, s.substr(0, min(3, (int)s.size())), s.substr(max(0, (int)s.size() - 3))};
		};
		for(auto rep = 0; rep < n; ++ rep){
			getline(cin, t);
			int p = find(t.begin(), t.end(), '=') - t.begin();
			if(t[p - 1] == ':'){
				string var = t.substr(0, p - 2);
				string x = t.substr(p + 2);
				dp[var] = calc(x);
			}
			else{
				int q = find(t.begin(), t.end(), '+') - t.begin();
				string var = t.substr(0, p - 1);
				string a = t.substr(p + 2, q - 1 - p - 2);
				string b = t.substr(q + 2);
				auto [x, pa, sa] = dp[a];
				auto [y, pb, sb] = dp[b];
				dp[var] = {
					res = x + y + get<0>(calc(sa + pb)),
					(pa + pb).substr(0, 3),
					(sa + sb).substr(max(0, (int)sa.size() + (int)sb.size() - 3))
				};
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