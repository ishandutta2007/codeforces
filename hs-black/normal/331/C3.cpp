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

#define MP make_pair
#define fi first
#define se second
unordered_map<ll, pair<ll, ll>> f[20];
pair<ll, ll> solve(int ht, ll n) {
	if (!n) return MP(0, 0);
	if (n < 10) return MP(1, min(0ll, n - ht));
	if (f[ht].count(n)) return f[ht][n];
	ll hbt = 1, ans = 0, tn = n;
	while (n / 10 >= hbt) hbt *= 10;
	while (n > 0) {
		int k = n / hbt;
		pair<ll, ll> tmp = solve(max(ht, k), n - k * hbt);
		n = k * hbt + tmp.se, ans += tmp.fi;
		if (!n) break;
		if (n % hbt == 0) ++ans, n -= max(ht, k);
	}
	return f[ht][tn] = MP(ans, n);
}

ll n;
int main() {
	read(n), write(solve(0, n).first);
	return 0;
}