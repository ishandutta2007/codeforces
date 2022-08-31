#include <bits/stdc++.h>
using namespace std;
 
using i64 = long long;
#define maxN (1 << 18) + 10

int n, k, a[maxN];
bool solve() {
	scanf("%d%d", &n, &k);
	set<int> num;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		num.insert(a[i]);
	}
	for (int i = 1; i <= n; i++) 
		if (num.count(a[i] + k)) return true;
	return false;
}

int main() {
	int tc;
	scanf("%d", &tc);
	for (int i = 1; i <= tc; i++) {
		puts(solve()?"YES":"NO");
	}
}