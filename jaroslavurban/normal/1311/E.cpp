#ifndef __PROGTEST__
#include <bits/stdc++.h>
using namespace std;
#endif // __PROGTEST__

typedef long long ll;
typedef long double ld;
#define pb(x) push_back(x)
#define ff first
#define ss second
#define vec vector
#define inf pow(2, 63)

bool is_space(ll *arr, ll i){
	ll n_nodes = arr[i];
	ll p = 0;
	while (n_nodes >= pow(2, p)) p++;
	return p <= i;
}

int main(){
	ll t;
	cin >> t;
	for (ll i = 0; i < t; ++i){
		ll n, d;
		cin>>n>>d;
		ll max_dist = n * (n-1) / 2;
		ll n_nodes = n;
		ll min_dist = 0;
		for (ll max_depth = 1; n_nodes > 0; ++max_depth){
			min_dist += min(n_nodes-1, ll(pow(2, max_depth))) * max_depth;
			n_nodes-= pow(2, max_depth);
		}
		if (d > max_dist || d < min_dist){
			cout << "NO" << endl;
		} else{
			cout << "YES" << endl;
			ll n_nodes_at[5000] = {};
			for (ll i = 0; i < n; ++i)
				n_nodes_at[i] = 1;
			ll dist = max_dist;
			for (ll i = n-1; dist != d && i > 1; --i){
				for (ll j = i; dist != d && j > 1 && is_space(n_nodes_at, j-1); --j){
					dist--;
					n_nodes_at[j-1]++;
					n_nodes_at[j]--;
					// cout << is_space(n_nodes_at, j-2) << " " << j-2 <<  endl;
				}
			}
			ll total_nodes[5000] = {};
			total_nodes[0] = 1;
			for (ll i = 1; i < 5000; ++i)
				total_nodes[i] = total_nodes[i-1] + n_nodes_at[i];
			ll cntr = 1;
			ll lay = 1;
			// for (ll i = 0; i < 5000; ++i){
			// 	if (n_nodes_at[i]){
			// 		cout << n_nodes_at[i] << " " << i << endl;
			// 	}
			// }
			while (cntr < n){
				for (ll i = 0; i < n_nodes_at[lay]; ++i){
					cout << total_nodes[lay-1] - i / 2 << " ";
					cntr++;				
				}
				lay++;
			}
			cout << endl;
		}
	}
}