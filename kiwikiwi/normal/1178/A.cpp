#include <bits/stdc++.h>
using namespace std;

#define maxN 123

using i64 = long long;

int n, s, t, a[maxN];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		s += a[i];
	}
	int t = a[1];
	vector<int> ans{1};
	for (int i = 2; i <= n; i++) {
		if (2 * a[i] <= a[1]) {
			t += a[i];
			ans.push_back(i);
		}
	}
	if (t * 2 > s) {
		printf("%d\n", (int)ans.size());
		for (auto par : ans)
			printf("%d ", par);
		printf("\n");
	} else {
		printf("0\n");
	}
}