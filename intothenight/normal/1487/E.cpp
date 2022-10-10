#include <bits/stdc++.h>
using namespace std;
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }

template<class T>
struct sparse_table{
	int n;
	vector<vector<T>> data;
	function<T(T, T)> TT; // monoid operation (must be idempotent)
	T T_id; // monoid identity
	sparse_table(){ }
	sparse_table(const vector<T> &a, function<T(T, T)> TT, T T_id): n((int)a.size()), TT(TT), T_id(T_id), data({a}){ // O(n log n)
		for(auto p = 1, i = 1; p << 1 <= n; p <<= 1, ++ i){
			data.emplace_back(n - (p << 1) + 1);
			for(auto j = 0; j < (int)data[i].size(); ++ j) data[i][j] = TT(data[i - 1][j], data[i - 1][j + p]);
		}
	}
	T query(int l, int r){ // O(1)
		if(l >= r) return T_id;
		int d = __lg(r - l);
		return TT(data[d][l], data[d][r - (1 << d)]);
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	array<int, 4> n;
	for(auto i = 0; i < 4; ++ i){
		cin >> n[i];
	}
	array<vector<int>, 4> cost;
	for(auto i = 0; i < 4; ++ i){
		cost[i].resize(n[i]);
		for(auto j = 0; j < n[i]; ++ j){
			cin >> cost[i][j];
		}
	}
	vector<long long> dp(n[0]);
	for(auto i = 0; i < n[0]; ++ i){
		dp[i] = cost[0][i];
	}
	for(auto i = 1; i <= 3; ++ i){
		int m;
		cin >> m;
		vector<vector<int>> bad(n[i]);
		for(auto j = 0; j < m; ++ j){
			int x, y;
			cin >> x >> y, -- x, -- y;
			bad[y].push_back(x);
		}
		sparse_table<long long> st(dp, [&](auto x, auto y){ return min(x, y); }, numeric_limits<long long>::max() / 3);
		vector<long long> dp_next(n[i], numeric_limits<long long>::max() / 3);
		for(auto j = 0; j < n[i]; ++ j){
			bad[j].push_back(-1), bad[j].push_back(n[i - 1]);
			sort(bad[j].begin(), bad[j].end());
			bad[j].erase(unique(bad[j].begin(), bad[j].end()), bad[j].end());
			for(auto k = 1; k < (int)bad[j].size(); ++ k){
				ctmin(dp_next[j], st.query(bad[j][k - 1] + 1, bad[j][k]) + cost[i][j]);
			}
		}
		swap(dp, dp_next);
	}
	auto res = *min_element(dp.begin(), dp.end());
	res < numeric_limits<long long>::max() / 3 ? cout << res << "\n" : cout << "-1\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////