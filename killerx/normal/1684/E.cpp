#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mxn =	1 << 17;

int n, k, a[mxn];
std::map <int, int> occ;

int sz;
int s1[mxn << 1], s2[mxn << 1];

inline void Main() {
	scanf("%d %d", &n, &k);
	rep(i, n) scanf("%d", &a[i]);
	occ.clear();
	rep(i, n) occ[a[i]] += 1;
	sz = 1;
	for (; sz < n + 1; sz <<= 1);
	rep(i, sz) s1[i + sz] = s2[i + sz] = 0;
	for (auto pr : occ) s1[pr.second + sz] += 1, s2[pr.second + sz] += pr.second;
	for (int i = sz - 1; i; -- i) {
		s1[i] = s1[i << 1] + s1[i << 1 | 1];
		s2[i] = s2[i << 1] + s2[i << 1 | 1];
	}
	int ans = mxn;
	int oth = 0, rem = (int) occ.size();
	for (int mex = 0; mex <= n; ++ mex) {
		if (oth > k) break;
		int cur = rem;
		if (s2[1] <= k) cur -= s1[1];
		else if (k) {
			int nk = k;
			int i = 1;
			while (i < sz) {
				if (s2[i << 1] >= nk) i = i << 1;
				else {
					nk -= s2[i << 1];
					cur -= s1[i << 1];
					i = i << 1 | 1;
				}
			}
			cur -= nk / (i - sz);
		}
		cur -= mex;
		ans = std::min(ans, cur);
		if (mex < n) {
			if (occ.find(mex) != occ.end()) {
				int x = occ[mex];
				for (x += sz; x; x >>= 1) {
					s1[x] -= 1;
					s2[x] -= occ[mex];
				}
			} else ++ oth, ++ rem;
		}
	}
	printf("%d\n", ans);
}

int main() {
	int T; scanf("%d", &T);
	while (T --) Main();
	return 0;
}