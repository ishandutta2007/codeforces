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

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	vector<vector<int>> c(n, vector<int>(n));
	vector<vector<long long>> pref(n + 1, vector<long long>(n + 1));
	for(auto i = 0; i < n; ++ i){
		copy_n(istream_iterator<int>(cin), n, c[i].begin());
		for(auto j = 0; j < n; ++ j){
			pref[i + 1][j + 1] = pref[i + 1][j] + pref[i][j + 1] - pref[i][j] + c[i][j];
		}
	}
	auto eval = [&](int l, int r)->long long{
		assert(0 <= l && l <= r && r <= n);
		return pref[r][l] - pref[l][l] + pref[r][n] - pref[r][r] - pref[l][n] + pref[l][r];
	};
	vector<vector<pair<long long, int>>> dp(n + 1, vector<pair<long long, int>>(n + 1, {numeric_limits<long long>::max() / 10, -1}));
	for(auto l = 0; l <= n; ++ l){
		dp[l][l] = {0, -1};
	}
	for(auto len = 1; len <= n; ++ len){
		for(auto l = 0; l + len <= n; ++ l){
			int r = l + len;
			long long base = eval(l, r);
			for(auto root = l; root < r; ++ root){
				ctmin(dp[l][r], pair{dp[l][root].first + dp[root + 1][r].first + base + eval(l, root) + eval(root + 1, r), root});
			}
		}
	}
	vector<int> res(n);
	y_combinator([&](auto self, int l, int r)->void{
		int root = dp[l][r].second;
		if(l < root){
			res[dp[l][root].second] = root + 1;
			self(l, root);
		}
		if(root + 1 < r){
			res[dp[root + 1][r].second] = root + 1;
			self(root + 1, r);
		}
	})(0, n);
	ranges::copy(res, ostream_iterator<int>(cout, " "));
	cout << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////