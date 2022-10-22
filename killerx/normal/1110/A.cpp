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

int main() {
	int b = read() % 2, n = read();
	int ans = 0;
	for (int i = 0; i < n; ++ i) {
		int a = read() % 2;
		if (i + 1 < n) ans = (ans + a * b) % 2;
		else ans = (ans + a) % 2;
	}
	puts(ans ? "odd" : "even");
	return 0;
}