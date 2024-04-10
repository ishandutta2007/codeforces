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
	int a, b, qq;
	cin >> a >> b >> qq;
	vector<int> pre(a * b + 1);
	for(auto i = 1; i <= a * b; ++ i){
		pre[i] = (i - 1) % a % b != (i - 1) % b % a;
	}
	for(auto i = 1; i <= a * b; ++ i){
		pre[i] += pre[i - 1];
	}
	auto get = [&](long long x){
		return x / (a * b) * pre.back() + pre[x % (a * b)];
	};
	while(qq --){
		long long l, r;
		cin >> l >> r, ++ r;
		cout << get(r) - get(l) << " ";
	}
	cout << "\n";
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