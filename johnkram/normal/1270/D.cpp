#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1048576
int n,k,i,j,x,y,z,x0,y0,f[505],g[505],a[505];
int get(int x)
{
	if(f[x]==x)return x;
	return f[x]=get(f[x]);
}
void merge(int x,int y)
{
	x=get(x);
	y=get(y);
	g[x]|=g[y];
	f[y]=x;
}
int main()
{
	scanf("%d%d",&n,&k);
	if(k==1)
	{
		cout<<'!'<<' '<<k<<endl;
		fflush(stdout);
		return 0;
	}
	cout<<'?';
	for(i=1;i<=k;i++)cout<<' '<<i;
	cout<<endl;
	fflush(stdout);
	scanf("%d%d",&x,&y);
	for(i=0;i<=n+1;i++)f[i]=i;
	g[0]=-1;
	g[n+1]=1;
	for(i=1;i<=k;i++)if(i!=x)
	{
		cout<<'?';
		for(j=1;j<=k+1;j++)if(j!=i)cout<<' '<<j;
		cout<<endl;
		fflush(stdout);
		scanf("%d%d",&x0,&y0);
		if(x==x0)merge(k+1,i);
		else if(y0<y)
		{
			merge(n+1,i);
			merge(0,k+1);
		}	
		else
		{
			merge(0,i);
			merge(n+1,k+1);
		}	
	}
	for(i=k+2;i<=n;i++)
	{
		cout<<'?';
		for(j=1;j<=k;j++)if(j!=x%k+1)cout<<' '<<j;
		cout<<' '<<i<<endl;
		fflush(stdout);
		scanf("%d%d",&x0,&y0);
		if(x==x0)merge(x%k+1,i);
		else if(y0<y)
		{
			merge(0,i);
			merge(n+1,x%k+1);
		}	
		else
		{
			merge(n+1,i);
			merge(0,x%k+1);
		}
	}
	for(i=1;i<=n;i++)if(g[get(i)])break;
	if(i>n)
	{
		cout<<'?';
		for(i=1;i<=k+1;i++)if(i!=x)cout<<' '<<i;
		cout<<endl;
		fflush(stdout);
		scanf("%d%d",&x0,&y0);
		cout<<'!'<<' ';
		if(y0<y)cout<<k<<endl;
		else cout<<1<<endl;
	}
	else
	{
		for(i=1;i<=n;i++)a[i]=g[get(i)];
		for(i=j=1;i<=k;i++)if(!~a[i])j++;
		cout<<'!'<<' '<<j<<endl;
	}
	fflush(stdout);
	return 0;
}