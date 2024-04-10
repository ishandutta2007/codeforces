#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](int __tc_num){
		int n;
		cin >> n;
		vector<int> a(2 * n);
		for(auto i = 0; i < 2 * n; ++ i){
			cin >> a[i];
		}
		sort(a.begin(), a.end());
		vector<array<int, 2>> res;
		auto check = [&](int x){
			vector<int> cur = a;
			res.clear();
			while(!cur.empty()){
				auto it = lower_bound(cur.begin(), cur.end(), x - cur.back());
				if(it == prev(cur.end()) || it == cur.end() || *it + cur.back() != x){
					return false;
				}
				x = cur.back();
				res.push_back({*it, cur.back()});
				cur.erase(it);
				cur.pop_back();
			}
			return true;
		};
		for(auto i = 0; i < 2 * n - 1; ++ i){
			if(check(a[i] + a.back())){
				cout << "YES\n" << a[i] + a.back() << "\n";
				for(auto [x, y]: res){
					cout << x << " " << y << "\n";
				}
				return 0;
			}
		}
		cout << "NO\n";
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