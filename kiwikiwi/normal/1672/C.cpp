#include <bits/stdc++.h>
using namespace std;
 
using i64 = long long;
#define maxN 201000

int n, a[maxN];
void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	vector<int> pos;
	for (int i = 1; i < n; i++) if (a[i] == a[i + 1]) {
		pos.push_back(i);
	}
	if (pos.empty()) puts("0");
	else {
		int ans = pos.back() - pos.front();
		if (ans >= 2) ans -= 1;
		printf("%d\n", ans);
	}
}
int main() {
	int tc;
	scanf("%d", &tc);
	for (int T = 0 ; T < tc; T++) {
		solve();
	}
}