#pragma GCC optimize("Ofast")
#pragma GCC target("avx2,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset; // order_of_key, find_by_order
oset a[3];
ll n=0, k;
int main() {
	 ios::sync_with_stdio(0);
	 cin.tie(0);
	 cout.tie(0);
	 int ks[3];
	 for(int t, i = 0; i < 3; i++)
		 cin >> ks[i];
	 for(int t, i = 0; i < 3; i++) {
		 int k = ks[i];
		 n+=k;
		 while(k--) {
			 cin >> t;
			 a[i].insert(t);
		 }
	 }
	 int ans = (a[1].size()+(a[0].size()-a[0].order_of_key(1))+a[2].order_of_key(1));
	 int cur = ans;
//	 cout << 0 << " " << cur << "\n";
	 for(int i = 1; i <= n; i++) {
		 ans = min(ans, (int)(a[1].size()+(a[0].size()-a[0].order_of_key(i+1))+a[2].order_of_key(i+1)));
		 cur = min(cur, (int)(a[1].size()+(a[0].size()-a[0].order_of_key(i+1))+a[2].order_of_key(i+1)));
		 if(a[1].find(i)!=a[1].end()) cur--;
		 else if(a[0].find(i)==a[0].end()) cur++;
		 ans = min(ans, cur);
//		 cout << i << " " << cur << "\n";
	 }
	 cout << ans;
	 return 0;
}