#include <bits/stdc++.h>
using namespace std;

const int N = 123456;
const int M = 30;
unordered_map<int, int> sg[N];
int pre[N][M], suf[N][M];
int L[N][M], R[N][M];
int f[N], key[N], w[N], n, q, l, r;
char s[N];
vector<pair<int, int>> rg[N];

void add(int l, int r) {
	rg[r - l].push_back(make_pair(l, r));
}
int find(int x) {
	if (f[x] == x) return x;
	else {
		int y = f[x];
		int z = find(f[x]);
		key[x] ^= key[y];
		f[x] = z;
		return z;
	}
}
int findkey(int x) {
	find(x);
	return key[x];
}

int query(int l, int r, int ty = 0);
int queryL(int l, int sig) {
	if (L[l][sig] != -1) return L[l][sig];
	else return L[l][sig] = query(l, suf[l + 1][sig]);
}
int queryR(int r, int sig) {
	if (R[r][sig] != -1) return R[r][sig];
	else return R[r][sig] = query(pre[r - 1][sig], r);
}

int query(int l, int r, int ty) {
	if (sg[l].count(r)) return sg[l][r];
	if (l + 1 == r) {
		sg[l][r] = 0;
		if (ty) return 0;
		if (w[l] == w[r]) {
			assert(find(l) != find(r));
			f[r] = l;
			key[r] = 0;
		}
		return 0;
	}
	int s = 0;
	for (int sig = 0; sig < 26; sig++) {
		if (suf[l + 1][sig] < r) {
			int val = queryL(l, sig)^queryR(r, sig)^
			          findkey(suf[l + 1][sig])^findkey(pre[r - 1][sig]);
			assert(find(suf[l + 1][sig]) == find(pre[r - 1][sig]));
			s |= (1 << val);
		}
	}
	int a = 0;
	while (s & (1 << a)) a++;
	sg[l][r] = a;
	if (ty) return a;
	if (w[l] == w[r]) {
		assert(find(l) != find(r));
		f[r] = l;
		key[r] = a;
	}
	return a;
}

int main() {
	memset(L, -1, sizeof(L));
	memset(R, -1, sizeof(R));
	scanf("%s", s + 1);
	n = strlen(s + 1);
	for (int i = 1; i <= n; i++) w[i] = s[i] - 'a';
	w[0] = -1;
	w[n + 1] = -2;
	for (int i = 0; i <= n + 1; i++) f[i] = i;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 26; j++)
			pre[i][j] = pre[i - 1][j];
		pre[i][w[i]] = i;
		for (int j = 0; j < 26; j++) add(pre[i][j], i + 1);
	}
	for (int j = 0; j < 26; j++) suf[n + 1][j] = n + 1;
	for (int i = n; i >= 1; i--) {
		for (int j = 0; j < 26; j++)
			suf[i][j] = suf[i + 1][j];
		suf[i][w[i]] = i;
		for (int j = 0; j < 26; j++) add(i - 1, suf[i][j]);
	}
	for (int d = 1; d <= n + 1; d++) {
		for (auto seg : rg[d]) {
			query(seg.first, seg.second);
		}
	}
	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		scanf("%d%d", &l, &r);
		puts(query(l - 1, r + 1, 1) ? "Alice" : "Bob");
	}
}