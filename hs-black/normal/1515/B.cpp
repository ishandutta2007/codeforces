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
int T, n, x, s[N];
int main() {
	for (read(T); T; --T) {
		read(n);
		if (n % 2 != 0) puts("NO");
		else {
			n /= 2;
			int x = sqrt(n);
			if (x * x == n) puts("YES");
			else {
				x = sqrt(n / 2);
				if (x * x * 2 == n) puts("YES");
				else puts("NO");
			} 
		}
	}
	return 0;
}