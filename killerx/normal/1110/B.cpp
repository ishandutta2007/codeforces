// Code by Denverjin.
#include <bits/stdc++.h>
using namespace std;

using ld = double;
using ll = long long;
using ull = unsigned long long;
const int INF = 1 << 30;
const ll LINF = 1LL << 60;

const int SZ = 1 << 13;
char buff[SZ], *pos = buff + SZ - 1;
#define getchar() (++ pos == buff + SZ ? fread(pos = buff, 1, SZ, stdin), *pos : *pos)

inline ll read() {
	ll x = 0; int f = 1, c = getchar();
	for (;!isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = (x<<3) + (x<<1) + (c^48);
	return x * f;
}

int n, m, k;
int b[1 << 17];

int main() {
	n = read(), m = read(), k = read();
	for (int i = 0; i < n; ++ i) b[i] = read();
	int ans = b[n - 1] - b[0] + 1;
	for (int i = 0; i + 1 < n; ++ i) b[i] = b[i + 1] - b[i] - 1;
	sort(b, b + n - 1);
	reverse(b, b + n - 1);
	for (int i = 0; i + 1 < k; ++ i) ans -= b[i];
	printf("%d\n", ans);
	return 0;
}