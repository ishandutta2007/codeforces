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
	int n;
	string a, b;
	cin >> n >> a >> b;
	int res = 0;
	for(auto i = 0; i < (n + 1) / 2; ++ i){
		int j = n - 1 - i;
		map<char, int> q;
		if(n % 2 && i == n / 2){
			if(a[i] != b[i]){
				++ res;
			}
		}
		else{
			++ q[a[i]], ++ q[a[j]], ++ q[b[i]], ++ q[b[j]];
			string odd;
			for(auto &[x, y]: q){
				if(y % 2){
					odd.push_back(x);
				}
			}
			if(!odd.empty()){
				if(a[i] == b[i] || a[i] == b[j] || a[j] == b[i] || a[j] == b[j] || b[i] == b[j]){
					++ res;
				}
				else{
					res += 2;
				}
			}
		}
	}
	cout << res;
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////