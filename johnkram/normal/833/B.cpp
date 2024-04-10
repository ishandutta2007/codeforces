#include<bits/stdc++.h>
using namespace std;
int n,m,N,i,a[35005],f[55][35005],ne[35005],d[35005],lc[1<<20],rc[1<<20],s[1<<20],root[35005];
bool b[35005];
void fix(int &R,int R1,int l,int r,int x)
{
	R=++N;
	s[R]=s[R1]+1;
	if(l==r)return;
	int mid=l+r>>1;
	if(x<=mid)
	{
		fix(lc[R],lc[R1],l,mid,x);
		rc[R]=rc[R1];
	}
	else
	{
		fix(rc[R],rc[R1],mid+1,r,x);
		lc[R]=lc[R1];
	}
}
int ask(int R,int l,int r,int x)
{
	if(!R)return 0;
	if(l==x)return s[R];
	int mid=l+r>>1;
	if(x>mid)return ask(rc[R],mid+1,r,x);
	return s[rc[R]]+ask(lc[R],l,mid,x);
}
void work(int d,int l,int r,int l1,int r1)
{
	if(l>r)return;
	int mid=l+r>>1,i=min(mid,r1),j,k;
	if(r1<mid)j=ask(root[mid],1,n+1,mid+1)-ask(root[r1],1,n+1,mid+1);
	else j=0;
	for(;i>=l1;i--)
	{
		if(ne[i]>mid)j++;
		if(f[d-1][i-1]+j>f[d][mid])
		{
			f[d][mid]=f[d-1][i-1]+j;
			k=i;
		}
	}
	for(i=l1;i<=mid;i++)b[a[i]]=0;
	work(d,l,mid-1,l1,k);
	work(d,mid+1,r,k,r1);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%d",a+i);
		f[1][i]=f[1][i-1]+!b[a[i]];
		b[a[i]]=1;
	}
	memset(b,0,sizeof(b));
	for(i=1;i<=n;i++)d[i]=n+1;
	for(i=n;i;i--)
	{
		ne[i]=d[a[i]];
		d[a[i]]=i;
	}
	for(i=1;i<=n;i++)fix(root[i],root[i-1],1,n+1,ne[i]);
	for(i=2;i<=m;i++)work(i,1,n,1,n);
	cout<<f[m][n]<<endl;
	return 0;
}