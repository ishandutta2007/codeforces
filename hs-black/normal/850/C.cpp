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
	static short st[30], tp; 
	if (x < 0) putchar('-'), x = -x;
	do st[++tp] = x % 10, x /= 10; while (x);
	while (tp) putchar(st[tp--] | '0');
	putchar(ed);
}

int vis[50], n;
map<int, int> nm, mp;
int calc(int s) {
	if (nm.count(s)) return nm[s];
	for (int i = 1;1 << i <= s; ++i)
		calc((s >> i) | (s & ((1 << i) - 1)));
	memset(vis, 0, sizeof(vis));
	for (int i = 1;1 << i <= s; ++i)
		vis[calc((s >> i) | (s & ((1 << i) - 1)))] = 1;
	int x = 0;
	while (vis[x]) ++x;
	return nm[s] = x;
}

int main() {
	read(n), nm[1] = 0;
	for (int i = 1, x;i <= n; ++i) {
		read(x);
		for (int j = 2;j * j <= x; ++j) if (x % j == 0) {
			int s = 2; x /= j;
			while (x % j == 0) s <<= 1, x /= j;
			mp[j] |= s;
		}
		if (x != 1) mp[x] |= 2;
	}
	int nim = 0;
	for (auto t: mp) nim ^= calc(t.second);
	puts(nim ? "Mojtaba" : "Arpa");
	return 0;
}