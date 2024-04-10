#include <bits/stdc++.h>
using namespace std;
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

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, k;
	cin >> n >> k;
	vector<int> a(n), prev(n, -1), next(n, n);
	vector<int> seen(n, -1);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i], -- a[i];
		prev[i] = seen[a[i]];
		seen[a[i]] = i;
	}
	fill(seen.begin(), seen.end(), n);
	for(auto i = n - 1; i >= 0; -- i){
		next[i] = seen[a[i]];
		seen[a[i]] = i;
	}
	int cl = 0, cr = 0;
	long long ccost = 0;
	auto cost = [&](int l, int r)->long long{
		static int cl = 0, cr = 0;
		static long long ccost = 0;
		while(cr < r){
			if(cl <= prev[cr]){
				ccost += cr - prev[cr];
			}
			++ cr;
		}
		while(l < cl){
			-- cl;
			if(next[cl] < cr){
				ccost += next[cl] - cl;
			}
		}
		while(r < cr){
			-- cr;
			if(cl <= prev[cr]){
				ccost -= cr - prev[cr];
			}
		}
		while(cl < l){
			if(next[cl] < cr){
				ccost -= next[cl] - cl;
			}
			++ cl;
		}
		return ccost;
	};
	vector<long long> dp(n + 1, numeric_limits<long long>::max() / 2);
	dp[0] = 0;
	for(auto x = 1; x <= k; ++ x){
		vector<long long> dp_next(n + 1, numeric_limits<long long>::max() / 2);
		y_combinator([&](auto self, int l, int r, int optl, int optr)->void{
			if(l == r){
				return;
			}
			int m = l + (r - l >> 1);
			pair<long long, int> opt{numeric_limits<long long>::max() / 2, x - 1};
			for(auto i = optl; i < min(optr, m); ++ i){
				ctmin(opt, pair{dp[i] + cost(i, m), i});
			}
			dp_next[m] = opt.first;
			self(l, m, optl, opt.second + 1), self(m + 1, r, opt.second, optr);
		})(x, n + 1, x - 1, n + 1);
		swap(dp, dp_next);
	}
	cout << dp[n] << "\n";
	return 0;
}

/*
dp[k][x]: min cost to split prefix of length x into k segments, k <= x
dp[k][x] = min{k - 1 <= y < x}(dp[k - 1][y] + cost[y][x])
cost is monge
*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////