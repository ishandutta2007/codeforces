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

inline ll read() {
	ll x = 0; int f = 1, c = getchar();
	for (;!isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = (x<<3) + (x<<1) + (c^48);
	return x * f;
}

int cnt;
int ask1(int x) {++ cnt;printf("? %d\n", x);fflush(stdout);return read();}
int ask2(int x) {++ cnt;printf("> %d\n", x);fflush(stdout);return read();}

int main() {
	int n = read();
	int lb = 0, rb = 1e9;
	while (lb < rb) {
		int md = (lb + rb) >> 1;
		if (ask2(md)) lb = md + 1;
		else rb = md;
	}
	int mx = lb;
	mt19937 rnd((ull) (new char));
	int lft = 60 - cnt;
	int ans = 0, mn = INF;
	if (n <= lft) {
		for (int i = 1; i <= n; ++ i) {
			int y = ask1(i);
			if (y < mn) mn = y;
		}
		ans = (mx - mn) / (n - 1);
	}
	else {
		for (int i = 1; i <= lft; ++ i) {
			int x = (rnd() % (n / lft)) + (i - 1) * (n / lft) + 1;
			int y = ask1(x);
			ans = __gcd(mx - y, ans);
		}
	}
	printf("! %d %d\n", mx - (n - 1) * ans, ans);fflush(stdout);
	return 0;
}