#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int N = 500005;

int n, ans[N];

struct P {
	int a, id;
} p[N];

int cmp(P a, P b) {
	return a.a < b.a;
}

int main() {
	scanf("%d", &n); int i, Min;
	for (i = 0; i < n; i++) {
		scanf("%d", &p[i].a);
		p[i].id = i;
	}
	sort(p, p + n, cmp);
	Min = p[0].a;
	for (i = 0; i < n; i++) {
		if (Min >= p[i].a) {
			ans[p[i].id] = Min++;
		}
		else {
			Min = p[i].a;
			ans[p[i].id] = Min++;
		}
	}
	for (i = 0; i < n - 1; i ++)
		printf("%d ", ans[i]);
	printf("%d\n", ans[n - 1]);
	return 0;
}