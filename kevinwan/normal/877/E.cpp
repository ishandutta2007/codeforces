#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxn 262144
vector<int> g[200001];
int seg[1 << 19], laz[1 << 19],a[maxn],tr[maxn],s[maxn];
int cnt = 0,sz;
void dfs(int x) {
	tr[x] = cnt++,s[x]=1;
	for (int y : g[x])dfs(y), s[x] += s[y];
}
int nd(int a) {
	return ((laz[a]) ? (sz - seg[a]) : (seg[a]));
}
void u(int a, int b) {
	a += maxn, b += maxn;
	int aa = a, bb = b;
	while (b > a) {
		if (a & 1)laz[a] ^= 1, a++;
		if (!(b & 1))laz[b] ^= 1, b--;
		a >>= 1, b >>= 1;
	}
	if (a == b)laz[a] ^= 1;
	sz = 1;
	for (aa >>= 1,bb>>=1; aa; aa >>= 1,bb>>=1,sz<<=1)seg[aa] = nd(aa * 2) + nd(aa * 2 + 1),seg[bb]=nd(bb*2)+nd(bb*2+1);
}
int q(int a, int b) {
	a += maxn, b += maxn;
	int i;
	for (i = 18; i; i--)if (laz[a >> i])laz[a >> i] = 0, laz[(a >> i) * 2] ^= 1, laz[(a >> i) * 2 + 1]^=1, seg[a >> i] = (1 << i) - seg[a >> i];
	for (i = 18; i; i--)if (laz[b >> i])laz[b >> i] = 0, laz[(b >> i) * 2] ^= 1, laz[(b >> i) * 2 + 1]^=1, seg[b >> i] = (1 << i) - seg[b >> i];
	int ans=0;
	sz = 1;
	while (b > a) {
		if (a & 1)ans+=nd(a), a++;
		if (!(b & 1))ans += nd(b), b--;
		a >>= 1, b >>= 1,sz<<=1;
	}
	if (a == b)ans += nd(a);
	return ans;
}
int main() {
	int n,qq,x,i;
	scanf("%d", &n);
	for (i = 2; i <= n; i++)scanf("%d", &x), g[x].push_back(i);
	for (i = 1; i <= n; i++)scanf("%d", a+ i);
	dfs(1);
	for (i = 1; i <= n; i++)seg[tr[i] + maxn]=a[i];
	for (i = maxn - 1; i; i--)seg[i] = seg[i * 2] + seg[i * 2 + 1];
	scanf("%d", &qq);
	while (qq--) {
		string ss;
		cin >> ss;
		scanf("%d", &x);
		if (ss[0] == 'g')printf("%d\n", q(tr[x], tr[x] + s[x] - 1));
		else u(tr[x], tr[x] + s[x] - 1);
	}
	getchar(); getchar();
}