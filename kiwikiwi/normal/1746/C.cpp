#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 123456;

int n, a[maxn], ans[maxn];
void solve() {
	scanf("%d",&n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	set<int> s;
	for (int i = 1; i <= n; i++) {
		s.insert(i);
		ans[i] = n;
	}
	for (int i = 2; i <= n; i++) if (a[i] < a[i - 1]) {
		int v = a[i - 1] - a[i];
		auto it = s.lower_bound(v);
		ans[*it] = i;
		s.erase(it);
	}
	for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
	puts("");
}

int main() {
	int tc;
	scanf("%d", &tc);
	for (int i = 0; i < tc; i++) {
		solve();
	}
}