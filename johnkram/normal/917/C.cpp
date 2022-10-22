#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define oo 1LL<<60
ll t[256][256];
map<int,int> M;
struct node
{
	ll r,c,a[256][256];
	void operator*=(const node& y)
	{
		int i,j,k;
		for(i=0;i<r;i++)for(j=0;j<y.c;j++)t[i][j]=oo;
		for(i=0;i<r;i++)for(k=0;k<c;k++)if(a[i][k]!=oo)for(j=0;j<y.c;j++)t[i][j]=min(t[i][j],a[i][k]+y.a[k][j]);
		c=y.c;
		for(i=0;i<r;i++)for(j=0;j<c;j++)a[i][j]=t[i][j];
	}
}S,A,F[30];
struct ask
{
	int x,y;
	bool operator<(const ask& b)const
	{
		return x<b.x;
	}
}d[30];
int x,N,n,m,q,i,j,k,l,a[10];
int main()
{
	scanf("%d%d%d%d",&x,&n,&m,&q);
	for(i=1;i<=n;i++)scanf("%d",a+i);
	F[0].r=F[0].c=S.c=N=1<<n;
	S.r=1;
	for(i=0;i<N;i++)S.a[0][i]=oo;
	S.a[0][(1<<x)-1]=0;
	for(i=0;i<N;i++)for(j=0;j<N;j++)F[0].a[i][j]=oo;
	for(i=0;i<N;i++)if(!(i&1))F[0].a[i][i>>1]=0;
	else for(j=1;j<=n;j++)if(!(i>>j&1))F[0].a[i][(i|1<<j)>>1]=a[j];
	for(i=1;1<<i<=m;i++)
	{
		F[i]=F[i-1];
		F[i]*=F[i];
	}
	for(i=1;i<=q;i++)
	{
		scanf("%d%d",&d[i].x,&d[i].y);
		M[d[i].x]=d[i].y;
	}
	sort(d+1,d+q+1);
	for(i=j=1;i<=q;i++)
	{
		if(j<d[i].x-n)
		{
			for(k=d[i].x-n-j,l=0;l<30;l++)if(k>>l&1)S*=F[l];
			j=d[i].x-n;
		}
		for(;j<d[i].x&&j<m-x+1;j++)
		{
			A=F[0];
			for(k=0;k<N;k++)if(k&1)for(l=1;l<=n;l++)if(!(k>>l&1))A.a[k][(k|1<<l)>>1]+=M[j+l];
			S*=A;
		}
	}
	for(k=m-x+1-j,l=0;l<30;l++)if(k>>l&1)S*=F[l];
	cout<<S.a[0][(1<<x)-1]<<endl;
	return 0;
}