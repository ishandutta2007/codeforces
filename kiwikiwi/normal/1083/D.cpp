#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int maxN = 1234567;
const i64 mod = 1000000007;

struct atom {
	i64 s0, sa, sb, sab;
	i64 taga, tagb;
} t[maxN << 2];

map<int, int> num;
stack<pair<int, int>> seg, sega;
int n, m;
int ocr[maxN], pos[maxN], a[maxN];
i64 s0, s1, ans;

void pushup(int p) {
	t[p].sa = (t[p + p].sa + t[p + p + 1].sa) % mod;
	t[p].sb = (t[p + p].sb + t[p + p + 1].sb) % mod;
	t[p].sab = (t[p + p].sab + t[p + p + 1].sab) % mod;
}

void apply(int p, i64 taga, i64 tagb) {
	t[p].taga = (t[p].taga + taga) % mod;
	t[p].tagb = (t[p].tagb + tagb) % mod;
	t[p].sab = (t[p].sab + taga * t[p].sb + tagb * t[p].sa + taga * tagb * t[p].s0) % mod;
	t[p].sa = (t[p].sa + taga * t[p].s0) % mod;
	t[p].sb = (t[p].sb + tagb * t[p].s0) % mod;
}
void build(int p, int l, int r) {
	t[p].s0 = r - l + 1;
	if (l == r) {
		t[p]. sa = l - 1;
	} else {
		int mid = (l + r) >> 1;
		build(p + p, l, mid);
		build(p + p + 1, mid + 1, r);
		pushup(p);
	}
}

void pushdown(int p) {
	if (t[p].taga || t[p].tagb) {
		apply(p + p, t[p].taga, t[p].tagb);
		apply(p + p + 1, t[p].taga, t[p].tagb);
		t[p].taga = 0;
		t[p].tagb = 0;
	}
}

i64 query(int p, int l, int r, int segl, int segr) {
	if (segl > segr) return 0;
	if (segl == l && segr == r) {
		return t[p].sab;
	} else {
		pushdown(p);
		int mid = (l + r) >> 1;
		return (query(p + p, l, mid, segl, min(mid, segr)) +
		        query(p + p + 1, mid + 1, r, max(mid + 1, segl), segr)) % mod;
	}
}
void modify(int p, int l, int r, int segl, int segr, int taga, int tagb) {
	if (segl == l && segr == r) {
		apply(p, taga, tagb);
	} else {
		pushdown(p);
		int mid = (l + r) >> 1;
		if (segl <= mid) modify(p + p, l, mid, segl, min(mid, segr), taga, tagb);
		if (segr > mid) modify(p + p + 1, mid + 1, r, max(mid + 1, segl), segr, taga, tagb);
		pushup(p);
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		if (!num.count(x)) {
			num[x] = ++m;
		}
		a[i] = num[x];
	}
	for (int i = 1; i <= m; i++) ocr[i] = n + 1;
	for (int i = n; i >= 1; i--) {
		pos[i] = ocr[a[i]];
		ocr[a[i]] = i;
	}
	build(1, 1, n);
	for (int i = 1; i <= m; i++) ocr[i] = 0;
	int posl = 0;
	for (int i = 1; i <= n; i++) {
		int posr = ocr[a[i]];
		posl = max(posl, ocr[a[i]]);
		ocr[a[i]] = i;
		int p = i;
		while (!seg.empty() && seg.top().second > pos[i]) {
			modify(1, 1, n, seg.top().first, p - 1, 0, -seg.top().second);
			p = seg.top().first;
			seg.pop();
		}
		modify(1, 1, n, p, i, 0, pos[i]);
		seg.push(make_pair(p, pos[i]));
		p = i;
		while (!sega.empty() && sega.top().second < posr) {
			modify(1, 1, n, sega.top().first, p - 1, sega.top().second, 0);
			p = sega.top().first;
			sega.pop();
		}
		modify(1, 1, n, p, i, -posr, 0);
		sega.push(make_pair(p, posr));
		modify(1, 1, n, posl + 1, i, 0, -i - 1);
		ans = (ans + query(1, 1, n, posl + 1, i)) % mod;
		modify(1, 1, n, posl + 1, i, 0, i + 1);
	}
	if (ans < 0) ans += mod;
	printf("%lld\n", ans);
}