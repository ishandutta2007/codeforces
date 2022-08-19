#include <bits/stdc++.h>
using namespace std;
 
using i64 = long long;
#define maxN 201000

int n, num[maxN], a[maxN], p[maxN], ans[maxN];
vector<int> pos[maxN];
void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		num[i] = 0;
		p[i] = i;
		pos[i].clear();
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		num[a[i]]++;
		pos[a[i]].push_back(i);
	}
	sort(p + 1, p + n + 1, [&](int a, int b) {
		return num[a] > num[b];
	});
	int d = p[1];
	for (int i = 1; i <= n; i++) {
		int c = (i == n)? 0 : num[p[i + 1]];
		for (int j = 0; j < c; j++) {
			ans[pos[p[i]][j]] = p[i + 1];
		}
		for (int j = c; j < num[p[i]]; j++) {
			ans[pos[p[i]][j]] = d;
		}
	}
	for (int i = 1; i <= n; i++) {
		printf("%d%c", ans[i], " \n"[i == n]);
	}
}
int main() {
	int tc;
	scanf("%d", &tc);
	for (int T = 0 ; T < tc; T++) {
		solve();
	}
}