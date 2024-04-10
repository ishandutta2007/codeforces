#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

int main() {
// 	freopen("d.in", "r", stdin);
// 	freopen("d.out", "w", stdout);
	int n, k, t;
	scanf("%d %d %d", &n, &k, &t);
	static char s[200005];
	scanf("%s", s);
	vector<bool> used(k);
	rep(i, n) used[s[i] - 'A'] = true;
	int forb = 0;
	rep(i, k) if (!used[i]) forb |= 1 << i;
	vector<int> c(k);
	rep(i, k) scanf("%d", &c[i]);
	vector<vector<int> > d(k, vector<int> (k));
	rep(i, k) rep(j, k) scanf("%d", &d[i][j]);
	vector<int> nex(k, n);
	vector<int> f(1 << k);
	for (int i = n - 1; ~i; -- i) {
		vector<pair<int, int> > vec;
		rep(ch, k) {
			if (nex[ch] < n) {
				vec.pb(mp(nex[ch], ch));
			}
		}
		sort(vec.begin(), vec.end());
		int mask = 0;
		rep(j, vec.size()) {
			int D = d[s[i] - 'A'][vec[j].second];
			if (!(mask >> (s[i] - 'A') & 1) && !(mask >> vec[j].second & 1)) {
				f[mask] += D;
				f[mask | 1 << (s[i] - 'A')] -= D;
				f[mask | 1 << vec[j].second] -= D;
				f[mask | 1 << (s[i] - 'A') | 1 << vec[j].second] += D;
			}
			mask |= 1 << vec[j].second;
		}
		nex[s[i] - 'A'] = i;
	}
	rep(i, k) rep(j, 1 << k) if (!(j >> i & 1)) f[j | 1 << i] += f[j];
	int ans = 0;
	rep(i, 1 << k) {
		if (i & forb) continue;
		if ((i | forb) == (1 << k) - 1) continue;
		int tot = f[i];
		rep(j, k) if (i >> j & 1) tot += c[j];
		if (tot <= t) ++ ans;
	}
	printf("%d\n", ans);
	return 0;
}