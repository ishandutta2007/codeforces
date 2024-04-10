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
i64 n,a[N],f[N],m=6,p[N]={0,1,10,100,1000,10000,100000};
inline void Max(i64 &a,i64 b){ if(a<b) a=b; }
void solve(int n,int i)
{
	fr(I,0,30) if(n>>I)
	{
		i64 d=p[i]<<I; i64 D=a[i]<<I;
		fd(j,333333,d) Max(f[j],f[j-d]+D);
		n-=1ll<<I;
	}
	fr(I,0,30) if((n>>I)&1)
	{
		i64 d=p[i]<<I; i64 D=a[i]<<I;
		fd(j,333333,d) Max(f[j],f[j-d]+D);
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
	fr(i,1,333333) f[i]=-1ll<<60;
	f[0]=0;
	fr(i,1,6) solve(std::min(n,333333/p[i]),i);
//	fr(i,1,333333) f[i]=std::max(f[i],f[i-1]);
//	fr(i,1,33) printf("%I64d%c",f[i],i==end_i?'\n':' ');
	fr(i,1,read())
	{
		int p=read(); i64 ans=0;
		fr(j,0,p) if((p-j)%3==0) ans=std::max(ans,calc(j,1)+f[(p-j)/3]);
		printf("%I64d\n",ans);
	}
	return 0;
}