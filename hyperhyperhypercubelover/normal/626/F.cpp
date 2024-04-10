#include <cstdio>
#include <algorithm>
using namespace std;
int n, k;

int can[202][202][1001];
int dat[201];

int M = int(1e9) + 7;

inline void add(int& a, int b) {
	a = (a + b) % M;
}

int main()
{
	scanf("%d%d", &n, &k);
	int i;
	for (i = 1; i <= n; ++i) scanf("%d", dat + i);
	sort(dat + 1, dat + n + 1);
	can[0][0][0] = 1;
	int j, im, imb;
	for (i = 1; i <= n; ++i) {
		for (int grp = 0; grp <= n; ++grp) {
			for (imb = 0; imb <= k; ++imb) {
				if (grp && imb - (grp - 1)*(dat[i] - dat[i - 1]) >= 0)
					can[i][grp][imb] = can[i - 1][grp - 1][imb - (grp - 1)*(dat[i] - dat[i - 1])];
				if (imb - grp*(dat[i] - dat[i - 1]) >= 0)
					add(can[i][grp][imb], can[i - 1][grp][imb - grp*(dat[i] - dat[i - 1])] * 1LL * (grp + 1) % M);
				if (imb - (grp + 1)*(dat[i] - dat[i - 1]) >= 0)
					add(can[i][grp][imb], can[i - 1][grp + 1][imb - (grp + 1)*(dat[i] - dat[i - 1])] * 1LL * (grp + 1) % M);
			}
		}
	}
	int ans = 0;
	for (im = 0; im <= k; ++im) {
		add(ans, can[n][0][im]);
	}
	printf("%d\n", ans);
	return 0;
}