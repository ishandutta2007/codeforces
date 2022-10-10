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



int SOLVE(){
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i];
	}
	for(auto i = 0; i < n; ++ i){
		cin >> b[i];
	}
	if(n & 1 && a[n >> 1] != b[n >> 1]){
		cout << "No\n";
		return 0;
	}
	vector<pair<int, int>> bond_a, bond_b;
	for(auto i = 0; i < n >> 1; ++ i){
		bond_a.push_back(minmax(a[i], a[n - 1 - i]));
		bond_b.push_back(minmax(b[i], b[n - 1 - i]));
	}
	sort(bond_a.begin(), bond_a.end()), sort(bond_b.begin(), bond_b.end());
	bond_a == bond_b ? cout << "Yes\n" : cout << "No\n";
	return 0;
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
1 2 3 4
4 2 3 1
1 3 2 4
3 4 1 2
2 
*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////