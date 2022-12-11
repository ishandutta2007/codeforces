#include <bits/stdc++.h>
#define ok printf ("ok on line#%d\n", __LINE__)
#define ll long long
using namespace std;
template <typename T>
void read(T &x) {
	x = 0; char c = getchar(); int f = 0;
	for (; !isdigit(c); c = getchar())
		f |= c == '-';
	for (; isdigit(c);  c = getchar())
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

const int N = 505000;
ll n, k, ans;
char A[N], B[N];
int main() {
	read(n), read(k);
	scanf ("%s%s", A + 1, B + 1);
	ll res = 1;
	for (int i = 1;i <= n; ++i) {
		res <<= 1, res -= (A[i] == 'b') + (B[i] == 'a');
		ans += min(res, k), res = min(res, k + 5);
	}
	write(ans);
	return 0;
}