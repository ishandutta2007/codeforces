#include <cstdio>

int a[100001];
int t[100001];
int v[100001];

int main() {
	long long r = 0;
	int i, j, n;
	scanf("%d", &n);
	for (i = 0; i < n; i++) scanf("%d", &a[i]);
	for (i = j = 0; i < n; i++) {
		if (!t[a[i]]) j++;
		t[a[i]]++;
	}
	for (i = n - 1; i >= 0; i--) {
		t[a[i]]--;
		if (!t[a[i]]) j--;
		if (!v[a[i]]) {
			v[a[i]] = 1;
			r += j;
		}
	}
	printf("%lld\n", r);
	return 0;
}