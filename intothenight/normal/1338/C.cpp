#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/rope>
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
mt19937 rng(high_resolution_clock::now().time_since_epoch().count());
mt19937_64 rngll(high_resolution_clock::now().time_since_epoch().count());
template<typename T> T ctmax(T &x, const T &y){ return x = max(x, y); }
template<typename T> T ctmin(T &x, const T &y){ return x = min(x, y); }
template<typename T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void SOLVE(){
	long long n;
	cin >> n;
	int base_digit = __lg(n) / 2 * 2;
	long long base = 1LL << __lg(n) / 2 * 2;
	int rem = (n - 1) % 3;
	n = (n - base - rem) / 3;
	static vector<vector<int>> ORDER{{0, 1, 2, 3}, {0, 2, 3, 1}, {0, 3, 1, 2}};
	vector<int> &ord = ORDER[rem];
	long long res = base * (rem + 1);
	long long low = base, high = base * 2;
	while(base > 1){
		long long t = base >> 2;
		res += t * ord[n % (4 * t) / t];
		base = t;
	}
	cout << res << "\n";
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int ttt;
	cin >> ttt;
	while(ttt --){
		SOLVE();
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