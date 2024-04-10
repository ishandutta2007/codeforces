#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

struct BIT {
	static const int mxn = 5e5 + 5;

	int mx[mxn], vis[mxn], tme;

	void clear() {
		tme ++;
	}

	void upd(int x, int v) {
		for (++ x; x < mxn; x += x & -x) {
			if (vis[x] < tme)
				vis[x] = tme, mx[x] = -0x3f3f3f3f;
			mx[x] = max(mx[x], v);
		}
	}

	int qry(int x) {
		int ans = -0x3f3f3f3f;
		for (++ x; x; x -= x & -x) {
			if (vis[x] < tme)
				vis[x] = tme, mx[x] = -0x3f3f3f3f;
			ans = max(ans, mx[x]);
		}
		return ans;
	}
} bit;

const int mxn = 5e5 + 5;

int n, k;
int a[mxn];
bool used[mxn];
vector <int> vec;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;
	rep(i, n) {
		cin >> a[i];
		a[i] -= i;
	}
	rep(i, k) {
		int x;
		cin >> x;
		-- x;
		used[x] = true;
	}

	rep(i, n)
		vec.pb(a[i]);
	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());

	rep(i, n)
		a[i] = lower_bound(vec.begin(), vec.end(), a[i]) - vec.begin() + 1;

	bit.clear();
	bit.upd(0, 0);
	rep(i, n) {
		int ans = bit.qry(a[i]) + 1;
		if (used[i]) bit.clear();
		bit.upd(a[i], ans);
	}

	int ans = n - bit.qry(vec.size());
	printf("%d\n", ans > n ? -1 : ans);

	return 0;
}