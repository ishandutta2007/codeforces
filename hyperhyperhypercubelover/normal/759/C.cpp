#include <cstdio>
#include <algorithm>

const int o = 1 << 17;

using namespace std;

struct node {
	int sum, min;
} IT[1 << 18];
int a[100001];

int main() {
	int i, j, k, l, n, t;
	scanf("%d", &n);
	while (n--) {
		scanf("%d%d", &i, &j);
		if (j) {
			scanf("%d", &k);
			a[i] = k;
			l = i + o;
			IT[l].sum = 1;
			while (l >>= 1) {
				IT[l].sum = IT[l << 1].sum + IT[l << 1 | 1].sum;
				IT[l].min = min(IT[l << 1].min, IT[l << 1].sum + IT[l << 1 | 1].min);
			}
		}
		else {
			l = i + o;
			IT[l].sum = -1;
			while (l >>= 1) {
				IT[l].sum = IT[l << 1].sum + IT[l << 1 | 1].sum;
				IT[l].min = min(IT[l << 1].min, IT[l << 1].sum + IT[l << 1 | 1].min);
			}
		}
		l = 1;
		t = IT[1].sum - 1;
		if (IT[1].min > t) {
			puts("-1");
			continue;
		}
		while (l < o) {
			if (IT[l << 1].sum + IT[l << 1 | 1].min > t) l = l << 1;
			else {
				t -= IT[l << 1].sum;
				l = l << 1 | 1;
			}
		}
		printf("%d\n", a[l - o]);
	}
}