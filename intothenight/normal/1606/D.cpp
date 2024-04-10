#include <bits/stdc++.h>
using namespace std;
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](auto __tc_num)->int{
		int n, m;
		cin >> n >> m;
		vector<vector<int>> a(n, vector<int>(m));
		vector<vector<int>> pmax(n, vector<int>(m + 1));
		vector<vector<int>> pmin(n, vector<int>(m + 1, numeric_limits<int>::max()));
		vector<vector<int>> smax(n, vector<int>(m + 1));
		vector<vector<int>> smin(n, vector<int>(m + 1, numeric_limits<int>::max()));
		for(auto i = 0; i < n; ++ i){
			for(auto j = 0; j < m; ++ j){
				cin >> a[i][j];
				pmax[i][j + 1] = max(pmax[i][j], a[i][j]);
				pmin[i][j + 1] = min(pmin[i][j], a[i][j]);
			}
			for(auto j = m - 1; j >= 0; -- j){
				smax[i][j] = max(smax[i][j + 1], a[i][j]);
				smin[i][j] = min(smin[i][j + 1], a[i][j]);
			}
		}
		vector<int> order(n);
		iota(order.begin(), order.end(), 0);
		for(auto cut = 1; cut < m; ++ cut){
			sort(order.begin(), order.end(), [&](int i, int j){ return pmin[i][cut] < pmin[j][cut]; });
			int lbluemax = 0, rbluemin = numeric_limits<int>::max();
			multiset<int> lredmin, rredmax;
			for(auto i = 0; i < n; ++ i){
				lredmin.insert(pmin[i][cut]);
				rredmax.insert(smax[i][cut]);
			}
			for(auto p = 0; p < n - 1; ++ p){
				int i = order[p];
				ctmax(lbluemax, pmax[i][cut]);
				ctmin(rbluemin, smin[i][cut]);
				lredmin.erase(lredmin.find(pmin[i][cut]));
				rredmax.erase(rredmax.find(smax[i][cut]));
				if(lbluemax < *lredmin.begin() && *rredmax.rbegin() < rbluemin){
					string res(n, 'R');
					for(auto t = 0; t <= p; ++ t){
						res[order[t]] = 'B';
					}
					cout << "YES\n" << res << " " << cut << "\n";
					return 0;
				}
			}
		}
		cout << "NO\n";
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
1
5 3
5  12 6    R
18  8 23    R
23  15 21   R
18  27 21   R

4  27 23    B
*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////