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
		int n, m;
		cin >> n >> m;
		vector<pair<int, long long>> a;
		{
			vector<int> t(n);
			copy_n(istream_iterator<int>(cin), n, t.begin());
			for(auto x: t){
				int p = 1;
				while(x % m == 0){
					x /= m;
					p *= m;
				}
				if(a.empty() || a.back().first != x){
					a.push_back({x, p});
				}
				else{
					a.back().second += p;
				}
			}
		}
		int k;
		cin >> k;
		vector<pair<int, long long>> b;
		{
			vector<int> t(k);
			copy_n(istream_iterator<int>(cin), k, t.begin());
			for(auto x: t){
				int p = 1;
				while(x % m == 0){
					x /= m;
					p *= m;
				}
				if(b.empty() || b.back().first != x){
					b.push_back({x, p});
				}
				else{
					b.back().second += p;
				}
			}
		}
		a == b ? cout << "Yes\n" : cout << "No\n";
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