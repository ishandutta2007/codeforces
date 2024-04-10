#include<bits/stdc++.h>
using namespace std;
#define ll long long
bitset<500> R[500],C[500];
int n,m,i,j,k;
struct node
{
	bitset<500> r[500],c[500];
	void operator*=(const node& y)
	{
		int i,j;
		for(i=0;i<n;i++)R[i]=C[i]=0;
		for(i=0;i<n;i++)for(j=0;j<n;j++)R[i][j]=C[j][i]=(r[i]&y.c[j]).any();
		for(i=0;i<n;i++)
		{
			r[i]=R[i];
			c[i]=C[i];
		}
	}
}a[70][2],A,B;
ll ans;
int main()
{
	scanf("%d%d",&n,&m);
	while(m--)
	{
		scanf("%d%d%d",&i,&j,&k);
		i--;
		j--;
		a[0][k].r[i][j]=a[0][k].c[j][i]=1;
	}
	for(i=0;i<n;i++)if(a[0][0].r[0][i])break;
	if(i==n)
	{
		puts("0");
		return 0;
	}
	for(i=1;i<60;i++)
	{
		for(j=0;j<2;j++)
		{
			a[i][j]=a[i-1][j];
			a[i][j]*=a[i-1][!j];
		}
		for(j=0;j<1;j++)for(k=0;k<n;k++)if(a[i][0].r[j][k])goto yyy;
		break;
		yyy:;
	}
	for(A=a[--i][0],ans=1LL<<i--,m=1;~i;i--)
	{
		B=A;
		B*=a[i][m];
		for(j=0;j<1;j++)for(k=0;k<n;k++)if(B.r[j][k])goto zzz;
		continue;
		zzz:A*=a[i][m];
		ans|=1LL<<i;
		m=!m;
	}
	if(ans>1000000000000000000LL)ans=-1;
	cout<<ans<<endl;
	return 0;
}