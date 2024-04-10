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
	vector<pair<long long, int>> a(n); // mask, val
	long long tot = 0;
	for(int i = 0; i < n; ++ i){
		cin >> a[i].second >> a[i].first;
		tot += a[i].second;
	}
	tot /= abs(tot);
	sort(a.begin(), a.end());
	long long res = 0;
	const int mx = 62;
	for(int bit = 0; bit < mx; ++ bit){
		static int i = 0;
		int j = i;
		while(j < n && a[j].first < 1LL << bit + 1){
			++ j;
		}
		long long sum = 0;
		for(int k = i; k < j; ++ k){
			if(__builtin_popcountll(res & a[k].first) & 1){
				sum -= a[k].second;
			}
			else{
				sum += a[k].second;
			}
		}
		if(sum * tot > 0){
			res |= 1LL << bit;
		}
		i = j;
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