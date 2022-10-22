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

void NO() {puts("NO");exit(0);}
int main() {
	int x = read(), y = read(), z = read(), a = read(), b = read(), c = read();
	if (a < x) NO(); else a -= x;
	if (a + b < y) NO(); else {if (a < y) y -= a, a = 0, b -= y; else a -= y;}
	if (a + b + c < z) NO(); else puts("YES");
	return 0;
}