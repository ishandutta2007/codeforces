#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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
const int maxn = 1e6 + 30;
using oset = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
int n, k, a[maxn];
vector<vi> cyc;
vi cl;
bitset<maxn> vis, dp;
vi items;
void add(int x, int cnt) {
	int L = 1;
	while((L<<1) <= cnt) L<<=1;
	for(int k = L; k>>=1;)
		items.pb(x*k);
	items.pb(x*(cnt-L+1));
}
bool bp() {
	dp.set(0);
	for(auto i : items) {
		dp|=dp<<i;
	}
	return !dp.test(k);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) {
		if(vis[i]) continue;
		int t = i;
		cyc.pb({});
		while(!vis[t]) {
			vis[t] = 1;
			cyc.back().pb(t);
			t = a[t];
		}
		cl.pb(cyc.back().size());
	}
	sort(all(cl));
	cl.pb(-1);
	int cnt = 1;
	for(int i = 1; i < cl.size(); i++) {
		if(cl[i]==cl[i-1]) cnt++;
		else add(cl[i-1], cnt), cnt = 1;
	}
	int mn = k+bp(), mx = 0;
	int t = 0, o = 0;
	for(auto &i : cyc) {
		t += i.size()/2;
		o += i.size()&1;
	}
	int tmp = min(k, t);
	mx += tmp<<1;
	tmp = min(k-tmp, o);
	mx += tmp;
	cout << mn << " " << mx << "\n";
}