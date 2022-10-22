#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

int main() {
// 	freopen("a.in", "r", stdin);
// 	freopen("a.out", "w", stdout);
	int n, k;
	scanf("%d %d", &n, &k);
	vector<int> a(n);
	rep(i, n) scanf("%d", &a[i]);
	auto chk = [&] (int w) {
		vector<int> f(n);
		int ans = n;
		for (int i = n - 1; ~i; -- i) {
			f[i] = n - i - 1;
			for (int j = i + 1; j < n; ++ j) {
				if (abs(a[j] - a[i]) <= 1LL * w * (j - i)) {
					f[i] = min(f[i], f[j] + (j - i - 1));
				}
			}
			ans = min(ans, i + f[i]);
		}
		return ans <= k;
	};
	int lb = 0, rb = 2e9;
	while (lb < rb) {
		int md = lb + (rb - lb) / 2;
		if (chk(md)) rb = md;
		else lb = md + 1;
	}
	printf("%d\n", lb);
	return 0;
}