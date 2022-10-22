#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int maxn = 1e5 + 5;
const int B = 333, nB = maxn / B + 5;

int n, k, a[maxn], q;
int sz[nB];
int nsz[nB], nv[nB][B], psz[nB], pv[nB][B];
bool ok[nB];

void ini(int b) {
	static int stk[maxn];
	int top = 0;
	rep(i, sz[b]) {
		int v = a[b * B + i];
		if (v > 0) stk[top ++] = v;
		else {
			if (top && stk[top - 1] == -v) -- top;
			else stk[top ++] = v;
		}
	}
	int las = 0;
	rep(i, top) if (stk[i] < 0) las = i + 1;
	ok[b] = 1;
	rep(i, las) ok[b] &= stk[i] < 0;
	if (!ok[b]) return ;
	nsz[b] = 0;
	rep(i, las) nv[b][nsz[b] ++] = -stk[las - i - 1];
	psz[b] = 0;
	rep(i, top - las) pv[b][psz[b] ++] = stk[i + las];
}

bool qry(int l, int r) {
	static int stk[maxn];
	int top = 0;
	for (; l < r && l % B; ++ l) {
		if (a[l] > 0) stk[top ++] = a[l];
		else {
			if (top && stk[top - 1] == -a[l]) -- top;
			else return 0;
		}
	}
	for (; l + B < r; l += B) {
		if (!ok[l / B]) return 0;
		if (top >= nsz[l / B] && !memcmp(
			stk + top - nsz[l / B],
			nv[l / B],
			nsz[l / B] * sizeof(int)))
			top -= nsz[l / B];
		else return 0;
		memcpy(stk + top, pv[l / B], psz[l / B] * sizeof(int));
		top += psz[l / B];
	}
	for (; l < r; ++ l) {
		if (a[l] > 0) stk[top ++] = a[l];
		else {
			if (top && stk[top - 1] == -a[l]) -- top;
			else return 0;
		}
	}
	return !top;
}

int main() {
	scanf("%d %d", &n, &k);
	rep(i, n) scanf("%d", &a[i]);
	rep(i, n) sz[i / B] ++;
	rep(i, n / B + 1) ini(i);
	scanf("%d", &q);
	while (q --) {
		int tp; scanf("%d", &tp);
		if (tp == 1) {
			int x, v; scanf("%d %d", &x, &v); -- x;
			a[x] = v; ini(x / B);
		} else {
			int l, r; scanf("%d %d", &l, &r); -- l;
			puts(qry(l, r) ? "Yes" : "No");
		}
	}
	return 0;
}