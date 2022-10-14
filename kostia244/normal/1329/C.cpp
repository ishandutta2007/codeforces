#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vpi = vector<pi>;
const int maxn = 1<<21;
int n, m, x, y, a[maxn];
void rem(int v) {
	if(a[v])
		a[v] = max(a[v<<1],a[v<<1|1]), rem(v<<1|(a[v<<1] < a[v<<1|1]));
}
int go(int v) {
	if(a[v] == 0) return 0;
	return 1+go(v<<1|(a[v<<1] < a[v<<1|1]));
}
vi op;
void retarded(int v, int req = y) {
	if(a[v]==0) return;
	while(69) {
		if(go(v)<=req) {
			retarded(v<<1, req-1);
			retarded(v<<1|1, req-1);
			break;
		} else {
			op.pb(v);
			rem(v);
		}
	}
}
void fuckmylife() {
	cin >> x >> y;
	op.clear();
	n = 1<<x, m = 1 << y;
	for(int i = 1; i < n; i++) cin >> a[i];
	retarded(1);
	ll res = 0;
	for(int i = 1; i < n; i++) res += a[i];
	for(int i = 0; i <= n; i++) a[i] = 0;
	cout <<res<< '\n';
	for(auto i : op) cout << i << " "; cout << '\n';
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) fuckmylife();
}