#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int, int>;
using vpi = vector<pi>;
using oset = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
void solve() {
	int n;
	cin >> n;
	vi a;
	a.resize(n);
	ll os = 0;
	for(auto & i : a) cin >> i, os += i;
	ll l = 0, sm = 0, ss = LLONG_MIN;
	for(int i = 0; i <n ; i++) {
//		cin >> a[i];//
		if(sm<=0) l = i;
		sm = max(0ll, sm);
		sm += a[i];
		if(i==n-1&&l==0) sm -= a[l++];
		ss =max(ss, sm);
	}
//	cout << os <<  " " << ss << "\n";
	cout << (os>ss?"YES":"NO") << "\n";
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;cin >> n;while(n--) solve();

}