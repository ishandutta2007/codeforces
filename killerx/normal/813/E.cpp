#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

const int N = 1 << 17;

int n, K;
int id[N];
int a[N], nex[N];
vector <int> v[N];

int siz;
vector <int> vec[N + N];

void build() {
	siz = 1;
	while (siz <= n) siz <<= 1;
	for (int i = 0; i < n; ++ i) vec[i + siz].pb(nex[i]);
	for (int i = siz - 1; i; -- i) {
		vec[i].resize(vec[i + i].size() + vec[i + i + 1].size());
		merge(vec[i + i].begin(), vec[i + i].end(), vec[i + i + 1].begin(), vec[i + i + 1].end(), vec[i].begin());
	}
}

int qry(int l, int r, int v) {
	int ans = 0;
	for (l += siz, r += siz; l < r; l >>= 1, r >>= 1) {
		if (l & 1) ans += vec[l].end() - lower_bound(vec[l].begin(), vec[l].end(), v), l ++;
		if (r & 1) -- r, ans += vec[r].end() - lower_bound(vec[r].begin(), vec[r].end(), v);
	}
	return ans;
}

int main() {
	scanf("%d %d", &n, &K);
	for (int i = 0; i < n; ++ i) {
		scanf("%d", &a[i]);
		id[i] = v[a[i]].size();
		v[a[i]].pb(i);
	}
	for (int i = 0; i < n; ++ i)
		nex[i] = id[i] + K >= v[a[i]].size() ? n : v[a[i]][id[i] + K];
	build();
	int q; scanf("%d", &q);
	int lst = 0;
	while (q --) {
		int x, y; scanf("%d %d", &x, &y);
		int l, r;
		l = (x + lst) % n + 1;
		r = (y + lst) % n + 1;
		if (l > r) swap(l, r);
		-- l;
		printf("%d\n", lst = qry(l, r, r));
	}
	return 0;
}