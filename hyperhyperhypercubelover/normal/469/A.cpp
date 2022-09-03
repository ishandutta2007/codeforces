#include <cstdio>
#include <algorithm>

using namespace std;

int a[101];

int main() {
	int i, n, m, t;
	scanf("%d", &n);
	scanf("%d", &m);
	while (m--) {
		scanf("%d", &t);
		a[t] = 1;
	}
	scanf("%d", &m);
	while (m--) {
		scanf("%d", &t);
		a[t] = 1;
	}
	for (i = 1; i <= n; i++) if (!a[i]) break;
	puts(i > n ? "I become the guy." : "Oh, my keyboard!");
}