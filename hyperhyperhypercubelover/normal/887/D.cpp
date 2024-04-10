#include <cstdio>
#include <deque>
#include <algorithm>

using namespace std;

deque<long long> dq;

int a[300003];
long long c[300003], d[300003];

int main() {
	int t;
	int i, j, k, n, start, A, B, C, D, len;
	scanf("%d%d%d%d%d%d%d", &n, &A, &B, &C, &D, &start, &len);
	for (i = 1; i <= n; i++) {
		scanf("%d%d", &a[i], &j);
		if (j) {
			c[i] = c[i - 1] + A;
			d[i] = d[i - 1] + C;
		}
		else {
			c[i] = c[i - 1] - B;
			d[i] = d[i - 1] - D;
		}
	}
	a[n + 1] = 2.1e9;
	t = i = j = 0;
	while (t < 1.05e9) {
		while (j < n && a[j + 1] < t + len) {
			j++;
			while (!dq.empty() && dq.back() > d[j]) dq.pop_back();
			dq.push_back(d[j]);
		}
		while (i < n && a[i + 1] < t) {
			i++;
			while (!dq.empty() && dq.front() == d[i]) dq.pop_front();
		}
		if (c[i] + start < 0) break;
		if ((dq.empty() ? 0 : dq.front() - d[i]) + c[i] + start >= 0) {
			printf("%d\n", t);
			return 0;
		}
		t = min(a[i + 1] + 1, a[j + 1] - len + 1);
	}
	puts("-1");
	return 0;
}