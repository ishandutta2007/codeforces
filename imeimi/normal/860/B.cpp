#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;
typedef long long llong;

int n, l, s;
int sa[1000000];
int _x[1000000];
int _y[1000000];
int cnt[1000000];
int rev[1000000];
int lcp[1000000];
char str[1000001];
int seg[1 << 21];
void init() {
	s = 1;
	while (s < n) s <<= 1;
	for (int i = 1; i < n; ++i) seg[s + i] = lcp[i];
	for (int i = s / 2; i > 0; i >>= 1) {
		for (int j = 0; j < i; ++j) {
			seg[i + j] = min(seg[(i + j) * 2], seg[(i + j) * 2 + 1]);
		}
	}
}

int ls[1000000];
int query(int i, int j) {
	int ret = 1e9;
	int x = min(i, j) + 1, y = max(i, j);
	x += s; y += s;
	while (x <= y) {
		ret = min(ret, seg[x]);
		ret = min(ret, seg[y]);
		x = (x + 1) >> 1;
		y = (y - 1) >> 1;
	}
	return ret;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int i, j, k, m = 26, len, p; char c;
	int *x = _x, *y = _y, *t;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> (str + i * 10);
		str[i * 10 + 9] = '9' + 1;
	}
	n *= 10;
	for (i = 0; i < n; ++i) ++cnt[x[i] = str[i] - '0'];
	for (i = 1; i < m; ++i) cnt[i] += cnt[i - 1];
	for (i = n; i--;) sa[--cnt[x[i]]] = i;
	for (p = 0, len = 1; p + 1 < n; len <<= 1, m = p + 1) {
		p = 0;
		for (i = n - len; i < n; ++i) y[p++] = i;
		for (i = 0; i < n; ++i) if (len <= sa[i]) y[p++] = sa[i] - len;
		for (i = 0; i < m; ++i) cnt[i] = 0;
		for (i = 0; i < n; ++i) ++cnt[x[y[i]]];
		for (i = 1; i < m; ++i) cnt[i] += cnt[i - 1];
		for (i = n; i--;) sa[--cnt[x[y[i]]]] = y[i];
		t = x; x = y; y = t;
		p = 0; x[sa[0]] = 0;
		for (i = 0; i + 1 < n; ++i) {
			if (n <= sa[i] + len) ++p;
			else if (n <= sa[i + 1] + len) ++p;
			else if (y[sa[i]] != y[sa[i + 1]]) ++p;
			else if (y[sa[i] + len] != y[sa[i + 1] + len]) ++p;
			x[sa[i + 1]] = p;
		}
	}
	for (i = 0; i < n; ++i) rev[sa[i]] = i;
	for (i = 0, j = 0, k = 0; i < n; lcp[rev[i++]] = k) {
		k = max(0, k - 1);
		if (rev[i])
			j = sa[rev[i] - 1];
		else
			continue;
		while (str[i + k] == str[j + k]) ++k;
	}

	for (int i = 0; i < n; ++i) {
		if (i % 10 == 9) continue;
		int j = rev[i];
		int tmp = 9 - i % 10;
		for (; j > 0; --j) {
			tmp = min(tmp, lcp[j]);
			if (sa[j - 1] / 10 != i / 10) break;
		}
		if (j == 0) tmp = 0;
		j = rev[i];
		ls[i] = tmp;
		tmp = 9 - i % 10;
		for (++j; j < n; ++j) {
			tmp = min(tmp, lcp[j]);
			if (sa[j] / 10 != i / 10) break;
		}
		if (j == n) tmp = 0;
		ls[i] = max(ls[i], tmp) + 1;
	}
	for (int i = 0; i < n; i += 10) {
		int idx = 0;
		for (int j = 1; j < 9; ++j) {
			if (9 - j < ls[i + j]) continue;
			if (ls[i + j] < ls[i + idx]) {
				idx = j;
			}
		}
		for (int j = 0; j < min(ls[i + idx], 9 - idx); ++j) {
			putc(str[i + idx + j], stdout);
		}
		putc('\n', stdout);
	}
	return 0;
}