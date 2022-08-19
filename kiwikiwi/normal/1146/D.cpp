#include <bits/stdc++.h>
using namespace std;

using i64 = long long;


int gcd(int a, int b) {
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}

#define maxN 423456
int T = 300000;
i64 m , ans;
int a, b, dis[maxN];

int main() {
	scanf("%lld%d%d", &m, &a, &b);
	T = min(T, (int)m);
	for (int i = 0; i <= T; i++)
		dis[i] = m + 1;
	int pos = 0, maxp = 0;
	for (int i = 0; i <= 300000; i++) {
		dis[pos] = min(dis[pos], maxp);
		if (pos >= b) pos -= b;
		else {
			pos += a;
			maxp = max(maxp, pos);
		}
	}
	int d = gcd(a, b);
	for (int i = maxp + 1; i <= T; i++) {
		if (i % d == 0) dis[i] = i;
	}
	for (int i = 0; i <= T; i++) {
		ans += m + 1 - dis[i];
		if (i % d == 0)
			ans -= m + 1 - i;
	}
	ans += (m + 1) * (m / d + 1);
	ans -= d * (m / d) * (m / d + 1) / 2;
	printf("%lld\n", ans);
}