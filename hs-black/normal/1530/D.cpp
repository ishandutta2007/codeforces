#include <iostream>
#include <cstring>
#include <cstdio>
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

const int N = 200050;
int T, n, vis[N], tvis[N], st[N], s2[N], s3[N], a[N], tp, t2;
int main() {
	for (read(T); T; T--) {
		read(n), tp = t2 = 0;
		memset(vis, 0, (n + 1) << 2);
		memset(tvis, 0, (n + 1) << 2);
		for (int i = 1;i <= n; ++i) read(a[i]), vis[a[i]] = 1;
		for (int i = 1;i <= n; ++i) if (!vis[i]) st[++tp] = i;
		write(n - tp);
		if (!tp) { for (int i = 1;i <= n; ++i) write(a[i], " \n"[i == n]); continue; }
		if (tp == 1) {
			memset(vis, 0, (n + 1) << 2);
			int to = a[st[tp]];
			for (int i = 1;i <= n; vis[a[i]] = 1, ++i) 
				if (vis[a[i]]) to = a[i];
			for (int i = 1;i <= n; ++i)
				if (a[i] == to && st[tp] != i) { a[i] = st[tp]; break; }
			for (int i = 1;i <= n; ++i) write(a[i], " \n"[i == n]);
			continue;
		}
		memset(vis, 0, (n + 1) << 2);
		for (int i = 1;i <= n; vis[a[i]] = 1, ++i)
			if (vis[a[i]]) s2[++t2] = i;
		for (int i = 1;i <= t2; ++i) 
			if (!vis[s2[i]]) s3[i] = s2[i], tvis[s2[i]] = 1;
		int j = 1;
		for (int i = 1;i <= t2; ++i) if (vis[s2[i]]) {
			while (tvis[st[j]]) ++j;
			s3[i] = st[j++];
		}
		for (int i = 1;i <= t2; ++i)
			a[s2[i]] = s3[i % t2 + 1];
		for (int i = 1;i <= n; ++i)
			write(a[i], " \n"[i == n]);
	}
}