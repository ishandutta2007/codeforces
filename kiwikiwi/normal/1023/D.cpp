#include <bits/stdc++.h>
using namespace std;

const int N = 234567;

int n, q, a[N];
vector<int> pos[N];
set<int> posset;
int main() {
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	int z = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i]) {
			z = a[i];
			break;
		}
	}
	if (z == 0) {
		puts("YES");
		for (int i = 1; i <= n; i++) {
			printf("%d ", q);
		}
		puts("");
		return 0;
	}
	bool getm = 0;
	for (int i = 1; i <= n; i++) if (a[i] == q) getm = 1;
	for (int i = 1; i <= n; i++) {
		if (a[i]) z = a[i];
		else {
			if (!getm) {
				a[i] = q;
				getm = 1;
				z = q;
			} else a[i] = z;
		}
	}
	for (int i = 1; i <= n; i++) {
		pos[a[i]].push_back(i);
	}
	if (!getm) {
		puts("NO");
		return 0;
	}
	for (int i = 1; i <= q; i++) {
		if (pos[i].empty()) continue;
		int l = pos[i][0], r = pos[i].back();
		auto it = posset.lower_bound(l);
		if (it != posset.end() && *it < r) {
			puts("NO");
			return 0;
		}
		for (auto x : pos[i]) posset.insert(x);
	}
	puts("YES");
	for (int i = 1; i <= n; i++) printf("%d ", a[i]);
	puts("");
}