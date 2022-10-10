#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif
template<class T> T &ctmin(T &x){ return x; }
template<class T, class Head, class ...Tail> T &ctmin(T &x, const Head &h, const Tail &... t){ return ctmin(x = min<T>(x, h), t...); }
template<class T> T &ctmax(T &x){ return x; }
template<class T, class Head, class ...Tail> T &ctmax(T &x, const Head &h, const Tail &... t){ return ctmax(x = max<T>(x, h), t...); }

// Specialization of sparse_table
// Range min query by default. Set cmp = greater for max query
template<class T, class Compare = less<>>
struct range_minmax_query_solver{
	int n;
	vector<vector<T>> data;
	Compare cmp;
	T T_id;
	range_minmax_query_solver(){ }
	// O(n log n)
	range_minmax_query_solver(const vector<T> &a, Compare cmp = less<>(), T T_id = numeric_limits<T>::max()): n((int)a.size()), cmp(cmp), T_id(T_id), data({a}){ // O(n log n)
		for(auto p = 1, i = 1; p << 1 <= n; p <<= 1, ++ i){
			data.emplace_back(n - (p << 1) + 1);
			for(auto j = 0; j < (int)data[i].size(); ++ j) data[i][j] = cmp(data[i - 1][j], data[i - 1][j + p]) ? data[i - 1][j] : data[i - 1][j + p];
		}
	}
	// O(1)
	T query(int l, int r) const{
		assert(0 <= l && l <= r && r <= n);
		if(l == r) return T_id;
		int d = __lg(r - l);
		return cmp(data[d][l], data[d][r - (1 << d)]) ? data[d][l] : data[d][r - (1 << d)];
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	vector<int> a(n);
	vector<vector<int>> pos(n);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i], -- a[i];
		pos[a[i]].push_back(i);
	}
	vector<int> pref(n + 1);
	vector<pair<int, int>> b(n);
	for(auto i = 0; i < n; ++ i){
		b[i] = {-1, i};
	}
	for(auto x = 0; x < n; ++ x){
		if((int)pos[x].size() < 2){
			continue;
		}
		int l = pos[x].front(), r = pos[x].back();
		++ pref[l];
		-- pref[r + 1];
		b[l].first = r;
	}
	range_minmax_query_solver rmq(b, greater<>(), pair{numeric_limits<int>::min(), -1});
	int res = 0;
	for(auto i = 0; i < n; ++ i){
		pref[i + 1] += pref[i];
		res += !!pref[i];
	}
	for(auto i = 0; i < n; ++ i){
		if(!~b[i].first){
			continue;
		}
		res -= 2;
		int left = i, right = b[i].first;
		while(rmq.query(left, right + 1).first > right){
			-- res;
			tie(right, left) = rmq.query(left, right + 1);
		}
		i = right;
	}
	cout << res << "\n";
	return 0;
}

/*
1 3 6 1 3 7 6
*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////