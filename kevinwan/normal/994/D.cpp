#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define mp make_pair
pii a[12], b[12];
int sim(pii x, pii y) {
	int ans = 0, ty = 0;
	if (x.first == y.second)ans = x.first, ty++;
	if (x.first == y.first)ans = x.first, ty++;
	if (x.second == y.second)ans = x.second, ty++;
	if (x.second == y.first)ans = x.second, ty++;
	if (ty >= 2)return 0;
	else return ans;
}
set<int> aa[12], bb[12];
int main() {
	int n, m, x, y, i, j;
	scanf("%d%d", &n, &m);
	for (i = 0; i < n; i++) {
		scanf("%d%d", &x, &y);
		a[i] = mp(x, y);
	}
	for (i = 0; i < m; i++) {
		scanf("%d%d", &x, &y);
		b[i] = mp(x, y);
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			int k = sim(a[i], b[j]);
			if (k != 0) {
				aa[i].insert(k);
				bb[j].insert(k);
			}
		}
	}
	int ans;
	bool pass = 1, me = 1;
	set<int> tot;
	for (i = 0; i < n; i++) {
		if (aa[i].size() >= 2)pass = 0;
		else if (aa[i].size() == 1) tot.insert(*(aa[i].begin()));
	}
	for (i = 0; i < m; i++) {
		if (bb[i].size() >= 2)pass = 0;
		if (bb[i].size() == 1)ans = *(bb[i].begin());
	}
	if (pass == 0)printf("-1");
	else if (tot.size() != 1)printf("0");
	else printf("%d", ans);
	getchar(); getchar();
}