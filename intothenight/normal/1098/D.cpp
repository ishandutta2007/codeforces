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



int main(){
	cin.tie(0)->sync_with_stdio(0);
	const int n = 30;
	vector<long long> blocksum(n);
	vector<multiset<int>> block(n);
	int q;
	cin >> q;
	int tot = 0;
	while(q --){
		char type;
		int x;
		cin >> type >> x;
		int i = __lg(x);
		if(type == '+'){
			blocksum[i] += x;
			block[i].insert(x);
			++ tot;
		}
		else{
			blocksum[i] -= x;
			block[i].erase(block[i].find(x));
			-- tot;
		}
		long long s = 0;
		int cnt = tot;
		for(auto i = 0; i < n; ++ i){
			if(2 * s < *block[i].begin()){
				-- cnt;
			}
			s += blocksum[i];
		}
		cout << cnt << "\n";
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