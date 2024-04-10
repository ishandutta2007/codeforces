/****************************************************************
*	Author: huhao
*	Email: 826538400@qq.com
*	Create time: 2020-09-17 09:59:39
****************************************************************/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
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
const int N=1<<21|10;
i64 n,a[N],f[N],m=6,p[N]={0,3,30,300,3000,30000,300000};
inline void Max(i64 &a,i64 b){ if(a<b) a=b; }
void solve(int n,int i)
{
	fr(I,0,30) if(n>>I)
	{
		i64 d=p[i]<<I; i64 D=a[i]<<I;
		fd(j,999999,d) Max(f[j],f[j-d]+D);
		n-=1ll<<I;
	}
	fr(I,0,30) if((n>>I)&1)
	{
		i64 d=p[i]<<I; i64 D=a[i]<<I;
		fd(j,999999,d) Max(f[j],f[j-d]+D);
	}
}
i64 calc(i64 a,i64 b)
{
	if(b==7) return 0;
	return calc(a/10,b+1)+(a%10%3==0?a%10/3*::a[b]:0);
}
int main()
{
	n=(read()-1)*3;
	fr(i,1,m) a[i]=read();
	fr(i,1,999999) f[i]=calc(i,1);
	f[0]=0;
	fr(i,1,6) solve(std::min(n,999999/p[i]),i);
	fr(i,1,read())
	{
		int p=read();
		printf("%I64d\n",f[p]);
	}
	return 0;
}