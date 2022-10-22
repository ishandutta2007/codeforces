#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;
const int MAXD = MAXN * 2;
const int inf = 0x3f3f3f3f;

struct Segment_Tree
{
	int tree[MAXD<<2], tag[MAXD<<2];
	#define ls(u) ((u)<<1)
	#define rs(u) ((u)<<1|1)
	#define lson(u) ls(u),l,mid
	#define rson(u) rs(u),mid+1,r
	inline void push_up(int u)
	{
		tree[u] = max(max(tree[ls(u)], tree[rs(u)]), tag[u]);
	}
	void build(int u,int l,int r)
	{
		tree[u] = tag[u] = -inf;
		if(l == r) return;
		int mid = (l+r)>>1;
		build(lson(u)); build(rson(u));
	}
	void update(int u,int l,int r,int ql,int qr,int k)
	{
		if(ql<=l && r<=qr){ tag[u] = max(tag[u], k); tree[u] = max(tree[u], k); return;}
		int mid = (l+r)>>1;
		if(ql<=mid) update(lson(u),ql,qr,k);
		if(mid<qr) update(rson(u),ql,qr,k);
		push_up(u);
	}
	int query(int u,int l,int r,int ql,int qr)
	{
		if(ql<=l && r<=qr) return tree[u];
		int mid = (l+r)>>1;
		if(ql<=mid && mid<qr)
			return max(tag[u], max(query(lson(u),ql,qr), query(rson(u),ql,qr)));
		else
			return max(tag[u], ql<=mid? query(lson(u),ql,qr): query(rson(u),ql,qr));
	}
}tree;

int a[MAXN], b[MAXN], V;

int f[MAXN];
void divid(int l,int r)
{
	if(l == r) return;
	int mid = (l+r)>>1;
	divid(l, mid);
	
	static ll L[MAXN], R[MAXN], dsc[MAXD];
	int dcnt = 0;
	for(int i=l; i<=r; ++i)
	{
		ll t = abs(b[i] - b[mid]);
		dsc[++dcnt] = L[i] = a[i] - t * V;
		dsc[++dcnt] = R[i] = a[i] + t * V + 1;
	}
	sort(dsc+1,dsc+dcnt+1);
	dcnt = unique(dsc+1,dsc+dcnt+1) - dsc - 1;
	tree.build(1,1,dcnt);
	
	for(int i=l; i<=r; ++i)
	{
		int ql = lower_bound(dsc+1,dsc+dcnt+1,L[i]) - dsc;
		int qr = lower_bound(dsc+1,dsc+dcnt+1,R[i]) - dsc - 1;
		if(i <= mid)
			tree.update(1,1,dcnt, ql, qr, f[i]);
		else
			f[i] = max(f[i], tree.query(1,1,dcnt, ql, qr) + 1);
	}
	
	divid(mid+1, r);
}

int main(void)
{
	int n;
	scanf("%d%d",&n,&V);
	for(int i=1; i<=n; ++i) scanf("%d",&b[i]);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	memset(f, 0xc0, (n+1)<<2);
	f[0] = 0;
	divid(0, n);
	
	int ans = 0;
	for(int i=0; i<=n; ++i)
		ans = max(ans, f[i]);
	printf("%d",ans);
	return 0;
}