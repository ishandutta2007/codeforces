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
	int n;
	cin >> n;
	vector<pair<long long, long long>> a(n);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i].first >> a[i].second;
	}
	long long sum = 0;
	for(auto i = 0; i < n; ++ i){
		sum += max(a[i].first - a[(i + n - 1) % n].second, 0LL);
	}
	long long res = numeric_limits<long long>::max();
	for(auto i = 0; i < n; ++ i){
		ctmin(res, sum - max(a[i].first - a[(i + n - 1) % n].second, 0LL) + a[i].first);
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