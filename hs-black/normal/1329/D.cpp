#include <bits/stdc++.h>
#define ll long long
using namespace std;
template <typename T>
void read(T &x) {
	x = 0; char c = getchar(); int f = 0;
	for (; !isdigit(c); c = getchar())
		f |= c == '-';
	for (; isdigit(c); c = getchar())
		x = x * 10 + (c ^ '0');
	if (f) x = -x;
}

template <typename T>
void write(T x, char ed = '\n') {
	if (x < 0) putchar('-'), x = -x;
	static short st[30], tp;
	do st[++tp] = x % 10, x /= 10; while (x);
	while (tp) putchar(st[tp--] | '0');
	putchar(ed);
}

const int N = 200005;
int T, st[N], ct[55], pos[N], tp, n;
char s[N];
int main() {
	for (read(T); T; --T) {
		scanf ("%s", s + 1), n = strlen(s + 1);
		memset(ct, 0, sizeof(ct)), tp = 0;
		s[n + 1] = -1;
		for (int i = 1;i <= n; ++i) s[i] -= 'a';
		for (int i = 1;i <= n; ++i) {
			if (s[i] == s[i+1]) st[++tp] = i, ct[s[i]]++;
		}
		int res = 0, fl = 0;
		for (int i = 0;i < 26; ++i) res = max(res, ct[i]);
		write(max((tp + 1) >> 1, res) + 1);
		int tnw = min(tp, 1), del = 0; st[tnw] = pos[tnw] = st[1];
		if (res * 2 > tp) fl = 1;
		for (int i = 2;i <= tp; ++i) {
			int c1 = s[st[tnw]], c2 = s[st[i]];
			if (!tnw || c1 == c2) { st[++tnw] = st[i], pos[tnw] = st[i] - del; continue; }
			int jzp = 0;
			if (fl) jzp = ct[c1] == res || ct[c2] == res;
			else {
				int tmx = 0;
				--ct[c1], --ct[c2];
				for (int i = 0;i < 26; ++i) tmx = max(tmx, ct[i]);
				jzp = tmx * 2 - 1 <= (tnw - 1 + tp - i);
				++ct[c1], ++ct[c2];
			}
			if (!jzp) { st[++tnw] = st[i], pos[tnw] = st[i] - del; continue; }
			int l, r;
			write(l = pos[tnw] + 1, ' '), write(r = st[i] - del);
			del += r - l + 1, --ct[c1], --ct[c2], res = 0, --tnw;
			for (int i = 0;i < 26; ++i) res = max(res, ct[i]);
		}
		pos[++tnw] = n - del, del = 0;
		for (int i = 1;i <= tnw; ++i)
			write(1, ' '), write(pos[i] - del), del += pos[i] - del;
	}
	return 0;
}