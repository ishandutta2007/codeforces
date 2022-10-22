#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
#define ll long long
ll ans;
int n,m,xn,y1n,an,bn,i,j,k,t[MAXN];
double x[MAXN],y[MAXN],a[MAXN],b[MAXN],x2[MAXN],y2[MAXN],a2[MAXN],b2[MAXN];
struct node
{
	int x,y,a,b,i;
	bool operator<(const node& z)const
	{
		if(x==z.x)return y<z.y;
		return x<z.x;
	}
}A[MAXN];
bool cmp(node x,node y)
{
	if(x.y==y.y)return x.x<y.x;
	return x.y<y.y;
}
inline void ins(int x,int y)
{
	for(;x<=n;x+=x&-x)t[x]+=y;
}
inline int ask(int x)
{
	int s=0;
	for(;x;x^=x&-x)s+=t[x];
	return s;
}
void work(int l,int r)
{
	if(l==r)return;
	int mid=l+r>>1,i;
	work(l,mid);
	work(mid+1,r);
	sort(A+l,A+r+1,cmp);
	for(i=l;i<=r;i++)if(A[i].i<=mid)ins(n+1-A[i].a,1);
	else ans+=ask(n+1-A[i].a);
	for(i=l;i<=r;i++)if(A[i].i<=mid)ins(n+1-A[i].a,-1);
	for(i=r;i>=l;i--)if(A[i].i<=mid)ins(A[i].b,1);
	else ans+=ask(A[i].b);
	for(i=r;i>=l;i--)if(A[i].i<=mid)ins(A[i].b,-1);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&j,&k);
		x[i]=x2[i]=1.0/j;
		y[i]=y2[i]=(double)k/j;
		a[i]=a2[i]=(double)(k-m)/j;
		b[i]=b2[i]=(double)(k+m)/j;
	}
	sort(x2+1,x2+n+1);
	sort(y2+1,y2+n+1);
	sort(a2+1,a2+n+1);
	sort(b2+1,b2+n+1);
	xn=unique(x2+1,x2+n+1)-x2-1;
	y1n=unique(y2+1,y2+n+1)-y2-1;
	an=unique(a2+1,a2+n+1)-a2-1;
	bn=unique(b2+1,b2+n+1)-b2-1;
	for(i=1;i<=n;i++)
	{
		A[i].x=lower_bound(x2+1,x2+xn+1,x[i])-x2;
		A[i].y=lower_bound(y2+1,y2+y1n+1,y[i])-y2;
		A[i].a=lower_bound(a2+1,a2+an+1,a[i])-a2;
		A[i].b=lower_bound(b2+1,b2+bn+1,b[i])-b2;
		A[i].i=i;
	}
	sort(A+1,A+n+1);
	for(i=1;i<=n;i++)A[i].i=i;
	work(1,n);
	cout<<ans<<endl;
	return 0;
}