#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

const int N = 3e6;

int tot;
int to[N][2], sum[N];

void upd(int i, int u, int x, int v) {
	sum[u] += v;
	if (i == 27) return;
	int c = x >> (26 - i) & 1;
	if (!to[u][c]) to[u][c] = ++ tot;
	upd(i + 1, to[u][c], x, v);
}

int qry(int i, int u, int x, int s) {
	if (i == 27) return 0;
	int ans = 0;
	for (int c = 0; c < 2; ++ c) {
		if (!to[u][c]) continue;
		int c0 = x >> (26 - i) & 1;
		int c1 = s >> (26 - i) & 1;
		if ((c ^ c0) < c1)
			ans += sum[to[u][c]];
		else if ((c ^ c0) == c1)
			ans += qry(i + 1, to[u][c], x, s);
	}
	return ans;
}

int main() {
	int q; scanf("%d", &q);
	while (q --) {
		int tp; scanf("%d", &tp);
		if (tp == 1) {
			int p; scanf("%d", &p);
			upd(0, 0, p, 1);
		} else if (tp == 2) {
			int p; scanf("%d", &p);
			upd(0, 0, p, -1);
		} else {
			int p, l; scanf("%d %d", &p, &l);
			printf("%d\n", qry(0, 0, p, l));
		}
	}
	return 0;
}