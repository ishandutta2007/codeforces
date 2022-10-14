#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const int maxn = 1<<17;
ll n, a[maxn], f[maxn];
ld ans = 0;
void add(int i, int v) {
	for(; i <= n; i += i&-i) f[i] += v;
}
ll get(int i) {
	ll res = 0;
	for(; i; i -= i&-i) res += f[i];
	return res;
}
ll get(int l, int r) {
	return get(r) - (l-1?get(l-1):0);
}
void clear() {
	memset(f, 0, sizeof f);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	ll pairs = n*1ll*(n+1)/2;
	ll inversions = 0;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		inversions += get(a[i], n);
		add(a[i], 1);
	}
	clear();
	ld exp_added = 0;
	ld exp_removed = 0;
	for(int i = 1; i <= n; i++) {
		exp_added += get(1, a[i]) * (n-i+1) * 0.5 / pairs;
		exp_removed += get(a[i], n) * (n-i+1) * 0.5 / pairs;
		add(a[i], i);
	}
	cout << fixed << setprecision(15) << inversions+exp_added-exp_removed << '\n';
}