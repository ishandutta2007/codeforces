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
	int k = __lg(n);
	vector<int> res(k);
	for(auto i = 0; i < k; ++ i){
		res[i] = 1 << i;
	}
	int cur = (1 << k + 1) - 1;
	if(cur - n <= res.back()){
		res.back() -= cur - n;
	}
	else if(cur - n & 1){
		*next(res.rbegin()) -= cur - n - res.back() + 1 >> 1;
		res.back() = 1;
	}
	else{
		*next(res.rbegin()) -= cur - n - res.back() >> 1;
		res.back() = 0;
	}
	cout << k << "\n";
	for(auto x: res){
		cout << x << " ";
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