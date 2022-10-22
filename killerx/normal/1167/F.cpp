#include <bits/stdc++.h>
using namespace std;
const int N = 500005;
const int mod = 1000000007;
int n, a[N];
vector <pair <int, int> > v;
struct Bit {
	int sum[N];
	void add(int x, int v) {
		for (++ x; x < N; x += x & -x)
			sum[x] = (sum[x] + v) % mod;
	}
	int qry(int x) {
		int ans = 0;
		for (++ x; x; x -= x & -x)
			ans = (ans + sum[x]) % mod;
		return ans;
	}
} L, R;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++ i) {
		scanf("%d", a + i);
		v.push_back(make_pair(a[i], i));
	}
	sort(v.begin(), v.end());
	int ans = 0;
	for (int ii = 0; ii < n; ++ ii) {
		int x = v[ii].first;
		int i = v[ii].second;
		long long coef = 0;
		coef = (coef + 1LL * L.qry(i) * (n - i)) % mod;
		coef = (coef + 1LL * (R.qry(n) - R.qry(i - 1)) * (i + 1)) % mod;
		coef = (coef + 1LL  * (i + 1) * (n - i)) % mod;
		ans = (ans + coef * x) % mod;
		L.add(i, i + 1);
		R.add(i, n - i);
	}
	printf("%d\n", ans);
	return 0;
}