#pragma GCC optimize("Ofast")
#pragma GCC optimize("avx,avx2,sse,sse2,fma")
#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long ;
using vi = vector<ll>;
using pi = pair<ll, ll>;
const int maxn = 2e5 + 33;
using oset = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
ll find(ll x, ll n) {
	if(x%2==1) {
		return (x+1)/2;
	}
	ll on = n;
	n/=2;
	x/=2;
	if(on%2==1) {
		x--;
		if(x==0) x+=n;
	}
	return (on-n) + find(x, n);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n, q, x;
	cin >> n >> q;
	while(q--) cin >> x,
	cout << find(x, n)<<"\n";
}