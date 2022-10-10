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
	int n;
	long long x;
	cin >> n >> x;
	vector<int> d(n);
	for(auto i = 0; i < n; ++ i){
		cin >> d[i];
	}
	vector<long long> pref(2 * n + 1), spref(2 * n + 1);
	for(auto i = 0; i < n; ++ i){
		pref[i + 1] = pref[i] + d[i];
		spref[i + 1] = spref[i] + 1LL * d[i] * (d[i] + 1) / 2;
	}
	for(auto i = n; i < 2 * n; ++ i){
		pref[i + 1] = pref[i] + d[i - n];
		spref[i + 1] = spref[i] + 1LL * d[i - n] * (d[i - n] + 1) / 2;
	}
	long long res = 0;
	for(auto i = 0, j = 0; i < n; ++ i){
		ctmax(j, i);
		while(j < 2 * n && pref[j + 1] - pref[i] <= x){
			++ j;
		}
		long long t = x - (pref[j] - pref[i]);
		ctmax(res, spref[j] - spref[i] + t * (t + 1) / 2);
	}
	for(auto i = 2 * n, j = 2 * n; j > n; -- j){
		ctmin(i, j);
		while(i > 0 && pref[j] - pref[i - 1] <= x){
			-- i;
		}
		long long t = x - (pref[j] - pref[i]);
		int ind = (i - 1 + n) % n;
		ctmax(res, spref[j] - spref[i] + 1LL * d[ind] * (d[ind] + 1) / 2 - 1LL * (d[ind] - t) * (d[ind] - t + 1) / 2);
	}
	cout << res << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////