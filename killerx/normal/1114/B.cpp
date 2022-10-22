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

const int N = 2e5 + 5;
int n, m, k;
int a[N];
bool used[N];
vector <pair <int, int> > e;

int main() {
	n = read(), m = read(), k = read();
	for (int i = 0; i < n; ++ i) {
		a[i] = read();
		e.push_back(make_pair(a[i], i));
	}
	sort(e.begin(), e.end());
	reverse(e.begin(), e.end());
	ll ans = 0;
	for (int i = 0; i < k * m; ++ i) {
		used[e[i].second] = 1;
		ans += e[i].first;
	}
	printf("%lld\n", ans);
	int cnt = 0, cntt = 0;
	for (int i = 0; i < n; ++ i) {
		if (used[i]) ++ cnt;
		if (cnt == m) {
			++ cntt;
			if (cntt < k) printf("%d ", i + 1);
			cnt = 0;
		}
	}
	return 0;
}