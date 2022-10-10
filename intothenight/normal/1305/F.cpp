#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using namespace chrono;
mt19937 rng(high_resolution_clock::now().time_since_epoch().count());
mt19937_64 rngll(high_resolution_clock::now().time_since_epoch().count());
template<typename T> T ctmax(T &x, const T &y){ return x = max(x, y); }
template<typename T> T ctmin(T &x, const T &y){ return x = min(x, y); }
template<typename T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	auto start = high_resolution_clock::now();
	int n;
	cin >> n;
	vector<long long> a(n);
	copy_n(istream_iterator<long long>(cin), n, a.begin());
	int res = numeric_limits<int>::max();
	const long long inf = numeric_limits<long long>::max();
	auto get_rand = [&](int l, int r){
		return rng() % (r - l) + l;
	};
	auto refresh = [&](long long p){
		long long cur = 0;
		for(auto x: a){
			long long u = x % p, v = (p - u) % p;
			if(x < p){
				u = inf;
			}
			ctmin(u, v);
			cur += u;
			if(cur >= res){
				return;
			}
		}
		res = cur;
	};
	refresh(2);
	while(duration<double>(high_resolution_clock::now() - start).count() < 1.5){
		int i = get_rand(0, n - 1), j = get_rand(i + 1, n);
		for(int t = -1; t <= 1; ++ t){
			for(int u = -1; u <= 1; ++ u){
				long long g = gcd(a[i] + t, a[j] + u);
				for(long long p = 2; p * p <= g; ++ p){
					if(g % p == 0){
						refresh(p);
						while(g % p == 0){
							g /= p;
						}
					}
				}
				if(g > 1){
					refresh(g);
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