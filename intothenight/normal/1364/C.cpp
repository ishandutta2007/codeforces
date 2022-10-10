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
	cin >> n;
	vector<int> a(n), used(n + 1);
	for(auto i = 0, c = 0; i < n; ++ i){
		cin >> a[i];
		used[a[i]] = true;
	}
	vector<int> res(n, -1);
	if(a[0]){
		res[0] = 0;
		used[0] = true;
	}
	for(auto i = 1; i < n; ++ i){
		if(a[i - 1] != a[i]){
			res[i] = a[i - 1];
		}
	}
	deque<int> rem;
	for(auto i = 0; i <= n; ++ i){
		if(!used[i]){
			rem.push_back(i);
		}
	}
	for(auto i = n + 1; i <= 2 * n; ++ i){
		rem.push_back(i);
	}
	for(auto i = 0; i < n; ++ i){
		if(!~res[i]){
			if(rem.empty()){
				res[i] = n + 1;
			}
			else{
				res[i] = rem.front();
				rem.pop_front();
			}
		}
	}
	for(auto x: res){
		cout << x << " ";
	}
	cout << "\n";
	return 0;
}

/*
5
0 2 3 3 4
*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////