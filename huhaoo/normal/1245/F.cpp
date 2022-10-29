/****************************************************************
*	Author: huhao
*	Email: 826538400@qq.com
*	Create time: 2019-11-01 22:41:18
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
#define i64 long long
const int L=40;
i64 f[L+5][2][2];
i64& add(i64& a,i64 b)
{
	return a+=b;
}
i64 calc(i64 a,i64 b)
{
	if(a<0||b<0)
		return 0;
	memset(f,0,sizeof(f));
	f[L][0][0]=1;
	fd(i,L-1,0)
		fr(j,0,1)
			fr(k,0,1)
			{
				int J=j||(!!(a&(1ll<<i))),K=k||(!!(b&(1ll<<i)));
				add(f[i][J][K],f[i+1][j][k]);
				if((a&(1ll<<i))||j)
					add(f[i][j][K],f[i+1][j][k]);
				if((b&(1ll<<i))||k)
					add(f[i][J][k],f[i+1][j][k]);
			}
	return f[0][0][0]+f[0][0][1]+f[0][1][0]+f[0][1][1];
}
int main()
{
	int t=read();
	while(t--)
	{
		int l=read(),r=read();
		printf("%I64d\n",calc(r,r)-calc(l-1,r)*2+calc(l-1,l-1));
	}
	return 0;
}