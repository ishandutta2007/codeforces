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
		vector<int> a(n), b(n);
		copy_n(istream_iterator<int>(cin), n, a.begin());
		copy_n(istream_iterator<int>(cin), n, b.begin());
		vector<array<int, 2>> rb;
		for(auto i = 0; i < n; ){
			int j = i;
			while(j < n && b[i] == b[j]){
				++ j;
			}
			rb.push_back({i, j - i - 1});
			i = j;
		}
		int m = (int)rb.size();
		vector<int> maps_to(m);
		map<int, int> cnt;
		for(auto j = m - 1, i = n - 1; j >= 0; -- j){
			int x = b[rb[j][0]];
			while(i >= 0 && a[i] != x){
				if(!cnt[a[i]]){
					cout << "NO\n";
					return 0;
				}
				-- cnt[a[i]];
				-- i;
			}
			if(i < 0){
				cout << "NO\n";
				return 0;
			}
			cnt[b[rb[j][0]]] += rb[j][1];
			-- i;
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