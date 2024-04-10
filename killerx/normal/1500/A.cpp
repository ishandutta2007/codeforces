#include <bits/stdc++.h>

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

typedef std::pair <int, int> pii;

const int mxn = 2e5 + 5;
const int mxm = 5e6 + 5;

int n;
pii a[mxn];
int cnt[mxm];
int ind[mxm];
int b[mxn];
pii fst[mxm];

int main() {
	scanf("%d", &n);
	rep(i, n) scanf("%d", &a[i].first), a[i].second = i;
	std::sort(a, a + n);
	rep(i, n) cnt[a[i].first] ++;
	rep(i, mxm) if (cnt[i] >= 4) {
		std::vector <int> ans;
		rep(j, n) if (a[j].first == i)
			ans.push_back(a[j].second + 1);
		printf("YES\n");
		printf("%d %d %d %d\n", ans[0], ans[1], ans[2], ans[3]);
		return 0;
	}
	std::vector <int> vec;
	rep(i, mxm) if (cnt[i] >= 2) {
		vec.push_back(i);
	}
	if (vec.size() >= 2) {
		std::vector <int> ans0, ans1;
		rep(i, n) if (a[i].first == vec[0])
			ans0.push_back(a[i].second + 1);
		rep(i, n) if (a[i].first == vec[1])
			ans1.push_back(a[i].second + 1);
		printf("YES\n");
		printf("%d %d %d %d\n", ans0[0], ans1[0], ans0[1], ans1[1]);
		return 0;
	}
	memset(ind, -1, sizeof(ind));
	rep(i, n) ind[a[i].first] = a[i].second;
	if (vec.size() == 1) {
		int fst = -1, las;
		rep(i, n) if (a[i].first == vec[0]) {
			if (fst == -1) fst = i;
			las = i;
		}
		for (int i = fst - 1; ~i; -- i) {
			if (ind[vec[0] + (vec[0] - a[i].first)] != -1) {
				printf("YES\n");
				printf("%d %d %d %d\n", a[fst].second + 1, a[las].second + 1, a[i].second + 1, ind[vec[0] + (vec[0] - a[i].first)] + 1);
				return 0;
			}
		}
	}
	rep(i, n) b[i] = a[i].first;
	int m = std::unique(b, b + n) - b;
	rep(i, mxm) fst[i] = {-1, -1};
	rep(i, m) {
		for (int j = i + 1; j < m; ++ j) {
			if (fst[b[j] - b[i]].first != -1) {
				printf("YES\n");
				printf("%d %d %d %d\n", fst[b[j] - b[i]].first + 1, ind[b[j]] + 1, fst[b[j] - b[i]].second + 1, ind[b[i]] + 1);
				return 0;
			}
		}
		for (int j = 0; j < i; ++ j) {
			fst[b[i] - b[j]] = {ind[b[j]], ind[b[i]]};
		}
	}
	printf("NO\n");
	return 0;
}