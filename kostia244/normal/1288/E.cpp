#pragma GCC optimize("trapv")
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma,tune=native")
#include<bits/stdc++.h>
#include<bits/extc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
const int maxn = 6e5 + 55;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using namespace __gnu_pbds;
using oset = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
int n, m, a[maxn], pos[maxn], mx[maxn], mn[maxn];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	oset x;
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		mn[i] = mx[i] = i+1;
		a[m+i]=i;
		pos[i]=m+i;
		x.insert(m+i);
	}
	int z = m-1;
	for(int t, i = 0; i < m; i++) {
		cin >> t, t--;
		mx[t] = max(mx[t], 1+(int)x.order_of_key(pos[t]));
		mn[t] = 1;
		x.erase(pos[t]);
		pos[t] = z--;
		x.insert(pos[t]);
	}
	for(int t = 0; t < n; t++) {
		mx[t] = max(mx[t], 1+(int)x.order_of_key(pos[t]));
	}
	for(int i = 0; i < n; i++)
		cout << mn[i] << " " << mx[i] << "\n";
}