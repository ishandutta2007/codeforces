#include <bits/stdc++.h>
using namespace std;
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(n, vector<int>(m));
	for(auto i = 0; i < n; ++ i){
		for(auto j = 0; j < m; ++ j){
			cin >> a[i][j];
		}
	}
	for(auto i = 1; i < n; ++ i){
		for(auto j = 1; j < m; ++ j){
			if(a[0][0] + a[i][j] != a[i][0] + a[0][j]){
				cout << "-1\n";
				return 0;
			}
		}
	}
	int a0 = *min_element(a[0].begin(), a[0].end()), b0 = numeric_limits<int>::max();
	for(auto i = 0; i < n; ++ i){
		ctmin(b0, a[i][0]);
	}
	if(a[0][0] > a0 + b0){
		cout << "-1\n";
		return 0;
	}
	vector<pair<string, int>> res;
	if(n <= m){
		for(auto rep = 0; rep < a0; ++ rep){
			res.push_back({"row", 0});
		}
		for(auto j = 0; j < m; ++ j){
			a[0][j] -= a0;
		}
		for(auto rep = 0; rep < a[0][0]; ++ rep){
			res.push_back({"col", 0});
		}
		for(auto i = n - 1; i >= 0; -- i){
			a[i][0] -= a[0][0];
		}
	}
	else{
		for(auto rep = 0; rep < b0; ++ rep){
			res.push_back({"col", 0});
		}
		for(auto i = 0; i < n; ++ i){
			a[i][0] -= b0;
		}
		for(auto rep = 0; rep < a[0][0]; ++ rep){
			res.push_back({"row", 0});
		}
		for(auto j = m - 1; j >= 0; -- j){
			a[0][j] -= a[0][0];
		}
	}
	for(auto i = 1; i < n; ++ i){
		for(auto rep = 0; rep < a[i][0]; ++ rep){
			res.push_back({"row", i});
		}
	}
	for(auto j = 1; j < m; ++ j){
		for(auto rep = 0; rep < a[0][j]; ++ rep){
			res.push_back({"col", j});
		}
	}
	cout << (int)res.size() << "\n";
	for(auto [type, i]: res){
		cout << type << " " << i + 1 << "\n";
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