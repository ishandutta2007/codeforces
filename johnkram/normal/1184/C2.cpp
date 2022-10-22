#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1<<21
int n,m,N,M,i,j,k,l1[MAXN],r1[MAXN],l2[MAXN],r2[MAXN],y[MAXN],ans,t[MAXN],t1[MAXN];
vector<int> a;
struct node
{
	int x,l,r,w;
	bool operator<(const node& y)const
	{
		return x<y.x;
	}
}q[MAXN];
void fix(int R,int l,int r,int l1,int r1,int d)
{
	if(l1<=l&&r<=r1)
	{
		t[R]+=d;
		t1[R]+=d;
		return;
	}
	int mid=l+r>>1;
	if(l1<=mid)fix(R<<1,l,mid,l1,r1,d);
	if(r1>mid)fix(R<<1|1,mid+1,r,l1,r1,d);
	t[R]=max(t[R<<1],t[R<<1|1])+t1[R];
}
int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&j,&k);
		l1[i]=j+k-m;
		l2[i]=j-k-m;
		r1[i]=j+k+m;
		r2[i]=j-k+m;
		q[++N].x=l1[i];
		q[N].l=l2[i];
		q[N].r=r2[i];
		q[N].w=1;
		q[++N].x=r1[i]+1;
		q[N].l=l2[i];
		q[N].r=r2[i];
		q[N].w=-1;
		y[++M]=l2[i];
		y[M]=r2[i];
	}
	sort(q+1,q+N+1);
	sort(y+1,y+M+1);
	M=unique(y+1,y+M+1)-y-1;
	for(i=1;i<=N;i=j)
	{
		for(j=i;j<=N&&q[j].x==q[i].x;j++)fix(1,1,M,lower_bound(y+1,y+M+1,q[j].l)-y,lower_bound(y+1,y+M+1,q[j].r)-y,q[j].w);
		ans=max(ans,t[1]);
	}
	cout<<ans<<endl;
	return 0;
}