#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }

template<class F>
struct y_combinator_result{
	F f;
	template<class T> explicit y_combinator_result(T &&f): f(forward<T>(f)){ }
	template<class ...Args> decltype(auto) operator()(Args &&...args){ return f(ref(*this), forward<Args>(args)...); }
};
template<class F>
decltype(auto) y_combinator(F &&f){
	return y_combinator_result<decay_t<F>>(forward<F>(f));
}

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
	vector<pair<vector<int>, int>> g;
	for(auto i = 0; i < n; ++ i){
		int x;
		cin >> x;
		a[i] = x;
		if(x == 0){
			g.push_back({{}, 0});
		}
		else{
			vector<int> block{__builtin_ctz(x), 1};
			for(auto i = __builtin_ctz(x) + 1, lg = __lg(x); i <= lg; ){
				int j = i;
				while(j <= lg && (x >> i & 1) == (x >> j & 1)){
					++ j;
				}
				block.push_back({j - i});
				i = j;
			}
			g.push_back({block, i});
		}
	}
	array<int, 3> res{numeric_limits<int>::min()};
	ranges::sort(g);
	vector<array<int, 2>> init((int)size(g));
	for(auto i = 0; i < (int)size(g); ++ i){
		auto &[block, ind] = g[i];
		init[i] = {(int)size(block), ind};
	}
	range_minmax_query_solver rmaxq(init, greater<>(), array{numeric_limits<int>::min() / 2, -1});
	y_combinator([&](auto self, int l, int r, int id)->void{
		if((int)size(g[l].first) == id){
			auto q = rmaxq.query(l + 1, r);
			ctmax(res, array{q[0] - max(id, 1), q[1], g[l].second});
			++ l;
		}
		if(r - l <= 1){
			return;
		}
		for(auto nl = l; nl < r; ){
			int nr = nl;
			while(nr < r && g[nl].first[id] == g[nr].first[id]){
				++ nr;
			}
			auto q1 = rmaxq.query(nl, nr), q2 = rmaxq.query(nr, r);
			ctmax(res, array{q1[0] + q2[0] - 2 * max(id, 1), q1[1], q2[1]});
			self(nl, nr, id + 1);
			nl = nr;
		}
	})(0, (int)size(g), 0);
	cout << res[1] + 1 << " " << res[2] + 1 << " " << res[0] << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////