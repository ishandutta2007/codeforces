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

const int N = 200050;
int T, n, x, m, s[N];
int main() {
	for (read(T); T; --T) {
		read(n), read(m), read(x); priority_queue<pair<int, int> > q;
		for (int i = 1;i <= n; ++i) read(s[i]);
		for (int i = 1;i <= m; ++i) q.push(make_pair(0, i));
		puts("YES");
		for (int i = 1;i <= n; ++i) {
			int x = q.top().first, y = q.top().second; q.pop();
			q.push(make_pair(x - s[i], y)), write(y, ' ');
		}
	}
	return 0;
}