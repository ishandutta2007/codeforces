#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define maxN 223456

int n, k, ans;
int t1[maxN], t2[maxN];

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		t1[i] = k + 1;
		t2[i] = 0;
	}
	for (int i = 1; i <= k; i++) {
		int x;
		scanf("%d", &x);
		t1[x] = min(t1[x], i);
		t2[x] = max(t2[x], i);
	}
	for (int i = 1; i <= n; i++) {
		if (t1[i] > t2[i]) ans++;
	}
	for (int i = 2; i <= n; i++) {
		if (t2[i - 1] < t1[i]) ans++;
	}
	for (int i = 1; i < n; i++) {
		if (t2[i + 1] < t1[i]) ans++;
	}
	printf("%d\n", ans);
}