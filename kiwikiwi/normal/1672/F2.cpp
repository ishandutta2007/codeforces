#include <bits/stdc++.h>
using namespace std;
 
using i64 = long long;
#define maxN 201000

int n, num[maxN], a[maxN], b[maxN], ind[maxN];
vector<int> e[maxN];

void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		e[i].clear();
		num[i] = 0;
		ind[i] = 0;
		scanf("%d", &a[i]);

	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &b[i]);
		num[b[i]]++;
	}
	int maxd = max_element(num + 1, num + n + 1) - num;
	for (int i = 1; i <= n; i++) {
		if (a[i] != maxd) {
			e[a[i]].push_back(b[i]);
			//printf("edge %d %d\n", a[i], b[i]);
			ind[b[i]]++;
		}
	}
	int cnt = 0;
	queue<int> q;
	for (int i = 1; i <= n; i++) if (ind[i] == 0) {
		q.push(i);
	}
	while (!q.empty()) {
		int u = q.front(); q.pop();
		++cnt;
		for (auto v : e[u]) {
			--ind[v];
			if (ind[v] == 0) q.push(v);
		}
	}
	if (cnt == n) puts("AC");
	else puts("WA");
}
int main() {
	int tc;
	scanf("%d", &tc);
	for (int T = 0 ; T < tc; T++) {
		solve();
	}
}