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
		vector<int> a(n);
		for(auto i = 0; i < n; ++ i){
			cin >> a[i];
		}
		ranges::sort(a);
		a = vector<int>(a.end() - m, a.end());
		n = m;
		vector<int> size(n);
		vector<long long> sum(n);
		vector<vector<int>> group(n);
		for(auto i = 0; i < n; ++ i){
			cin >> size[i];
			group[i].resize(size[i]);
			for(auto j = 0; j < size[i]; ++ j){
				cin >> group[i][j];
			}
			sum[i] = accumulate(group[i].begin(), group[i].end(), 0LL);
		}
		vector<int> order(n), pos(n);
		iota(order.begin(), order.end(), 0);
		ranges::sort(order, [&](int i, int j){ return sum[i] * size[j] < sum[j] * size[i]; });
		for(auto t = 0; t < n; ++ t){
			pos[order[t]] = t;
		}
		vector<array<int, 3>> state(n);
		vector<array<int, 3>> pref(n + 1);
		for(auto t = 0; t < n; ++ t){
			int i = order[t];
			for(auto d = 0; d <= 2; ++ d){
				state[t][d] = clamp(t + d - 1, 0, n - 1) == t + d - 1 && 1LL * a[t + d - 1] * size[i] >= sum[i];
				pref[t + 1][d] = pref[t][d] + state[t][d];
			}
		}
		vector<string> res(n);
		auto solve = [&](int t, int i, int j)->bool{
			int x = group[i][j];
			if(1LL * x * size[i] >= sum[i]){
				int t2 = ranges::partition_point(order | ranges::views::take(t), [&](int k){ return sum[k] * (size[i] - 1) < (sum[i] - x) * size[k]; }) - order.begin();
				if(1LL * a[t2] * (size[i] - 1) < sum[i] - x){
					return false;
				}
				return pref[t2][1] + (pref[t][2] - pref[t2][2]) + (pref[n][1] - pref[t + 1][1]) == n - 1;
			}
			else{
				int t2 = ranges::partition_point(order | ranges::views::drop(t + 1), [&](int k){ return sum[k] * (size[i] - 1) < (sum[i] - x) * size[k]; }) - order.begin() - 1;
				if(1LL * a[t2] * (size[i] - 1) < sum[i] - x){
					return false;
				}
				return pref[t][1] + (pref[t2 + 1][0] - pref[t + 1][0]) + (pref[n][1] - pref[t2 + 1][1]) == n - 1;
			}
		};
		for(auto t = 0; t < n; ++ t){
			int i = order[t];
			res[i] = string(size[i], '?');
			for(auto j = 0; j < size[i]; ++ j){
				res[i][j] = solve(t, i, j) + '0';
			}
		}
		for(auto s: res | ranges::views::join){
			cout << s;
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