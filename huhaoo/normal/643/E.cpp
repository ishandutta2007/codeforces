/***************************************************************
	File name: 643E.cpp
	Author: huhao
	Create time: Tue 25 Jun 2019 09:43:59 PM CST
***************************************************************/
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
		r=r*10+c-48;
		c=getchar();
	}
	return r*t;
}
const int N=500010,L=60;
double f[N][L+10];
int _f[N],q,n,s[N],t;
int main()
{
	n=1;
	fr(i,0,L)
		f[n][i]=1;
	q=read();
	while(q--)
	{
		int opt=read();
		if(opt==1)
		{
			n++;
			_f[n]=read();
			fr(i,0,L)
				f[n][i]=1.;
			int k=_f[n];
			t=0;
			fr(i,2,L)
			{
				if(!_f[k])
					break;
				s[++t]=k;
				k=_f[k];
			}
			while(t)
			{
				fr(j,0,L)
					f[_f[s[t]]][j]/=0.5+(j==0?0:0.5*f[s[t]][j-1]);
				t--;
			}
			k=n;
			fr(i,1,L)
			{
				if(!_f[k])
					break;
				fr(j,0,L)
					f[_f[k]][j]*=0.5+(j==0?0:0.5*f[k][j-1]);
				k=_f[k];
			}
		}
		else
		{
			int u=read();
			double ans=0;
			fr(i,1,L)
				ans+=i*(f[u][i]-f[u][i-1]);
			printf("%.10lf\n",ans);
		}
	}
	return 0;
}