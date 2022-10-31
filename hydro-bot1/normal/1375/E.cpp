// Hydro submission #61891de31edf93b3ad658a6b@1636376042721
#include <bits/stdc++.h>
using namespace std;

inline int read();
#define N 1010

int n, a[N], c[N], sum = 0;
pair<int, int> b[N];

int main() {
	n = read();
	for (int i = 1; i <= n; i ++) {
		a[i] = read(), b[i] = make_pair(a[i], i);
	}
	sort(b + 1, b + n + 1);
	for (int i = 1; i <= n; i ++) {
		a[b[i].second] = i, c[i] = b[i].second;
	}

	for (int i = 1; i <= n; i ++) {
		for (int j = i + 1; j <= n; j ++) {
			if (a[i] > a[j]) sum ++;
		}
	}
	printf("%d\n", sum);

	for (int i = n; i >= 1; i --) {
		for (int j = a[i] + 1; j <= i; j ++) {
			int t = c[j];
			c[a[t]] = i, c[a[i]] = t;
			swap(a[t], a[i]);
			printf("%d %d\n", t, i);
		}
	}
	return 0;
}

inline int read() {
	int x = 0, f = 0; char c = 0;
	while (!isdigit(c)) f |= c == '-', c = getchar();
	while (isdigit(c)) x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
	return f ? -x : x;
}