#include <bits/stdc++.h>

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

typedef long long ll;

const int mxn = 1e6 + 5;

int n, m;
ll k;
int a[mxn], b[mxn];
int go[mxn];
std::vector <int> chain[mxn];
int occ[mxn][2];
bool vis[mxn];

ll calc(ll tim) {
	ll ans = 0;
	rep(i, n) {
		ll tms = tim / n + (tim % n > i);
		int id = occ[b[i]][0];
		int st = occ[b[i]][1];
		int len = chain[id].size();
		ll ful = tms / len;
		int oth = tms % len;
		if (occ[a[i]][0] != id) ans += tms;
		else {
			ans += ful * (len - 1);
			ans += oth - ((occ[a[i]][1] - st + len) % len < oth);
		}
	}
	return ans;
}

char buf[1 << 20], *pos = buf + (1 << 20);

char gc() {
	if (pos == buf + (1 << 20))
		fread(pos = buf, 1, 1 << 20, stdin);
	return *pos ++;
}

template <typename T> void read(T &x) {
	x = 0;
	char ch = gc();
	while (ch <= 32) ch = gc();
	while (ch > 32) x = x * 10 + ch - '0', ch = gc();
}

int main() {
	read(n); read(m); read(k);
	rep(i, n) read(a[i]);
	rep(i, m) read(b[i]);
//	scanf("%d %d %lld", &n, &m, &k);
//	rep(i, n) scanf("%d", &a[i]);
//	rep(i, m) scanf("%d", &b[i]);
	if (n > m) {
		std::swap(n, m);
		rep(i, mxn) std::swap(a[i], b[i]);
	}
	rep(i, m) go[i] = (i + n) % m;
	memset(occ, -1, sizeof(occ));
	rep(i, m) if (!vis[i]) {
		int u = i;
		do {
			vis[u] = 1;
			chain[i].push_back(u);
			u = go[u];
		} while (u != i);
		rep(j, chain[i].size()) {
			occ[b[chain[i][j]]][0] = i;
			occ[b[chain[i][j]]][1] = j;
		}
	}
	ll lb = 0, rb = 4e18;
	while (lb < rb) {
		ll md = (lb + rb) >> 1;
		if (calc(md) >= k) rb = md;
		else lb = md + 1;
	}
	printf("%lld\n", lb);
	return 0;
}