#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	vector<int> a(n);
	rep(i, n) scanf("%d", &a[i]);
	auto f = [&] (int l, int k) {
		int mn = l / k;
		int lft = l % k;
		return 1LL * mn * mn * (k - lft) + 1LL * (mn + 1) * (mn + 1) * lft;
	};
	vector<int> cur(n);
	rep(i, n) cur[i] = 1;
	ll ans = 0;
	rep(i, n) ans += f(a[i], cur[i]);
	k -= n;
	priority_queue <pair <ll, int> > pq;
	rep(i, n) pq.push(mp(f(a[i], cur[i]) - f(a[i], cur[i] + 1), i));
	while (k) {
		auto p = pq.top();
		pq.pop();
		ll bonus = -p.first;
		int i = p.second;
		ans += bonus;
		++ cur[i];
		-- k;
		pq.push(mp(f(a[i], cur[i]) - f(a[i], cur[i] + 1), i));
	}
	printf("%lld\n", ans);
	return 0;
}