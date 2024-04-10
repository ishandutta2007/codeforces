#include <cstdio>
#include <map>

using namespace std;

int a[101];
map<int, int> D;

int f(int x) {
	if (x == 0) return 0;
	if (D.find(x) == D.end()) {
		int i;
		int a[32];
		for (i = 0; i < 32; i++) a[i] = 0;
		for (i = 0; (1 << i) <= x; i++) {
			a[f((x >> i + 1) | (x & (1 << i) - 1))] = 1;
		}
		for (i = 0; a[i]; i++);
		return D[x] = i;
	}
	return D[x];
}

int main() {
	int i, j, k, l, n, t, r = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++) scanf("%d", &a[i]);
	for (i = 2; i <= 40000; i++) {
		l = 0;
		for (j = 0; j < n; j++) {
			for (k = 0; a[j] % i == 0; k++) a[j] /= i;
			if (k) l |= 1 << k - 1;
		}
		r ^= f(l);
	}
	for (i = 0; i < n; i++) if (a[i] > 1) {
		t = a[i];
		l = 0;
		for (j = 0; j < n; j++) {
			for (k = 0; a[j] % t == 0; k++) a[j] /= t;
			if (k) l |= 1 << k - 1;
		}
		r ^= f(l);
	}
	puts(r ? "Mojtaba" : "Arpa");
	return 0;
}