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
		cin >> n;
		vector<int> a(n);
		array<bool, 3> cnt{};
		set<int> appear;
		for(auto i = 0; i < n; ++ i){
			cin >> a[i];
			if(a[i] <= 2){
				cnt[a[i]] = true;
			}
			appear.insert(a[i]);
		}
		ranges::sort(a);
		if(!cnt[1]){
			cout << "YES\n";
			return 0;
		}
		if(cnt[0]){
			cout << "NO\n";
			return 0;
		}
		vector<int> b(appear.begin(), appear.end());
		for(auto i = 0; i < (int)b.size() - 1; ++ i){
			if(b[i] + 1 == b[i + 1]){
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