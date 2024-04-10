#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](auto __tc_num)->int{
		int n;
		cin >> n;
		vector<int> a(n), pos(n);
		vector<vector<int>> appear(n);
		for(auto i = 0; i < n; ++ i){
			cin >> a[i], -- a[i];
			pos[i] = (int)appear[a[i]].size();
			appear[a[i]].push_back(i);
		}
		int bad = n + 1;
		vector<int> next(n + 2, bad);
		const int mx = 20;
		vector<array<int, mx>> lift(n + 2);
		lift[bad].fill(bad);
		lift[n].fill(bad);
		auto rightmost = [&](int i, int th)->int{
			for(auto bit = mx - 1; bit >= 0; -- bit){
				if(lift[i][bit] <= th){
					i = lift[i][bit];
				}
			}
			return i;
		};
		for(auto i = n - 1; i >= 0; -- i){
			lift[i].fill(bad);
			int x = a[i];
			if(pos[i] + 1 == (int)appear[x].size()){
				continue;
			}
			for(auto j = appear[x][pos[i] + 1]; ; ){
				if(rightmost(i + 1, j) == j){
					next[i] = j + 1;
					lift[i][0] = j + 1;
					for(auto bit = 1; bit < mx; ++ bit){
						lift[i][bit] = lift[lift[i][bit - 1]][bit - 1];
					}
					break;
				}
				if(next[j] == bad){
					break;
				}
				int k = next[j] - 1;
				if(pos[k] + 1 == (int)appear[x].size()){
					break;
				}
				j = appear[x][pos[k] + 1];
			}
		}
		vector<int> dp(n + 1);
		for(auto i = n - 1; i >= 0; -- i){
			if(next[i] != bad){
				dp[i] = dp[next[i]] + 1;
			}
		}
		cout << accumulate(dp.begin(), dp.end(), 0LL) << "\n";
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