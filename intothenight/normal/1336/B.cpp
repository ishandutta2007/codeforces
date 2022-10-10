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
	vector<int> n(3);
	for(auto i = 0; i < 3; ++ i){
		cin >> n[i];
	}
	vector<vector<int>> a(3);
	for(auto i = 0; i < 3; ++ i){
		a[i].resize(n[i]);
		for(auto j = 0; j < n[i]; ++ j){
			cin >> a[i][j];
		}
		sort(a[i].begin(), a[i].end());
	}
	vector<int> ord{0, 1, 2};
	long long res = numeric_limits<long long>::max();
	auto sq = [&](int d){
		return 1LL * d * d;
	};
	do{
		for(auto x: a[ord[0]]){
			auto it1 = lower_bound(a[ord[1]].begin(), a[ord[1]].end(), x);
			if(it1 != a[ord[1]].end()){
				int z = *it1;
				auto it2 = lower_bound(a[ord[2]].begin(), a[ord[2]].end(), x + z >> 1);
				if(it2 != a[ord[2]].end()){
					int y = *it2;
					ctmin(res, sq(x - y) + sq(y - z) + sq(z - x));
				}
				if(it2 != a[ord[2]].begin()){
					int y = *prev(it2);
					ctmin(res, sq(x - y) + sq(y - z) + sq(z - x));
				}
			}
		}
	}while(next_permutation(ord.begin(), ord.end()));
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