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
		long long sum = 0;
		vector<array<int, 2>> a(n, {0, true});
		for(auto &x: a | ranges::views::keys){
			cin >> x;
			sum += x;
		}
		vector<long long> fib{0, 1};
		{
			long long fsum = 1;
			while(fsum < sum){
				fib.push_back(fib.end()[-1] + fib.end()[-2]);
				fsum += fib.back();
			}
			if(fsum != sum){
				cout << "No\n";
				return 0;
			}
			fib.erase(fib.begin());
		}
		for(auto f: fib | ranges::views::reverse){
			int i = ranges::max_element(a) - a.begin();
			if(!a[i][1] || a[i][0] < f){
				cout << "No\n";
				return 0;
			}
			a[i][0] -= f;
			a[i][1] = false;
			for(auto j = 0; j < n; ++ j){
				if(j != i){
					a[j][1] = true;
				}
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