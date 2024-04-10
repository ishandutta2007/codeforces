#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

map<int, int> M;
vector<int> a[200002];
int b[1 << 19];
int c[200004];

int get(int i, int j) {
	int r = 0;
	while (i <= j) {
		r = max(r, max(b[i], b[j]));
		i = i + 1 >> 1;
		j = j - 1 >> 1;
	}
	return r;
}

int main() {
	int i, j, k, l, m, n;
	scanf("%d", &n);
	M[0] = 0;
	a[0].push_back(0);
	for (i = 0; i < n; i++) {
		scanf("%d%d", &j, &k);
		M[k] = j;
		a[j].push_back(k);
		b[j | 1 << 18] = k;
	}
	for (j = 1 << 18; --j; b[j] = max(b[j << 1], b[j << 1 | 1]));
	scanf("%d", &m);
	while (m--) {
		scanf("%d", &l);
		for (i = 1; i <= l; i++) scanf("%d", &c[i]);
		sort(c + 1, c + l + 1);
		c[l + 1] = n + 1;
		j = 0;
		for (i = 0; i <= l; i++) j = max(j, get(c[i] + 1 | 1 << 18, c[i + 1] - 1 | 1 << 18));
		k = M[j];
		printf("%d ", k);
		for (i = l + 2; c[i - 1] > k; i--) c[i] = c[i - 1];
		c[i] = k;
		j = 0;
		for (i = 0; i <= l + 1; i++) j = max(j, get(c[i] + 1 | 1 << 18, c[i + 1] - 1 | 1 << 18));
		printf("%d\n", *lower_bound(a[k].begin(), a[k].end(), j));
	}
}