#include <bits/stdc++.h>
using namespace std;

int n, m, x, now;

int main() {
	scanf("%d %d", &n, &m);
	for (; n--; ) {
		scanf("%d", &x);
		printf("%d ", (now + x) / m);
		now = (now + x) % m;
	}
	return 0;
}