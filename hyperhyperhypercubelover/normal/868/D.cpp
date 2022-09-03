#include <cstdio>
#include <string>

using namespace std;

struct str {
	string pre, suf;
	int r;
	char a[65536];
} d[202];

str operator +(const str &u, const str &v) {
	str res;
	int i, j, t, tt;
	for (i = 0; i < 65536; i++) res.a[i] = u.a[i] || v.a[i];
	if (u.pre == u.suf) {
		res.pre = u.pre + v.pre;
		if (res.pre.size() > 20) res.pre.resize(20);
	}
	else res.pre = u.pre;
	if (v.pre == v.suf) {
		res.suf = u.suf + v.suf;
		if (res.suf.size() > 20) res.suf = res.suf.substr(res.suf.size() - 20, 20);
	}
	else res.suf = v.suf;
	t = 0;
	for (i = 0; i < 16 && i < u.suf.size(); i++) {
		t |= (u.suf[u.suf.size() - i - 1] & 1) << i;
		tt = t;
		for (j = 0; j < 16 && j < v.pre.size(); j++) {
			tt = tt << 1 | v.pre[j] & 1;
			if (i + j + 2 < 16) res.a[1 << i + j + 2 | tt] = 1;
		}
	}
	for (res.r = 0;; res.r++) {
		for (i = 0; i < 1 << res.r && res.a[1 << res.r | i]; i++);
		if (i < 1 << res.r) break;
	}
	return res;
}

char tt[256];

int main() {
	int i, j, k, n, m, t;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%s", tt);
		d[i].pre = d[i].suf = tt;
		d[i].a[1] = 1;
		for (j = 0; j < d[i].pre.size(); j++) for (k = t = 0; k < 15 && j + k < d[i].pre.size(); k++) {
			t = t << 1 | d[i].pre[j + k] & 1;
			d[i].a[1 << k + 1 | t] = 1;
		}
	}
	scanf("%d", &m);
	for (k = 1; k <= m; k++) {
		scanf("%d%d", &i, &j);
		d[n + k] = d[i] + d[j];
		printf("%d\n", d[n + k].r - 1);
	}
	return 0;
}