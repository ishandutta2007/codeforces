#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int t,n,m,b[N],c[N],d[N];
struct node
{
	int x,ord;
}a[N];
bool cmp(node x,node y) {if(x.x!=y.x) return x.x<y.x; else return x.ord<y.ord;}
#define rt 1,1,n
#define lc 2*k
#define rc 2*k+1
#define ls lc,l,mid
#define rs rc,mid+1,r
int minn[N<<2],tag[N<<2];
void change(int k,int l,int r,int v)
{
	minn[k]+=v;tag[k]+=v;
}
void pushdown(int k,int l,int r,int mid)
{
	if(!tag[k]) return;
	change(ls,tag[k]);change(rs,tag[k]);
	tag[k]=0;
}
void pushup(int k)
{
	minn[k]=min(minn[lc],minn[rc]);
}
void build(int k,int l,int r)
{
	if(l==r) {minn[k]=l-1;tag[k]=0;return;}
	int mid=l+r>>1;
	build(ls);build(rs);
	pushup(k);
}
void update(int k,int l,int r,int ql,int qr,int v)
{
	if(qr<l||ql>r) return;
	if(ql<=l&&qr>=r) {change(k,l,r,v);return;}
	int mid=l+r>>1;
	pushdown(k,l,r,mid);
	update(ls,ql,qr,v);update(rs,ql,qr,v);
	pushup(k);
}
int tr[N];
void update(int x)
{
	for(;x<=n;x+=x&(-x)) tr[x]++;
}
int query(int x)
{
	int res=0;
	for(;x;x-=x&(-x)) res+=tr[x];
	return res;
}

int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++) scanf("%d",&a[i].x),c[i]=a[i].x,a[i].ord=i;
        a[++n].x=1e9+1;
        a[n].ord=n;
        c[n]=1e9+1;
        for(int i=1;i<=4*n+5;i++) tag[i]=minn[i]=0;
        for(int i=1;i<=n+5;i++) tr[i]=0;
		for(int i=1;i<=m;i++) scanf("%d",&b[i]);
		sort(c+1,c+n+1);
		int tmp=unique(c+1,c+n+1)-c-1;
		for(int i=1;i<=n;i++) d[i]=lower_bound(c+1,c+tmp+1,a[i].x)-c,a[i].x=d[i];
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			ans+=i-1-query(d[i]);
			update(d[i]);
		}
		sort(b+1,b+m+1);
		build(rt);
        sort(a+1,a+n+1,cmp);
        int Now=1,NowAns=0;
        for(int i=1;i<=m;i++)
        {
            if(b[i]==b[i-1]) 
            {
                ans+=NowAns;
                continue;
            }
            NowAns=0;
            int Rank=lower_bound(c+1,c+tmp+1,b[i])-c;
            while(Now!=n+1 && a[Now].x<Rank)
            {
                update(rt,a[Now].ord+1,n,-2);
                Now++;
            }
            NowAns=(Now-1)+minn[1];
            while(Now!=n+1 && a[Now].x==Rank && b[i]>=c[Rank])
            {
                update(rt,a[Now].ord+1,n,-2);
                Now++;
                NowAns=min(NowAns,(Now-1)+minn[1]);
            }
            ans+=NowAns;
            // printf("NowAns=%d\n",NowAns);
        }
		printf("%lld\n",ans);
	}
}