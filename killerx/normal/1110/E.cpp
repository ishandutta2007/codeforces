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

const int N = 1 << 20;
int n, c[N], t[N];
map <int, int> delta;
void no() {puts("No"); exit(0);}

int main() {
	n = read();
	for (int i = 0; i < n; ++ i) c[i] = read();
	for (int i = 0; i < n; ++ i) t[i] = read();
	for (int i = 1; i < n; ++ i) delta[c[i] - c[i - 1]] ++;
	for (int i = 1; i < n; ++ i) if (!delta[t[i] - t[i - 1]]) no(); else delta[t[i] - t[i - 1]] --;
	puts(c[0] == t[0] && c[n - 1] == t[n - 1] ? "Yes" : "No");
	return 0;
}