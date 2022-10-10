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

array<vector<int>, 2> linearsieve(int n){
	vector<int> lpf(n + 1), prime;
	prime.reserve(n + 1);
	for(int i = 2; i <= n; ++ i){
		if(!lpf[i]) lpf[i] = i, prime.push_back(i);
		for(int j = 0; j < int(prime.size()) && prime[j] <= lpf[i] && i * prime[j] <= n; ++ j){
			lpf[i * prime[j]] = prime[j];
		}
	}
	return {lpf, prime};
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	auto [lpf, prime] = linearsieve(10000000);
	int n;
	cin >> n;
	vector<int> a(n);
	vector<array<int, 2>> res(n);
	for(auto i = 0; i < n; ++ i){
		vector<int> fact;
		int x;
		cin >> x;
		a[i] = x;
		while(x > 1){
			int p = lpf[x];
			fact.push_back(1);
			while(x % p == 0){
				fact.back() *= p;
				x /= p;
			}
		}
		if(int(fact.size()) <= 1){
			res[i][0] = res[i][1] = -1;
		}
		else{
			res[i][0] = fact[0];
			res[i][1] = accumulate(1 + fact.begin(), fact.end(), 1, multiplies{});
		}
	}
	for(auto i = 0; i < 2; ++ i){
		for(auto j = 0; j < n; ++ j){
			cout << res[j][i] << " ";
		}
		cout << "\n";
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