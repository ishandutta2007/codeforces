#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](int __tc_num){
		int n;
		cin >> n;
		vector<vector<int>> s(n);
		vector<int> a(n);
		for(auto i = 0; i < n; ++ i){
			cin >> a[i], -- a[i];
		}
		for(auto i = 0; i < n; ++ i){
			int x;
			cin >> x;
			s[a[i]].push_back(x);
		}
		vector<long long> res(n + 1), aux(n + 2);
		for(auto &a: s){
			sort(a.rbegin(), a.rend());
			vector<long long> pref((int)a.size() + 1);
			for(auto i = 0; i < (int)a.size(); ++ i){
				pref[i + 1] = pref[i] + a[i];
			}
			for(auto sz = 1; sz <= (int)a.size(); ++ sz){
				res[sz] += pref[(int)a.size() / sz * sz];
			}
		}
		for(auto i = 1; i <= n; ++ i){
			cout << res[i] << " ";
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