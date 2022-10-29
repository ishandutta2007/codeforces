#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<assert.h>
#define i64 long long
#define fr(i,a,b) for(int i=(a),end_##i=(b);i<=end_##i;i++)
#define fd(i,a,b) for(int i=(a),end_##i=(b);i>=end_##i;i--)
int read()
{
	int r=0,t=1,c=getchar();
	while(c<'0'||c>'9'){ t=c=='-'?-1:1; c=getchar(); }
	while(c>='0'&&c<='9'){ r=r*10+c-48; c=getchar(); }
	return r*t;
}
const int N=2100,mod=998244353;
int n,m;
i64 C[N*2][N*2];
i64 Q(i64 a,i64 b){ return a>=0&&b>=0?C[a+b][a]:0; }
i64 A(int n,int m)
{
	i64 ans=0;
//	return 0;
	fr(i,1,n-1)
	{
		static i64 a[N];
		fr(j,2,m) a[j]=Q(i,j-2)*Q(i-1,m-j)%mod;
		fr(j,2,m) a[j]=(a[j]+a[j-1])%mod;
		fr(j,3,m) ans=(ans+a[j-1]*Q(n-i-1,j)%mod*Q(n-i,m-j))%mod;
	}
	return ans;
}
i64 B(int n,int m)
{
	i64 ans=0;
	fr(i,1,n-1) fr(j,2,m) ans=(ans+Q(i,j-2)*Q(i-1,m-j)%mod*Q(n-i-1,j)%mod*Q(n-i,m-j))%mod;
//	fr(i,1,n-1) fr(j,2,m) printf("%d %d  %d %d %d %d\n",i,j,Q(i,j-2),Q(i-1,m-j),Q(n-i-1,j),Q(n-i,m-j));
	return ans;
}
int main()
{
	n=read(); m=read();
	fr(i,0,N*2-10)
	{
		C[i][0]=C[i][i]=1;
		fr(j,1,i-1) C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
	}
	printf("%I64d\n",(A(n,m)+A(m,n)+B(n,m))*2%mod);
	return 0;
}