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
	const int mx = 7000;
	vector<int> lpf(mx + 1), prime, mobius(mx + 1);
	for(auto i = 2; i <= mx; ++ i){
		if(!lpf[i]) lpf[i] = i, prime.push_back(i);
		for(int j = 0; j < int(prime.size()) && prime[j] <= lpf[i] && i * prime[j] <= mx; ++ j){
			lpf[i * prime[j]] = prime[j];
		}
	}
	mobius[1] = 1;
	for(auto i = 2; i <= mx; ++ i){
		if(i / lpf[i] % lpf[i]){
			mobius[i] = -mobius[i / lpf[i]];
		}
	}
	int n, qq;
	cin >> n >> qq;
	vector<bitset<mx + 1>> a(n), div(mx + 1), pie(mx + 1);
	for(auto x = 1; x <= mx; ++ x){
		for(auto y = x; y <= mx; y += x){
			div[y].set(x);
		}
		for(auto d = 1; x * d <= mx; ++ d){
			if(mobius[d]){
				pie[x].set(x * d);
			}
		}
	}
	while(qq --){
		int type;
		cin >> type;
		if(type == 1){
			int x, u;
			cin >> x >> u, -- x;
			a[x] = div[u];
		}
		else if(type == 2){
			int x, y, z;
			cin >> x >> y >> z, -- x, -- y, -- z;
			a[x] = a[y] ^ a[z];
		}
		else if(type == 3){
			int x, y, z;
			cin >> x >> y >> z, -- x, -- y, -- z;
			a[x] = a[y] & a[z];
		}
		else{
			int x, u;
			cin >> x >> u, -- x;
			cout << ((a[x] & pie[u]).count() & 1);
		}
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