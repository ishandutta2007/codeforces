#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](auto __tc_num)->int{
		int n;
		cin >> n;
		const int mx = 1e4;
		vector<vector<int>> pos(mx + 1), neg(mx + 1);
		vector<int> a(n);
		for(auto i = 0; i < n; ++ i){
			cin >> a[i];
			if(a[i] > 0){
				pos[a[i]].push_back(i);
			}
			else{
				neg[-a[i]].push_back(i);
			}
		}
		vector<int> res(n), rem;
		for(auto x = 1; x <= mx; ++ x){
			for(auto i = 1; i < (int)pos[x].size(); i += 2){
				res[pos[x][i - 1]] = 1;
				res[pos[x][i]] = -1;
			}
			if((int)pos[x].size() & 1){
				rem.push_back(pos[x].back());
			}
			for(auto i = 1; i < (int)neg[x].size(); i += 2){
				res[neg[x][i - 1]] = 1;
				res[neg[x][i]] = -1;
			}
			if((int)neg[x].size() & 1){
				rem.push_back(neg[x].back());
			}
		}
		if((int)rem.size() == 1){
			for(auto x = 1; x <= mx; ++ x){
				if((int)pos[x].size() >= 2){
					rem.push_back(pos[x][0]);
					rem.push_back(pos[x][1]);
					break;
				}
				if((int)neg[x].size() >= 2){
					rem.push_back(neg[x][0]);
					rem.push_back(neg[x][1]);
					break;
				}
			}
		}
		if((int)rem.size() & 1){
			int i = rem[0], j = rem[1], k = rem[2];
			res[i] = a[j] * a[k];
			res[j] = a[k] * a[i];
			res[k] = -2 * a[i] * a[j];
			for(auto i = 4; i < (int)rem.size(); i += 2){
				res[rem[i - 1]] = a[rem[i]];
				res[rem[i]] = -a[rem[i - 1]];
			}
		}
		else{
			for(auto i = 1; i < (int)rem.size(); i += 2){
				res[rem[i - 1]] = a[rem[i]];
				res[rem[i]] = -a[rem[i - 1]];
			}
		}
		for(auto x: res){
			cout << x << " ";
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
x y z
yz zx 

1e9 - 30000 + 3e8
*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////