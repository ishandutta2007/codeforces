#include <bits/stdc++.h>
using namespace std;
template<typename T, typename U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<typename T, typename U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](int __tc_num){
		int n;
		cin >> n;
		vector<vector<int>> pos(n, {-1});
		for(auto i = 0; i < n; ++ i){
			int x;
			cin >> x, -- x;
			pos[x].push_back(i);
		}
		const int inf = numeric_limits<int>::max() / 2;
		vector<int> res(n + 2, inf);
		for(auto x = 0; x < n; ++ x){
			pos[x].push_back(n);
			int mxdif = numeric_limits<int>::min() / 2;
			for(auto i = 1; i < (int)pos[x].size(); ++ i){
				ctmax(mxdif, pos[x][i] - pos[x][i - 1]);
			}
			ctmin(res[mxdif], x + 1);
		}
		for(auto i = 1; i <= n; ++ i){
			ctmin(res[i], res[i - 1]);
			res[i] == inf ? cout << "-1 " : cout << res[i] << " ";
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