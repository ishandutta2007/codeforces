#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define ll long long
using namespace std;
const int P = 1000000007;
ll k, m, n;
template <typename T>
void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-')f=-1;
	for (;isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+(c^48);
	if (f<0) x=-x;
}
const int N = 100500;
struct node{
	int ls, rs;
	int sum;
	#define ls(x) tree[x].ls
	#define rs(x) tree[x].rs
	#define sum(x) tree[x].sum
}tree[N<<5];
int cnt;
int update(int u,int l,int r,int k) {
	int rt = ++cnt;
	tree[rt] = tree[u]; sum(rt)++;
	if (l == r) return rt;
	int mid = (l + r) >> 1;
	if (mid >= k) ls(rt) = update(ls(u), l, mid, k);
	else rs(rt) = update(rs(u), mid + 1, r, k);
	return rt;
}
int query(int u,int v,int l,int r,int ql,int qr) {
	if (l >= ql && r <= qr) return sum(v) - sum(u);
	int mid = (l + r) >> 1;
	int ans = 0;
	if (ql <= mid) ans += query(ls(u), ls(v), l, mid, ql, qr);
	if (qr > mid) ans += query(rs(u), rs(v), mid + 1, r, ql, qr);
	return ans;
}
vector<int> v[N];
int a[N], b[N], T[N];
int l, r, lastans;
int main() {
	read(n), read(k);
	for (int i = 1;i <= n; i++) {
		read(a[i]), v[a[i]].push_back(i);
		b[i] = v[a[i]].size();
	}
	for (int i = 1;i <= n; i++) {
		if (b[i] + k > v[a[i]].size()) b[i] = n + 1;
		else b[i] = v[a[i]][b[i] + k - 1];
		T[i] = update(T[i-1], 1, n + 1, b[i]);
	}
	read(m);
	while (m--) {
		read(l), read(r);
		l = (l + lastans) % n + 1;
		r = (r + lastans) % n + 1;
		if (l > r) swap(l, r);
		printf ("%d\n", lastans = query(T[l-1], T[r], 1, n + 1, r+1, n+1));
	}
	return 0;
}