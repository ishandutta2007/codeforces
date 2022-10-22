#include<bits/stdc++.h>
using namespace std;
#define MAXN 200005
#define ll long long
int n,m,N,i,j,k,xx,yy,x[MAXN],y[MAXN];
ll a[2][MAXN],b[2][MAXN],l;
void check(int a,int b)
{
	if(a>=0&&a<=n&&b>=0&&b<=m&&(a!=i||b!=j))
	{
		xx=a;
		yy=b;
	}
}
int A(int x)
{
	if(x<0)return -x;
	return x;
}
int main()
{
	scanf("%d%d%d",&n,&m,&N);
	for(i=1;i<=N;i++)scanf("%d%d",x+i,y+i);
	for(i=j=k=l=0;;k=!k)
	{
		if(k)
		{
			check(0,i+j);
			check(i+j,0);
			check(n,i+j-n);
			check(i+j-m,m);
			if(xx>i)
			{
				a[1][i+j]=1;
				b[1][i+j]=2*l+j-i;
			}
			else
			{
				a[1][i+j]=-1;
				b[1][i+j]=2*l+i-j;
			}
		}
		else
		{
			check(0,j-i);
			check(i-j,0);
			check(n,n+j-i);
			check(m+i-j,m);
			if(xx>i)
			{
				a[0][i-j+m]=1;
				b[0][i-j+m]=2*l-i-j;
			}
			else
			{
				a[0][i-j+m]=-1;
				b[0][i-j+m]=2*l+i+j;
			}
		}
		l+=A(xx-i);
		i=xx;
		j=yy;
		if((!i||i==n)&&(!j||j==m))break;
	}
	for(i=1;i<=N;i++)if(!a[0][x[i]-y[i]+m]&&!a[1][x[i]+y[i]])puts("-1");
	else if(!a[0][x[i]-y[i]+m])printf("%I64d\n",a[1][x[i]+y[i]]*(x[i]-y[i])+b[1][x[i]+y[i]]>>1);
	else if(!a[1][x[i]+y[i]])printf("%I64d\n",a[0][x[i]-y[i]+m]*(x[i]+y[i])+b[0][x[i]-y[i]+m]>>1);
	else printf("%I64d\n",min(a[0][x[i]-y[i]+m]*(x[i]+y[i])+b[0][x[i]-y[i]+m],a[1][x[i]+y[i]]*(x[i]-y[i])+b[1][x[i]+y[i]])>>1);
	return 0;
}