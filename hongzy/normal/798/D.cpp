#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 1e5 + 10;

int n, a[N], b[N], rka[N], rkb[N];
bool tag[N];

bool cmpa(int x, int y) {
	return a[x] > a[y];
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) scanf("%d", a + i);
	for(int i = 1; i <= n; i ++) scanf("%d", b + i);
	for(int i = 1; i <= n; i ++) rka[i] = i;
	sort(rka + 1, rka + n + 1, cmpa);
	if(n & 1) {
		printf("%d\n", n / 2 + 1);
		printf("%d ", rka[1]);
		for(int i = 2; i <= n; i += 2) {
			printf("%d ", b[rka[i]] >= b[rka[i + 1]] ? rka[i] : rka[i + 1]);
		}
	} else {
		printf("%d\n", n / 2 + 1);
		printf("%d %d ", rka[1], rka[2]);
		for(int i = 3; i <= n; i += 2) {
			printf("%d ", b[rka[i]] >= b[rka[i + 1]] ? rka[i] : rka[i + 1]);
		}
	}
	return 0;
}