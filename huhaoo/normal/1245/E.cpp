/****************************************************************
*	Author: huhao
*	Email: 826538400@qq.com
*	Create time: 2019-11-01 23:11:13
****************************************************************/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
#define fr(i,a,b) for(int i=(a),end_##i=(b);i<=end_##i;i++)
#define fd(i,a,b) for(int i=(a),end_##i=(b);i>=end_##i;i--)
int read()
{
	int r=0,t=1,c=getchar();
	while(c<'0'||c>'9')
	{
		t=c=='-'?-1:1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		r=(r<<3)+(r<<1)+(c^48);
		c=getchar();
	}
	return r*t;
}
const int N=1010;
int id[N][N],t[N],I,n;
double f[N];
int main()
{
	n=10;
	fr(i,1,n)
		if(i&1)
			fr(j,1,n)
			{
				I++;
				id[i][j]=I;
			}
		else
			fd(j,n,1)
			{
				I++;
				id[i][j]=I;
			}
	fd(i,n,1)
		fr(j,1,n)
			t[id[i][j]]=id[i+read()][j];
	fr(i,2,n)
	{
		f[id[n][i]]=1;
		fr(j,1,min(i-1,6))
			f[id[n][i]]+=f[id[n][i-j]]/6;
		if(i<=6)
			f[id[n][i]]=f[id[n][i]]*6/(i-1);
	}
	fd(i,(n-1)*n,1)
	{
		f[i]=1;
		fr(j,1,6)
			f[i]+=min(f[i+j],f[t[i+j]])/6;
	}
	printf("%.10lf\n",f[1]);
	return 0;
}