#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define maxN 5678

mt19937 mrand(random_device{}());

int k, a[maxN], posb[maxN], posc[maxN], b[maxN], c[maxN];

int main() {
	scanf("%d", &k);
	int n = 1 << k;
	int s = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", a + i);
		s ^= a[i];
	}
	memset(posb, -1, sizeof(posb));
	memset(posc, -1, sizeof(posc));
	auto nextInt = [&](int *pos) {
		while (true) {
			int x = mrand() % n;
			if (pos[x] == -1)
				return x;
		}
	};
	if (s != 0) {
		printf("Fou\n");
		return 0;
	}
	for (int i = 0; i < n; i++) {
		b[i] = nextInt(posb);
		posb[b[i]] = i;
		c[i] = a[i] ^ b[i];
		int which = 0;
		int idx = i;
		while (1) {
			if (which == 0) {
				if (posc[c[idx]] == -1) {
					posc[c[idx]] = idx;
					break;
				} else {
					swap(posc[c[idx]], idx);
					c[idx] = nextInt(posc);
					posc[c[idx]] = idx;
					posb[b[idx]] = -1;
					b[idx] = a[idx] ^ c[idx];
					which = 1;
				}
			} else {
				if (posb[b[idx]] == -1) {
					posb[b[idx]] = idx;
					break;
				} else {
					swap(posb[b[idx]], idx);
					b[idx] = nextInt(posb);
					posb[b[idx]] = idx;
					posc[c[idx]] = -1;
					c[idx] = a[idx] ^ b[idx];
					which = 0;
				}
			}
		}
	}
	printf("Shi\n");
	for (int i = 0; i < n; i++)
		printf("%d ", b[i]);
	printf("\n");
	for (int i = 0; i < n; i++)
		printf("%d ", c[i]);
	printf("\n");
}