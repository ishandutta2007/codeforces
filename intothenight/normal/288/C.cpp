#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
mt19937 rng(high_resolution_clock::now().time_since_epoch().count());
mt19937_64 rngll(high_resolution_clock::now().time_since_epoch().count());
template<typename T> T ctmax(T &x, const T &y){ return x = max(x, y); }
template<typename T> T ctmin(T &x, const T &y){ return x = min(x, y); }
template<typename T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	long long res = 0;
	vector<int> mapto(n + 1);
	function<void(int)> solve = [&](int x){
		if(!x){
			return;
		}
		int tot = (1 << __lg(x) + 1) - 1;
		for(int i = tot - x; i <= x; ++ i){
			res += tot;
			mapto[i] = tot - i;
		}
		if(tot != x){
			solve(tot - x - 1);
		}
	};
	solve(n);
	cout << res << "\n";
	copy(mapto.begin(), mapto.end(), ostream_iterator<int>(cout, " "));
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////