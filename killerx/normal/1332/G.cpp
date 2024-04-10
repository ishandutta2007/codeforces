#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mxn = 2e5 + 5;

int n, q;
int a[mxn];

std::set <int> nstk;

int fl[mxn], fs[mxn];

int stk1[mxn], top1;
int stk2[mxn], top2;

int ans3[mxn][2];
int ans4[mxn][3];

int cnt[mxn];

void is(int i) { if (cnt[i] == 0) nstk.erase(i); cnt[i] ++; }
void er(int i) { cnt[i] --; if (cnt[i] == 0) nstk.insert(i); }

std::vector <std::pair <int, int> > qry[mxn];
std::string ans[mxn];

std::pair <int, int> mn3, mn4;

int main() {
	scanf("%d %d", &n, &q);
	rep(i, n) scanf("%d", &a[i]);
	memset(fl, -1, sizeof(fl));
	memset(fs, -1, sizeof(fs));
	memset(ans3, -1, sizeof(ans3));
	memset(ans4, -1, sizeof(ans4));
	rep(i, n) nstk.insert(i);
	for (int i = n - 1; ~i; -- i) {
		while (top1 && a[stk1[top1 - 1]] > a[i]) -- top1, er(stk1[top1]); stk1[top1 ++] = i, is(i);
		while (top2 && a[stk2[top2 - 1]] < a[i]) -- top2, er(stk2[top2]); stk2[top2 ++] = i, is(i);
		int P = std::upper_bound(stk1, stk1 + top1, i, [&] (int x, int y) { return a[x] == a[y]; }) - stk1 - 1;
		int Q = std::upper_bound(stk2, stk2 + top2, i, [&] (int x, int y) { return a[x] == a[y]; }) - stk2 - 1;
		if (P >= 0) fs[i] = stk1[P];
		if (Q >= 0) fl[i] = stk2[Q];
		if (P >= 0 && Q >= 0) {
			auto it = nstk.upper_bound(std::max(stk1[P], stk2[Q]));
			if (it != nstk.end()) {
				ans4[i][2] = *it;
				ans4[i][0] = *std::lower_bound(stk1, stk1 + top1, *it, [&] (int x, int y) { return x > y; });
				ans4[i][1] = *std::lower_bound(stk2, stk2 + top2, *it, [&] (int x, int y) { return x > y; });
				if (ans4[i][0] > ans4[i][1]) std::swap(ans4[i][0], ans4[i][1]);
			}
		}
		if (P >= 0 && ~fl[stk1[P]]) {
			if (!~ans3[i][1]) {
				ans3[i][0] = stk1[P];
				ans3[i][1] = fl[stk1[P]];
			}
		}
		if (Q >= 0 && ~fs[stk2[Q]]) {
			if (!~ans3[i][1] || ans3[i][1] > fs[stk2[Q]]) {
				ans3[i][0] = stk2[Q];
				ans3[i][1] = fs[stk2[Q]];
			}
		}
	}
	rep(i, q) {
		int l, r;
		scanf("%d %d", &l, &r);
		-- l, -- r;
		qry[l].push_back(std::make_pair(i, r));
	}
	mn3 = std::make_pair(n, -1);
	mn4 = std::make_pair(n, -1);
	for (int l = n - 1; ~l; -- l) {
		if (~ans3[l][1]) mn3 = std::min(mn3, std::make_pair(ans3[l][1], l));
		if (~ans4[l][2]) mn4 = std::min(mn4, std::make_pair(ans4[l][2], l));
		for (std::pair <int, int> pr : qry[l]) {
			int r = pr.second;
			int i = pr.first;
			std::stringstream ss;
			if (r >= mn4.first) {
				ss << 4 << std::endl;
				ss << mn4.second + 1 << " " <<
					ans4[mn4.second][0] + 1 << " " <<
					ans4[mn4.second][1] + 1 << " " <<
					ans4[mn4.second][2] + 1 << std::endl;
			} else if (r >= mn3.first) {
				ss << 3 << std::endl;
				ss << mn3.second + 1 << " " <<
					ans3[mn3.second][0] + 1 << " " <<
					ans3[mn3.second][1] + 1 << std::endl;
			} else {
				ss << 0 << std::endl;
			}
			ans[i] = ss.str();
		}
	}
	rep(i, q) printf("%s", ans[i].c_str());
	return 0;
}