#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int N = 200005;
const int INF = 1e9;

int n;
int g[N], s[N], h[N];
pii seg[N<<2];

inline pii comb(pii a, pii b) {
	return {min(a.first, b.first), min(a.second, b.second)};
}
void build(int id=1, int l=0, int r=n) {
	seg[id] = {INF, INF};
	if (r-l < 2)
		return;
	int mid = (l+r) >> 1;
	build(id<<1, l, mid);
	build(id<<1|1, mid, r);
}
void modify(int x, int id=1, int l=0, int r=n) {
	if (r-l < 2) {
		seg[id] = {h[x] - x, h[x] + x};
		return;
	}
	int mid = (l+r) >> 1;
	if (x < mid) modify(x, id<<1, l, mid);
	else modify(x, id<<1|1, mid, r);
	seg[id] = comb(seg[id<<1], seg[id<<1|1]);
}
pii query(int ql, int qr, int id=1, int l=0, int r=n) {
	if (ql>=r || l>=qr)
		return {INF, INF};
	if (ql<=l && r<=qr)
		return seg[id];
	int mid = (l+r) >> 1;
	return comb(query(ql, qr, id<<1, l, mid), query(ql, qr, id<<1|1, mid, r));
}

int p[N];
bool cmp(int i, int j) { return s[i]+g[i] < s[j]+g[j]; }

int main() {
	scanf("%d", &n);
	int mi = 0;
	for (int i=0; i<n; i++) {
		p[i] = i;
		scanf("%d%d", s+i, g+i);
	}
	build();
	sort(p, p+n, cmp);

	int id = p[0];
	h[id] = g[id] + s[id];
	ll ans = g[id];
	modify(id);
	for (int i=1; i<n; i++) {
		int id = p[i];
		h[id] = s[id] + g[id];
		h[id] = min(h[id], query(id, n).second - id);
		h[id] = min(h[id], query(0, id+1).first + id);
		if (h[id] < s[id]) {
			cout << -1 << endl;
			return 0;
		}
		// cout << id<<": " << h[id] << "," <<s[id] << endl;
		ans += h[id] - s[id];
		modify(id);
	}
	printf("%lld\n", ans);
	for (int i=0; i<n; i++) {
		printf("%d%c", h[i], " \n"[i==n-1]);
	}

	return 0;
}