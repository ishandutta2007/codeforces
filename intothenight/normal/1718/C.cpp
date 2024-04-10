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
		int n, qn;
		cin >> n >> qn;
		vector<int> div;
		vector<vector<long long>> sum;
		{
			int x = n;
			for(auto p = 2; p * p <= x; ++ p){
				if(x % p == 0){
					div.push_back(n / p);
					sum.push_back(vector<long long>(n / p));
					while(x % p == 0){
						x /= p;
					}
				}
			}
			if(x >= 2){
				div.push_back(n / x);
				sum.push_back(vector<long long>(n / x));
			}
		}
		int m = (int)div.size();
		vector<int> a(n);
		for(auto i = 0; i < n; ++ i){
			cin >> a[i];
			for(auto j = 0; j < m; ++ j){
				sum[j][i % div[j]] += 1LL * a[i] * div[j];
			}
		}
		multiset<long long, greater<>> ms;
		for(auto &s: sum){
			for(auto x: s){
				ms.insert(x);
			}
		}
		cout << *ms.begin() << "\n";
		for(auto qi = 0; qi < qn; ++ qi){
			int i, x;
			cin >> i >> x, -- i;
			int delta = x - a[i];
			a[i] = x;
			for(auto j = 0; j < m; ++ j){
				int r = i % div[j];
				ms.erase(ms.find(sum[j][r]));
				sum[j][r] += 1LL * delta * div[j];
				ms.insert(sum[j][r]);
			}
			cout << *ms.begin() << "\n";
		}
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