#include <bits/stdc++.h>
using namespace std;

const int maxN = 123456;
int n, m, x[maxN], x1, x2, y, r;
map<int, int> cnt;
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x[i]);
		cnt[x[i]]++;
	}

	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &x1, &x2, &y);
		if (x1 == 1) {
			cnt[x2]--;
			r++;
		}
	}
	int cc = r, ans = r;
	for (auto p : cnt) {
		if (p.first >= 1000000000) continue;
		cc += p.second;
		ans = min(ans, cc);
	}
	printf("%d\n", ans);
}