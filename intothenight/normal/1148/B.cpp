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
	int n, m, ta, tb, k;
	cin >> n >> m >> ta >> tb >> k;
	if(k >= min(n, m)){
		cout << -1;
		return 0;
	}
	vector<int> a(n), b(m);
	copy_n(istream_iterator<int>(cin), n, a.begin());
	copy_n(istream_iterator<int>(cin), m, b.begin());
	long long res = 0;
	for(int i = 0; i <= k; ++ i){ // cancel first i from A, and next (k-i) from B
		int j = lower_bound(b.begin(), b.end(), a[i] + ta) - b.begin();
		if(m - j <= k - i){
			cout << -1;
			return 0;
		}
		ctmax(res, 0LL + b[j + k - i] + tb);
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