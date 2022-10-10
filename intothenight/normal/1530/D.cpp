#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](auto __tc_num)->int{
		int n;
		cin >> n;
		vector<int> a(n), b(n, -1);
		vector<vector<int>> appear(n);
		vector<bool> flag(n);
		for(auto i = 0; i < n; ++ i){
			cin >> a[i], -- a[i];
			appear[a[i]].push_back(i);
			flag[a[i]] = true;
		}
		vector<int> rem;
		for(auto x = 0; x < n; ++ x){
			if(!flag[x]){
				rem.push_back(x);
			}
		}
		for(auto x = 0; x < n; ++ x){
			reverse(appear[x].begin(), appear[x].end());
			while((int)appear[x].size() >= 2){
				int i = appear[x].back();
				appear[x].pop_back();
				if(rem.back() != i){
					b[i] = rem.back();
					rem.pop_back();
				}
				else if((int)rem.size() >= 2){
					b[i] = *next(rem.rbegin());
					rem.erase(prev(prev(rem.end())));
				}
				else{
					swap(i, appear[x].back());
					b[i] = rem.back();
					rem.pop_back();
				}
			}
			if(!appear[x].empty()){
				b[appear[x][0]] = x;
			}
		}
		int res = 0;
		for(auto i = 0; i < n; ++ i){
			res += a[i] == b[i];
		}
		cout << res << "\n";
		for(auto x: b){
			cout << x + 1 << " ";
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