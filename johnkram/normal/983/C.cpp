#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,N,a[2005],b[2005],f[2][1005][10],x[10005],y[10005],i,j,k,l,m,o,p,q;
int A(int x)
{
	if(x<0)return -x;
	return x;
}
int main()
{
	scanf("%d",&n);
	for(i=0;i<n;i++)scanf("%d%d",a+i,b+i);
	memset(f,127,sizeof(f));
	f[0][0][1]=0;
	for(i=0;i<10;i++)for(j=0;j<=i;j++)for(k=0;k<=j;k++)for(l=0;l<=k;l++)x[1000*i+100*j+10*k+l]=N++;
	for(i=0;i<=n;i++)for(memset(f[!(i&1)],127,sizeof(f[!(i&1)])),j=9;~j;j--)for(k=j;~k;k--)for(l=k;~l;l--)for(m=l;~m;m--)for(o=1;o<10;o++)
	{
		p=x[1000*j+100*k+10*l+m];
		if(i<n&&!m)
		{
			if(b[i]>j)q=1000*b[i]+100*j+10*k+l;
			else if(b[i]>k)q=1000*j+100*b[i]+10*k+l;
			else if(b[i]>l)q=1000*j+100*k+10*b[i]+l;
			else q=1000*j+100*k+10*l+b[i];
			q=x[q];
			f[!(i&1)][q][a[i]]=min(f[!(i&1)][q][a[i]],f[i&1][p][o]+A(o-a[i])+1);
		}
		if(j)
		{
			q=x[1000*k+100*l+10*m];
			f[i&1][q][j]=min(f[i&1][q][j],f[i&1][p][o]+A(o-j)+1);
		}
		if(k)
		{
			q=x[1000*j+100*l+10*m];
			f[i&1][q][k]=min(f[i&1][q][k],f[i&1][p][o]+A(o-k)+1);
		}
		if(l)
		{
			q=x[1000*j+100*k+10*m];
			f[i&1][q][l]=min(f[i&1][q][l],f[i&1][p][o]+A(o-l)+1);
		}
		if(m)
		{
			q=x[1000*j+100*k+10*l];
			f[i&1][q][m]=min(f[i&1][q][m],f[i&1][p][o]+A(o-m)+1);
		}
	}
	for(m=2147483647,i=1;i<10;i++)m=min(m,f[n&1][0][i]);
	cout<<m<<endl;
	return 0;
}