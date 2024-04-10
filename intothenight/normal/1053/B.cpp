#include <bits/stdc++.h>
using namespace std;

template<class Q, Q (*merge)(Q, Q), Q (*identity)()>
struct sparse_table{
	int n;
	vector<vector<Q>> val;
	sparse_table(vector<Q> &a): n((int)a.size()), val({a}){ // O(n log n)
		for(int p = 1, i = 1; p << 1 <= n; p <<= 1, ++ i){
			val.emplace_back(n - (p << 1) + 1);
			for(int j = 0; j < (int)val[i].size(); ++ j) val[i][j] = merge(val[i - 1][j], val[i - 1][j + p]);
		}
	}
	sparse_table(){ }
	Q query(int l, int r){ // O(1)
		if(l >= r) return identity();
		int d = __lg(r - l);
		return merge(val[d][l], val[d][r - (1 << d)]);
	}
};
int max_op(int x, int y){
	return max(x, y);
}
int max_id(){
	return numeric_limits<int>::min() / 2;
}
//	sparse_table<int, min_op, min_id> st;

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	vector<int> a(n), pref(n + 1);
	for(auto i = 0; i < n; ++ i){
		long long x;
		cin >> x;
		a[i] = __builtin_popcountll(x);
		pref[i + 1] = pref[i] + a[i];
	}
	long long tot = 0;
	array<int, 2> dp{0, 0};
	for(auto x: a){
		++ dp[0];
		if(x & 1){
			swap(dp[0], dp[1]);
		}
		tot += dp[0];
	}
	// now subtract all seq with even count and 2 * max > tot
	sparse_table<int, max_op, max_id> st(a);
	for(auto i = 0; i < n; ++ i){
		for(auto j = i + 1; j <= n && j - i <= 70; ++ j){
			if(pref[j] % 2 == pref[i] % 2 && 2 * st.query(i, j) > pref[j] - pref[i]){
				-- tot;
			}
		}
	}
	cout << tot << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////