#include <bits/stdc++.h>
using namespace std;
//typedef long long ll;
const int mn = 1 << 17;
int seg[26][mn*2], laz[26][mn*2],sz[mn*2];
#define mid (l+r>>1)
void prop(int q,int x) {
	if (x >= mn||laz[q][x]==-1) { laz[q][x] = -1; return; }
	laz[q][2 * x] = laz[q][2 * x + 1] = laz[q][x];
	seg[q][2 * x] = seg[q][2 * x + 1] = (laz[q][2 * x]!=0)*sz[2*x];
	laz[q][x] = -1;
}
void st(int q,int x, int a, int b, int c, int l, int r) {
	if (a == l && b == r) { seg[q][x] = (laz[q][x] = c)*sz[x]; return; }
	prop(q, x);
	if (b <= mid)st(q, x * 2, a, b, c, l, mid);
	else if (a > mid)st(q, x * 2 + 1, a, b, c, mid + 1, r);
	else st(q, x * 2, a, mid, c, l, mid), st(q, x * 2 + 1, mid + 1, b, c, mid + 1, r);
	seg[q][x] = seg[q][x * 2] + seg[q][x * 2 + 1];
}
int qu(int q, int x, int a, int b, int l, int r) {
	if (a == l && b == r)return seg[q][x];
	prop(q, x);
	if (b <= mid)return qu(q, x * 2, a, b,  l, mid);
	else if (a > mid)return qu(q, x * 2 + 1, a, b,  mid + 1, r);
	else return qu(q, x * 2, a, mid,  l, mid)+ qu(q, x * 2 + 1, mid + 1, b,  mid + 1, r);
}
int am[26];
int main() {
	string s;
	int n, q,i,j;
	scanf("%d%d", &n, &q);
	cin >> s;
	sz[1] = mn;
	for (i = 2; i < 2 * mn; i++)sz[i] = sz[i >> 1] >> 1;
	memset(laz, -1, sizeof(laz));
	for (i = 0; i < n; i++)s[i] -= 'a',st(s[i],1,i+1,i+1,1,1,mn);
	int a, b, c;
	while (q--) {
		scanf("%d%d%d", &a, &b, &c);
		for (i = 0; i < 26; i++)am[i] = qu(i, 1, a, b, 1, mn);
		int cur=a;
		if (c)for (i = 0; i < 26; i++) {
			st(i, 1, a, b, 0, 1, mn);
			if(am[i])st(i, 1, cur, cur + am[i] - 1, 1, 1, mn), cur += am[i];
		}
		else for (i = 25; i >=0; i--) {
			st(i, 1, a, b, 0, 1, mn);
			if (am[i])st(i, 1, cur, cur + am[i] - 1, 1, 1, mn), cur += am[i];
		}
	}
	for (i = 1; i <= n; i++) {
		for (j = 0; j < 26; j++)if (qu(j, 1, i, i, 1, mn))printf("%c", j + 'a');
	}
	getchar(); getchar();
}