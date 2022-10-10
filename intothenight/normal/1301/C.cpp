#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rngll(chrono::steady_clock::now().time_since_epoch().count());
template<typename T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
 
 
int main(){
	cin.tie(0)->sync_with_stdio(0);
	int tt;
	cin >> tt;
	while(tt --){
		int n, m;
		cin >> n >> m;
		long long res = 1LL * n * (n + 1) / 2;
		if(m == 0){
			cout << "0\n";
		}
		else if(m <= n / 2){
			n -= m;
			int q = n / (m + 1), r = n % (m + 1);
			cout << res - 1LL * (q + 1) * (q + 2) / 2 * r - 1LL * q * (q + 1) / 2 * (m + 1 - r) << "\n";
		}
		else{
			cout << res - (n - m) << "\n";
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