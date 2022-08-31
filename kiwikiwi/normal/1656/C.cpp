#include <bits/stdc++.h>
using namespace std;
 
using i64 = long long;
#define maxN (1 << 18) + 10

int n, k, a[maxN];
bool solve() {
	scanf("%d", &n);
	bool has1 = false;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		has1 |= (a[i] == 1);
	}
	if (!has1) return true;
	sort(a + 1, a + n + 1);
	for (int i = 1; i < n; i++) if (a[i + 1] == a[i] + 1) 
		return false;
	return true;
}

int main() {
	int tc;
	scanf("%d", &tc);
	for (int i = 1; i <= tc; i++) {
		puts(solve()?"YES":"NO");
	}
}