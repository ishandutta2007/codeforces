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
	vector<pair<int, int>> a(n);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i].first >> a[i].second;
	}
	for(auto i = 1; i < n; ++ i){
		if(a[i - 1].first > a[i].first || a[i - 1].second > a[i].second || a[i].first - a[i - 1].first < a[i].second - a[i - 1].second){
			cout << "NO\n";
			return;
		}
	}
	for(auto i = 0; i < n; ++ i){
		if(a[i].first < a[i].second){
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
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