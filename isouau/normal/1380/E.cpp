#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e5 + 5;

set <int> num[N];
set <int> :: iterator it;
int res[N], f[N];
int n, m, cnt;

void add(int idx, int x) {
	it = num[idx].lower_bound(x);
	if (it != num[idx].end() && *it == x + 1) ++cnt, ++res[idx];
	if (it != num[idx].begin()) {
		--it;
		if (*it == x - 1) ++cnt, ++res[idx];
	}
	num[idx].insert(x);
}

int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) f[i] = i;
	for (int i = 1; i <= n; i++) {
		int pos;
		scanf("%d", &pos);
		add(pos, i);
	}
	printf("%d\n", n - 1 - cnt);
	for (int i = 1; i < m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		x = find(x); y = find(y);
		if (num[x].size() > num[y].size()) swap(x, y);
		for (set <int> :: iterator it = num[x].begin(); it != num[x].end(); ++it) add(y, *it);
		f[x] = y; cnt -= res[x];
		printf("%d\n", n - 1 - cnt);
	}
	return 0;
}