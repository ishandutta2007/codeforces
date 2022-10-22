#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mxn = 1e6 + 5, mxm = 8192;

int n;
std::bitset <mxm> G[mxm + 5], nG[mxm + 5];

int main() {
	scanf("%d", &n);
	// n = 1e6;
	rep(i, mxm + 1) G[i].set(0), nG[i].set(0);
	rep(i, n) {
		int ai;
		scanf("%d", &ai);
		// ai = rand() % 5001;
		for (int z = nG[ai]._Find_first(); z < mxm; z = nG[ai]._Find_next(z)) {
			for (int y = ai + 1; y <= mxm; ++ y) {
				if (!G[y].test(z ^ ai)) {
					nG[y].set(z ^ ai);
					G[y].set(z ^ ai);
				} else break;
			}
			nG[ai].reset(z);
		}
		if (G[mxm].count() == mxm) break;
	}
	printf("%d\n", (int) G[mxm].count());
	for (int x = G[mxm]._Find_first(); x < mxm; x = G[mxm]._Find_next(x)) {
		printf("%d ", x);
	}
	printf("\n");
	return 0;
}