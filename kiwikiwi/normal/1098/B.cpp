#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

const int maxN = 323456;

int n, m, p[10], sw;
char s[maxN];
vector<int> u[1234], v[1234];
int main() {
	scanf("%d%d", &n, &m);
	if (n <= m) {
		for (int i = 0; i < n; i++) {
			scanf("%s", s);
			v[i] = vector<int>(m, 0);
			for (int j = 0; j < m; j++) {
				for (int k = 0; k < 4; k++)
					if (s[j] == "ACGT"[k]) v[i][j] = k;
			}
		}
	} else {
		for (int i = 0; i < m; i++)
			v[i] = vector<int>(n, 0);
		for (int i = 0; i < n; i++) {
			scanf("%s", s);
			for (int j = 0; j < m; j++) {
				for (int k = 0; k < 4; k++)
					if (s[j] == "ACGT"[k]) v[j][i] = k;
			}
		}
		swap(n, m);
		sw = 1;
	}
	int ans = 1 << 30;
	for (int i = 0; i < n; i++) u[i] = vector<int>(m, 0);
	for (int i = 0; i < 4; i++) p[i] = i;
	while (1) {
		int cnt = 0;
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
				int c = p[((i % 2) * 2) ^ (j % 2)];
				cnt += v[i][j] != c;
			}
		if (cnt < ans) {
			ans = cnt;
			for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
					int c = p[((i % 2) * 2) ^ (j % 2)];
					u[i][j] = c;
				}
		}
		cnt = 0;
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
				int c = p[((i % 2) * 2) ^ (j % 4)];
				cnt += v[i][j] != c;
			}
		if (cnt < ans) {
			ans = cnt;
			for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
					int c = p[((i % 2) * 2) ^ (j % 4)];
					u[i][j] = c;
				}
		}
		cnt = 0;
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
				int c = p[(i % 4) ^ ((j % 2) * 2)];
				cnt += v[i][j] != c;
			}
		if (cnt < ans) {
			ans = cnt;
			for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
					int c = p[(i % 4) ^ ((j % 2) * 2)];
					u[i][j] = c;
				}
		}
		if (!next_permutation(p, p + 4)) break;
	}
	for (int i = 0; i < 4; i++) p[i] = i;
	while (1) {
		int cnt = 0;
		for (int j = 0; j < m; j++) {
			int w[2] = {0, 0};
			for (int i = 0; i < n; i++) {
				for (int k = 0; k <= 1; k++) {
					int c = p[(j % 2) * 2 + ((i % 2) ^ k)];
					w[k] += v[i][j] != c;
				}
			}
			cnt += min(w[0], w[1]);
		}
		if (cnt < ans) {
			ans = cnt;
			for (int j = 0; j < m; j++) {
				int w[2] = {0, 0};
				for (int i = 0; i < n; i++) {
					for (int k = 0; k <= 1; k++) {
						int c = p[(j % 2) * 2 + ((i % 2) ^ k)];
						w[k] += v[i][j] != c;
					}
				}
				int k = 0;
				if (w[1] < w[0]) k = 1;
				for (int i = 0; i < n; i++) {
					int c = p[(j % 2) * 2 + ((i % 2) ^ k)];
					u[i][j] = c;
				}
			}
		}
		cnt = 0;
		for (int i = 0; i < n; i++) {
			int w[2] = {0, 0};
			for (int j = 0; j < m; j++) {
				for (int k = 0; k <= 1; k++) {
					int c = p[(i % 2) * 2 + ((j % 2) ^ k)];
					w[k] += v[i][j] != c;
				}
			}
			cnt += min(w[0], w[1]);
		}
		if (cnt < ans) {
			ans = cnt;
			for (int i = 0; i < n; i++) {
				int w[2] = {0, 0};
				for (int j = 0; j < m; j++) {
					for (int k = 0; k <= 1; k++) {
						int c = p[(i % 2) * 2 + ((j % 2) ^ k)];
						w[k] += v[i][j] != c;
					}
				}
				int k = 0;
				if (w[1] < w[0]) k = 1;
				for (int j = 0; j < m; j++) {
					int c = p[(i % 2) * 2 + ((j % 2) ^ k)];
					u[i][j] = c;
				}
			}
		}
		if (!next_permutation(p, p + 4)) break;
	}
//	fprintf(stderr, "%d\n", ans);
	if (!sw) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
				printf("%c", "ACGT"[u[i][j]]);
			puts("");
		}
	} else {
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++)
				printf("%c", "ACGT"[u[j][i]]);
			puts("");
		}
	}
}