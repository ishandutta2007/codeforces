#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	long long t;
	int l, r, m;
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	b -= a;
	l = 0;
	r = 1000000000;
	while (l < r) {
		m = l + r + 1 >> 1;
		t = (m > c ? 1ll * (m + m - c) * (c - 1) / 2 : 1ll * m * (m - 1) / 2) +
			(m > a - c ? 1ll * (m + m - a + c - 1) * (a - c) / 2 : 1ll * m * (m - 1) / 2) +
			m;
		if (t > b) r = m - 1;
		else l = m;
	}
	printf("%d", l + 1);
}