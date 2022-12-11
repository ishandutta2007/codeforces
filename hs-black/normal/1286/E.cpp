#include <bits/stdc++.h>
#define ll __int128
#define fi first
#define se second
#define MP make_pair
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

const int N = 605000;
ll las, T;
ll insert(int c, ll v) {
	static int nxt[N], s[N], jmp[N], p[N], tp, n;
	static ll nwans = 0, st[N], ct[N];
	s[++n] = c;
	int nw = n - 1, j = nxt[n - 1];
	while (j) {
		if (s[j + 1] != c) {
			int tc = s[j + 1];
			while (j && s[j + 1] == tc) {
				int l = 1, r = tp, x = n - j;
				while (l <= r) {
					int mid = (l + r) >> 1;
					if (p[mid] < x) l = mid + 1;
					else r = mid - 1;
				}
				nwans -= st[l], --ct[l], j = nxt[j];
			}
		}
		nw = jmp[nw], j = nxt[nw];
	}
	nw = n - 1, j = nxt[n - 1];
	while (j && s[j + 1] != c) nw = jmp[nw], j = nxt[nw];
	if (n > 1 && s[j + 1] == c) ++j;
	jmp[n] = !nxt[j] || s[nxt[j] + 1] != s[j + 1] ? j : jmp[j], nxt[n] = j;
	int tmp = s[1] == s[n]; int mx = s[1] == s[n] ? n : 0;
	while (tp && st[tp] >= v) mx = max(mx, p[tp]), nwans -= st[tp] * ct[tp], tmp += ct[tp], --tp;
	if (tmp) ++tp, st[tp] = v, ct[tp] = tmp, nwans += st[tp] * ct[tp], p[tp] = mx;
	return nwans;
}

int main() {
	for (read(T); T; --T) {
		char opc[3]; int w;
		scanf ("%s", opc); read(w);
		static const int lim = (1 << 30) - 1;
		las += insert((opc[0] - 'a' + las) % 26, (w ^ las) & lim);
		write(las);
	}
	return 0;
}