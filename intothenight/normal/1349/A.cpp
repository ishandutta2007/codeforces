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
template<typename T> T ctmax(T &x, const T &y){ return x = max(x, y); }
template<typename T> T ctmin(T &x, const T &y){ return x = min(x, y); }
template<typename T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	map<int, vector<int>> q;
	for(auto i = 0; i < n; ++ i){
		int x;
		cin >> x;
		for(auto p = 2; p * p <= x; ++ p){
			if(x % p == 0){
				int cnt = 0;
				while(x % p == 0){
					x /= p;
					++ cnt;
				}
				q[p].push_back(cnt);
			}
		}
		if(x > 1){
			q[x].push_back(1);
		}
	}
	long long res = 1;
	auto pow = [&](int p, int e){
		int res = 1;
		while(e --){
			res *= p;
		}
		return res;
	};
	for(auto &[p, a]: q){
		sort(a.begin(), a.end());
		if(int(a.size()) <= n - 2){
			continue;
		}
		else if(int(a.size()) == n - 1){
			res *= pow(p, a.front());
		}
		else{
			res *= pow(p, *next(a.begin()));
		}
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