/************************************************
*Author        :  demonlover
*Created Time  :  2021.12.20.16:07
*Problem       :  CF1539F
************************************************/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <ctime>
using namespace std;
typedef long long ll;
#define int ll
typedef pair <int,int> pii;
#define DEBUG(x) cout << #x << " = " << x << "\n"
template <typename T>
inline bool read(T &x) {
	int f = 1,c = getchar();x = 0;
	while (!isdigit(c)) {if (c == 45)f = -1;c = getchar();}
	while (isdigit(c))x = (x<<3)+(x<<1)+(c^48),c = getchar();
	return x *= f,true;
}
template <typename T,typename... Args>
inline bool read(T &x,Args &...args) {
	return read(x) && read(args...);
}

namespace run {
	const int maxn = 2e5+10;
	struct segment {
		int l,r,lsum,rsum,sum;
	}tree[maxn<<2];
	inline void pushup(int root) {
		tree[root].sum = tree[root<<1].sum+tree[root<<1|1].sum;
		tree[root].lsum = max(tree[root<<1].lsum,tree[root<<1].sum+tree[root<<1|1].lsum);
		tree[root].rsum = max(tree[root<<1|1].rsum,tree[root<<1|1].sum+tree[root<<1].rsum);
		return;
	}
	inline void build(int root,int l,int r) {
		tree[root].l = l;tree[root].r = r;
		if (l == r)return tree[root].sum = tree[root].lsum = tree[root].rsum = -1,void();
		int mid = (l+r)>>1;
		build(root<<1,l,mid);
		build(root<<1|1,mid+1,r);
		pushup(root);
		return;
	}
	inline void update(int root,int l,int r,int pos,int val) {
		if (l == r)return tree[root].sum = tree[root].lsum = tree[root].rsum = val,void();
		int mid = (l+r)>>1;
		if (pos <= mid)update(root<<1,l,mid,pos,val);
		else update(root<<1|1,mid+1,r,pos,val);
		pushup(root);
		return;
	}
	inline segment query(int root,int l,int r,int al,int ar) {
		if (l > ar || r < al)return (segment){0,0,0,0,0};
		if (al <= l && r <= ar)return tree[root];
		int mid = (l+r)>>1;
		segment u = query(root<<1,l,mid,al,ar),v = query(root<<1|1,mid+1,r,al,ar);
		return (segment){min(u.l,v.l),max(u.r,v.r),max(u.lsum,u.sum+v.lsum),max(v.rsum,v.sum+u.rsum),u.sum+v.sum};
	}
	struct node {int x,id;}a[maxn];
	int n,ans[maxn];
	inline int main() {
		read(n);
		for (int i = 1;i <= n;++i)read(a[i].x),a[i].id = i;
		sort(a+1,a+1+n,[] (node u,node v) {return u.x < v.x;});
		build(1,1,n);
		for (int i = 1;i <= n;++i) {
			int j = i;
			while (j < n && a[j+1].x == a[i].x)++j;
			for (int k = i;k <= j;++k)update(1,1,n,a[k].id,1);
			for (int k = i;k <= j;++k) {
				segment u = query(1,1,n,1,a[k].id),v = query(1,1,n,a[k].id,n);
				ans[a[k].id] = max(ans[a[k].id],u.rsum+v.lsum-2);
			}
			i = j;
		}
		for (int i = 1;i <= n/2;++i)swap(a[i],a[n-i+1]);
		for (int i = 1;i <= n;++i)a[i].x = -a[i].x;
		build(1,1,n);
		for (int i = 1;i <= n;++i) {
			int j = i;
			while (j < n && a[j+1].x == a[i].x)++j;
			for (int k = i;k <= j;++k)update(1,1,n,a[k].id,1);
			for (int k = i;k <= j;++k) {
				segment u = query(1,1,n,1,a[k].id),v = query(1,1,n,a[k].id,n);
				ans[a[k].id] = max(ans[a[k].id],u.rsum+v.lsum-1);
			}
			i = j;
		}
		for (int i = 1;i <= n;++i)printf("%lld ",ans[i]/2);
		return 0;
	}
}

#undef int
int main() {
#ifdef demonlover
	freopen("CF1539F.in","r",stdin);
	freopen("CF1539F.out","w",stdout);
#endif
	return run :: main();
}