#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
#include "ext/rope"
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
mt19937 rng(high_resolution_clock::now().time_since_epoch().count());
mt19937_64 rngll(high_resolution_clock::now().time_since_epoch().count());
#define lambdify(x) [&](auto &&...args){ return x(forward<decltype(args)>(args)...); }
template<typename T, typename U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<typename T, typename U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }
template<typename T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n, a, r, m;
	cin >> n >> a >> r >> m;
	ctmin(m, a + r);
	vector<int> t(n);
	for(auto i = 0; i < n; ++ i){
		cin >> t[i];
	}
	sort(t.begin(), t.end());
	long long tot = accumulate(t.begin(), t.end(), 0LL), res = min(tot * r, (1LL * t.back() * n - tot) * a);
	long long left = 0, right = tot;
	auto calc = [&](long long x, long long y){
		return x <= y ? x * (m - r) + y * r : x * a + y * (m - a);
	};
	for(auto i = 0; i < n - 1; ++ i){
		left += t[i], right -= t[i];
		ctmin(res, calc(1LL * t[i] * (i + 1) - left, right - 1LL * t[i] * (n - i - 1)));
		ctmin(res, calc(1LL * t[i + 1] * (i + 1) - left, right - 1LL * t[i + 1] * (n - i - 1)));
		array<long long, 2> H = {tot / n, tot / n + 1};
		for(auto j = 0; j < 2; ++ j){
			H[j] = clamp<long long>(H[j], t[i], t[i + 1]);
			ctmin(res, calc(H[j] * (i + 1) - left, right - H[j] * (n - i - 1)));
		}
	}
	cout << res << "\n";
	return 0;
}

/*
H = t[i] ~ t[i + 1]

X = H * (i + 1) - left
Y = right - H * (n - i - 1)

if(X <= Y) X * m + (Y - X) * r = X * (m - r) + Y * r
else Y * m + (X - Y) * a =       X * a       + Y * (m - a)

X = Y -> n * H = left + right
*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////