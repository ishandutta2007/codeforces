#include <bits/stdc++.h>
using namespace std;

const int maxN = 201000;
const int B = 500;
int cnt[410][(1 << 14) + 10];
int off[maxN], a[maxN], b[maxN], d[maxN], pos[maxN], epos[maxN], spos[maxN];
int n, k, q, zch, m;
vector<int> nch[maxN];

void modify(int p, int v) {
	int l = pos[p], r = epos[p];
	int idl = pos[p] / B, idr = epos[p] / B;
	zch -= (spos[r - 1] ^ off[(r - 1) / B]) == 0;
	if (idl == idr) {
		for (int i = l; i < r; i++) {
			cnt[idl][spos[i]]--;
			spos[i] ^= v;
			cnt[idl][spos[i]]++;
		}
	} else {
		for (int i = l; i < (idl + 1) * B; i++) {
			cnt[idl][spos[i]]--;
			spos[i] ^= v;
			cnt[idl][spos[i]]++;
		}
		for (int i = idl + 1; i < idr; i++) {
			off[i] ^= v;
		}
		for (int i = idr * B; i < r; i++) {
			cnt[idr][spos[i]]--;
			spos[i] ^= v;
			cnt[idr][spos[i]]++;
		}
	}
	zch += (spos[r - 1] ^ off[(r - 1) / B]) == 0;
}

void output() {
	if (zch != k) {
		printf("-1\n");
	} else {
		int answer = 0;
		for (int i = 0; i <= (m - 1) / B; i++)
			answer += cnt[i][off[i]];
		printf("%d\n", m - answer);
	}
}

int main() {
	scanf("%d%d%d", &n, &k, &q);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &b[i]);
	}
	for (int i = 0; i <= n; i++) {
		d[i] = (a[i] ^ a[i + 1]) ^ (b[i] ^ b[i + 1]);
	}
	for (int i = 0; i <= n; i++) {
		nch[i % k].push_back(i);
	}
	m = 0;
	for (int i = 0; i < k; i++) {
		int s = 0;
		for (auto u : nch[i]) {
			s ^= d[u];
			spos[m] = s;
			pos[u] = m++;
		}
		if (spos[m - 1] == 0) zch++;
		for (auto u : nch[i]) {
			epos[u] = m;
		}
	}
	for (int i = 0; i < m; i++) {
		cnt[i / B][spos[i]]++;
	}
	output();

	for (int i = 0; i < q; i++) {
		int p, v;
		char op[5];
		scanf("%s%d%d", op, &p, &v);
		if (op[0] == 'a') {
			a[p] ^= v;
			swap(v, a[p]);
		} else {
			b[p] ^= v;
			swap(v, b[p]);
		}
		modify(p, v);
		modify(p - 1, v);
		output();
	}
}