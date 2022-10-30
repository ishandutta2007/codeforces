// Hydro submission #62596da737de167dd82c2623@1650027947169
#include <bits/stdc++.h>
using namespace std;

inline int read() {
	int x = 0, f = 0; char c = 0;
	while (!isdigit(c)) f |= c == '-', c = getchar();
	while (isdigit(c)) x = (x << 3) + (x << 1) + (c & 15), c = getchar();
	return f ? -x : x;
}

#define N 5010

int a[N];

int main() {
	int n = read(), m = read();
	int t = 0;
	for (int i = 0; i < n; i ++) {
		a[i] = i + 1, t += i >> 1;
		if (t >= m) {
			a[i] += (t - m) * 2;
			for (int j = n - 1, k = 1e9; j > i; j --, k -= i + 2) {
				a[j] = k;
			}
			for (int j = 0; j < n; j ++) {
				printf("%d ", a[j]);
			}
			return 0;
		}
	}
	puts("-1");
	return 0;
}