#include<bits/stdc++.h>
#define maxn 200000
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vl;
const int mod = 998244353;
int t[maxn * 4 + 16];
int fact[maxn + 1];

int bin_pow(int a, int b) {
	if(b == 0) return 1;
	int res = bin_pow(a, b >> 1);
	res = (ll)res * res % mod;
	if(b & 1) res = (ll)res * a % mod;
	return res;
}
int obr(int a) {
	return bin_pow(a, mod - 2);
}

void update(int now, int l, int r, int pos, int val) {
	if(l == r) {
		t[now] = val;
		return;
	}
	int mid = (l + r) / 2;
	if(mid >= pos) {
		update(now * 2, l, mid, pos, val);
	} else {
		update(now * 2 + 1, mid + 1, r, pos, val);
	}
	t[now] = t[now * 2] + t[now * 2 + 1];
}

int get(int now, int l, int r, int l1, int r1) {
	if(l1 > r || l > r1) return 0;
	if(l1 <= l && r <= r1) return t[now];
	int mid = (l + r) / 2;
	return get(now * 2, l, mid, l1, r1) + get(now * 2 + 1, mid + 1, r, l1, r1);
}



int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	#ifdef _FILE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	fact[0] = 1;
	for(int i = 1; i <= maxn; i++) {
		fact[i] = (ll)fact[i - 1] * i % mod;
	}
	int n, m;
	cin >> n >> m;
	vi a(n), b(m);
	vi am(maxn + 1);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		++am[a[i]];
	}
	int now = 1;
	for(int i = 1; i <= maxn; i++) {
		now = (ll)now * fact[am[i]] % mod;
		update(1, 0, maxn, i, am[i]);
	}
	for(int i = 0; i < m; i++) {
		cin >> b[i];
	}
	int ans = 0;
	int here1 = 1;
	for(int i = 0; i < min(n, m); i++) {
		int here = get(1, 0, maxn, 0, b[i] - 1);
		ans = (ans + (ll)here * fact[n - i - 1] % mod * here1) % mod;
		//cout << ans << '\n';
		here1 = (ll)here1 * am[b[i]] % mod;
		if(am[b[i]] == 0) {
			ans = (ll)ans * obr(now) % mod;
			cout << ans;
			return 0;
		}
		--am[b[i]];
		update(1, 0, maxn, b[i], am[b[i]]);
	}
	ans = (ll)ans * obr(now) % mod;
	if(n < m) ans = (ans + 1) % mod;
	cout << ans;
}