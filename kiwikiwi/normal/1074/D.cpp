#include <bits/stdc++.h>
using namespace std;

const int maxN = 423456;

int q, t, l, r, x, m;
int f[maxN], key[maxN];
map<int, int> cnt;
int addIndex(int x) {
	if (!cnt.count(x)) {
		cnt[x] = m;
		f[m] = m;
		key[m] = 0;
		m++;
	}
	return cnt[x];
}

int find(int x) {
	if (f[x] == x) {
		return x;
	} else {
		int y = f[x];
		f[x] = find(f[x]);
		key[x] ^= key[y];
		return f[x];
	}
}

void access(int x) {
	if (x == f[x]) return;
	key[f[x]] = key[x];
	key[x] = 0;
	f[f[x]] = x;
	f[x] = x;
}
void add(int l, int r, int x) {
	if (find(l) == find(r)) return;
	access(l);
	access(r);
	key[r] = x;
	f[r] = l;
}

int main() {
	scanf("%d", &q);
	int last = 0;
	for (int i = 0; i < q; i++) {
		scanf("%d", &t);
		if (t == 1) {
			scanf("%d%d", &l, &r);
			l ^= last; r ^= last;
			if (l > r) swap(l, r);
			l = addIndex(l - 1);
			r = addIndex(r);
			scanf("%d", &x);
			x ^= last;
			add(l, r, x);
		} else {
			scanf("%d%d", &l, &r);
			l ^= last; r ^= last;
			if (l > r) swap(l, r);
			l = addIndex(l - 1);
			r = addIndex(r);
			if (find(l) != find(r)) {
				printf("-1\n");
				last = 1;
			} else {
				last = key[l] ^ key[r];
				printf("%d\n", last);
			}
		}
	}
}