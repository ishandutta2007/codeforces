#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rngll(chrono::steady_clock::now().time_since_epoch().count());
template<typename T> T ctmax(T &x, const T &y){ return x = max(x, y); }
template<typename T> T ctmin(T &x, const T &y){ return x = min(x, y); }
template<typename T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	int tt;
	cin >> tt;
	while(tt --){
		int n, m;
		cin >> n >> m;
		vector<int> a(n), p(m);
		for(auto &x: a){
			cin >> x;
		}
		vector<int> flag(n);
		for(auto &x: p){
			cin >> x;
			flag[x] = true;
		}
		int pmax = 0;
		bool ok = true;
		for(int i = 0; i < n; ){
			int j = i + 1, cmin = a[i], cmax = a[i];
			while(j < n && flag[j]){
				ctmin(cmin, a[j]);
				ctmax(cmax, a[j]);
				++ j;
			}
			if(pmax > cmin){
				ok = false;
				break;
			}
			pmax = cmax;
			i = j;
		}
		ok ? cout << "YES\n" : cout << "NO\n";
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