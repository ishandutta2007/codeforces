#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define ll long long
#define vi vector <int>
#define pii pair <int, int>
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i,n) for (int i = 0; i < (int) (n); ++ i)
#define foreach(it,c) for (__typeof(c.begin()) it = c.begin(); it != c.end(); ++ it)

inline int read() {
	int x = 0, f = 1, c = getchar();
	for (;!isdigit(c);c = getchar()) if (c == '-') f ^= 1;
	for (; isdigit(c);c = getchar()) x = x * 10 + c - '0';
	return f ? x : -x;
}

const int N = 500005;

struct Segt {
	vi t[N * 4];
	int siz;
	void init(int n, int cnt[N]) {
		for (siz = 1; siz <= n; siz <<= 1);
		rep(i, n) t[i + siz].pb(cnt[i]);
		for (int i = siz - 1; i; -- i) {
			t[i].resize(t[i << 1].size() + t[i << 1 | 1].size());
			merge(t[i << 1].begin(), t[i << 1].end(), t[i << 1 | 1].begin(), t[i << 1 | 1].end(), t[i].begin());
		}
	}
	int qry(int l, int r, int x) {
		int ans = 0;
		for (l += siz, r += siz; l < r; l >>= 1, r >>= 1) {
			if (l & 1) { ans += upper_bound(t[l].begin(), t[l].end(), x) - t[l].begin(); ++ l; }
			if (r & 1) { -- r; ans += upper_bound(t[r].begin(), t[r].end(), x) - t[r].begin(); }
		}
		return ans;
	}
} segt;

int n, m, q;
int a[N], cnt[N];

int main() {
	n = read(), m = read(), q = read();
	rep(i, n) a[i] = read() - 1, cnt[a[i]] ++;
	segt.init(m, cnt);
	map <int, int> mapp;
	rep(i, m) mapp[cnt[i]] ++;
	vector <pii> v;
	foreach(it, mapp) v.pb(*it);
	rep(i, v.size() - 1) v[i + 1].second += v[i].second;
	vector <ll> sum; sum.pb(0);
	rep(i, v.size() - 1) sum.pb(sum.back() + 1LL * (v[i + 1].first - v[i].first) * v[i].second);
	while (q --) {
		ll k; scanf("%lld", &k);
		int lb = 0, rb = sum.size();
		while (lb < rb) {
			int md = (lb + rb) >> 1;
			if (sum[md] + n < k) lb = md + 1;
			else rb = md;
		}
		if (lb == sum.size()) {
			printf("%lld\n", (k - sum.back() - n - 1) % m + 1);
		} else {
			int j = lb;
			ll nw = sum[j - 1] + n;
			int rem = (k - nw) % v[j - 1].second;
			if (rem == 0) rem += v[j - 1].second;
			lb = 0, rb = m - 1;
			while (lb < rb) {
				int md = (lb + rb) >> 1;
				if (segt.qry(0, md + 1, v[j - 1].first) < rem) lb = md + 1;
				else rb = md;
			}
			printf("%d\n", lb + 1);
		}
	}
	return 0;
}