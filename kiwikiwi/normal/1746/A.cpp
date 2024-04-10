#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, k;
void solve() {
	scanf("%d%d",&n, &k);
	int v = 0;
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		v |= x;
	}
	puts(v ? "YES" : "NO");
}

int main() {
	int tc;
	scanf("%d", &tc);
	for (int i = 0; i < tc; i++) {
		solve();
	}
}