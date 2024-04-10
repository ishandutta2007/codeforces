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
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> a(m);
	for(int i = 0; i < m; ++ i){
		int u, v;
		cin >> u >> v, -- u, -- v;
		if(u > v){
			swap(u, v);
		}
		a[i] = {u, v};
	}
	sort(a.begin(), a.end());
	for(int i = 1, j = 1; i <= n; i = j + 1){
		j = n / (n / i);
		if(j < n && n % j == 0){
			static vector<pair<int, int>> b(m);
			b = a;
			for(auto &[u, v]: b){
				u = (u + j) % n, v = (v + j) % n;
				if(u > v){
					swap(u, v);
				}
			}
			sort(b.begin(), b.end());
			if(a == b){
				cout << "Yes";
				return 0;
			}
		}
	}
	cout << "No";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////