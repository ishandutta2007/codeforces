#include <bits/stdc++.h>
using namespace std;
 
using i64 = long long;
#define maxN 201000

int a[maxN], b[maxN];
int n, m, k;

vector<array<i64, 2>> factor(int *a, int n) {
	int num = -1;
	i64 cnt = 0;
	vector<array<i64, 2>> nums;
	for (int i = 1; i <= n; i++) {
		i64 c = 1;
		while (a[i] % m == 0) a[i] /= m, c *= m;
		if (a[i] == num) cnt += c;
		else {
			nums.push_back({num, cnt});
			num = a[i];
			cnt = c;
		}
	}
	nums.push_back({num, cnt});
	return nums;
}
void solve() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	auto ans1 = factor(a, n);
	scanf("%d", &k);
	for (int i = 1; i <= k; i++) {
		scanf("%d", &b[i]);
	}
	auto ans2 = factor(b, k);
	puts(ans1 == ans2 ? "Yes" : "No");
}
int main() {
	int tc;
	scanf("%d", &tc);
	for (int T = 0 ; T < tc; T++) {
		solve();
	}
}