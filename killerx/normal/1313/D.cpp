#include <bits/stdc++.h>
using namespace std;

void read(int &x) {
	x = 0; int c = getchar();
	while (c <= 32) c = getchar();
	while (c > 32) {
		x = x * 10 + c - '0';
		c = getchar();
	}
}

int bits[256];
int n, m, k;
vector <int> vx;
vector <pair <int, int> > vr;
vector <vector <int> > vrid;
vector <vector <int> > dp;

int main() {
	for (int i = 0; i < 256; ++ i)
		bits[i] = bits[i >> 1] ^ (i & 1);
	read(n); read(m); read(k);
	vx.push_back(1); vx.push_back(n + 1);
	for (int i = 0; i < n; ++ i) {
		int l, r;
		read(l); read(r);
		vx.push_back(l); vx.push_back(r + 1);
		vr.push_back(make_pair(l, r));
	}
	sort(vx.begin(), vx.end());
	vx.erase(unique(vx.begin(), vx.end()), vx.end());
	vrid.resize(vx.size());
	for (int i = 0; i < n; ++ i) {
		int l = vr[i].first, r = vr[i].second;
		l = lower_bound(vx.begin(), vx.end(), l) - vx.begin();
		r = lower_bound(vx.begin(), vx.end(), r + 1) - vx.begin();
		for (int j = l; j < r; ++ j) vrid[j].push_back(i);
	}
	dp.resize(vx.size());
	dp[0].resize(1 << vrid[0].size());
	for (int i = 0; i < (1 << vrid[0].size()); ++ i)
		dp[0][i] = bits[i] ? vx[1] - vx[0] : 0;
	for (int i = 1; i + 1 < vx.size(); ++ i) {
		dp[i].resize(1 << vrid[i].size());
		vector <vector <int> > common(2);
		for (int j = 0; j < vrid[i].size(); ++ j) {
			int nj = lower_bound(vrid[i - 1].begin(), vrid[i - 1].end(), vrid[i][j]) - vrid[i - 1].begin();
			if (nj < vrid[i - 1].size() && vrid[i - 1][nj] == vrid[i][j]) {
				common[0].push_back(nj); common[1].push_back(j);
			}
		}
		vector <int> f(1 << common[0].size());
		for (int j = 0; j < (1 << vrid[i - 1].size()); ++ j) {
			int nw = 0;
			for (int k = 0; k < common[0].size(); ++ k)
				nw |= (j >> common[0][k] & 1) << k;
			f[nw] = max(f[nw], dp[i - 1][j]);
		}
		for (int j = 0; j < (1 << vrid[i].size()); ++ j) {
			int nw = 0;
			for (int k = 0; k < common[1].size(); ++ k)
				nw |= (j >> common[1][k] & 1) << k;
			dp[i][j] = max(dp[i][j], f[nw] + (bits[j] ? vx[i + 1] - vx[i] : 0));
		}
	}
	int ans = 0;
	for (int i = 0; i < (1 << vrid[vx.size() - 2].size()); ++ i)
		ans = max(ans, dp[vx.size() - 2][i]);
	printf("%d\n", ans);
	return 0;
}