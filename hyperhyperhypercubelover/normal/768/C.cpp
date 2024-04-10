#include <cstdio>
#include <algorithm>

using namespace std;

int a[2][1024];

int main() {
	int *p, *q;
	int i, j, n, m, l;
	scanf("%d%d%d", &n, &m, &l);
	p = a[0];
	q = a[1];
	while (n--) {
		scanf("%d", &i);
		p[i]++;
	}
	while (m--) {
		for (i = 0; i < 1024; i++) q[i] = 0;
		for (i = j = 0; i < 1024; i++) {
			if (j & 1) {
				q[i] += p[i] + 1 >> 1;
				q[i ^ l] += p[i] >> 1;
			}
			else {
				q[i] += p[i] >> 1;
				q[i ^ l] += p[i] + 1 >> 1;
			}
			j += p[i];
		}
		swap(p, q);
	}
	for (i = 1023; !p[i]; i--);
	printf("%d ", i);
	for (i = 0; !p[i]; i++);
	printf("%d\n", i);
}