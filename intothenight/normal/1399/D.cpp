#include "bits/stdc++.h"
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	auto __solve_tc = [&](int __tc_num){
		int n;
		string s;
		cin >> n >> s;
		array<set<int>, 2> pos;
		for(auto i = 0; i < n; ++ i){
			pos[s[i] - '0'].insert(i);
		}
		int cnt = 0;
		vector<int> res(n);
		while(!pos[0].empty() || !pos[1].empty()){
			++ cnt;
			for(int t = pos[0].empty() || !pos[1].empty() && *pos[0].begin() > *pos[1].begin(), prev = -1; ; ){
				auto it = pos[t].lower_bound(prev);
				if(it == pos[t].end()){
					break;
				}
				res[*it] = cnt;
				prev = *it;
				pos[t].erase(it);
				t = !t;
			}
		}
		cout << cnt << "\n";
		for(auto x: res){
			cout << x << " ";
		}
		cout << "\n";
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