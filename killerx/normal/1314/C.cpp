#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define pii pair <int, int>

const int N = 1005;

int n, m, lcp[N][N];
ll k, f[N][N];
char s[N], ans[N];
vector <pii> vr;

bool comp(const pii &a, const pii &b) {
	int l1 = a.first, r1 = a.second;
	int l2 = b.first, r2 = b.second;
	if (lcp[l1][l2] + l1 >= r1 || lcp[l1][l2] + l2 >= r2)
		return r1 - l1 < r2 - l2;
	return s[lcp[l1][l2] + l1] < s[lcp[l1][l2] + l2];
}

bool check(int rid) {
	memset(f, 0, sizeof(f));
	f[0][0] = 1;
	for (int j = 0; j < m; ++ j) {
		for (int i = 0; i < n; ++ i) if (f[i][j]) {
			int lb = i + 1, rb = n;
			while (lb < rb) {
				int md = lb + rb >> 1;
				if (comp(mp(i, md), vr[rid]))
					lb = md + 1;
				else
					rb = md;
			}
			if (!comp(mp(i, lb), vr[rid])) {
				f[lb][j + 1] += f[i][j];
				f[lb][j + 1] = min(k, f[lb][j + 1]);
			}
		}
		for (int i = 1; i <= n; ++ i) {
			f[i][j + 1] += f[i - 1][j + 1];
			f[i][j + 1] = min(k, f[i][j + 1]);
		}
	}
#ifdef DEBUG
	cerr << string(s).substr(vr[rid].first, vr[rid].second - vr[rid].first);
	cerr << " " << f[n][m] << endl;
#endif
	return f[n][m] >= k;
}

int main() {
	cin >> n >> m >> k;
	cin >> s;
	for (int i = n - 1; ~i; -- i) for (int j = n - 1; ~j; -- j)
		if (s[i] == s[j])
			lcp[i][j] = lcp[i + 1][j + 1] + 1;
		else
			lcp[i][j] = 0;
	for (int i = 0; i < n; ++ i) for (int j = i + 1; j <= n; ++ j)
		vr.push_back(make_pair(i, j));
	sort(vr.begin(), vr.end(), comp);
	int lb = 0, rb = vr.size() - 1;
	while (lb < rb) {
		int md = lb + rb + 1 >> 1;
		if (check(md))
			lb = md;
		else
			rb = md - 1;
	}
	int len = 0;
	for (int i = vr[lb].first; i < vr[lb].second; ++ i) ans[len ++] = s[i];
	cout << ans << endl;
	return 0;
}