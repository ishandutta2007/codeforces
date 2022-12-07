#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<vector>
#include<set>
#include<map>
using std::cin;using std::cerr;
using std::max;using std::min;
#define N 200005
#define mod 1000000007
#define ll long long
#define db double
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
int T,n,m,fac[N],inv[N],f[N][2],tot,tot0,tot1,ans;
int cal(int x) {x-=x<mod?0:mod;return x;}
int C(int x,int y) {return (ll)fac[x]*inv[y]%mod*inv[x-y]%mod;}
int Pow(int x,int y) {int res=1;for(;y;x=(ll)x*x%mod,y>>=1) if(y&1) res=(ll)res*x%mod;return res;}
void clear()
{
	ans=tot0=tot1=0;
}
int main()
{
	fac[0]=inv[0]=inv[1]=1;
	for(int i=1;i<=N-5;i++) fac[i]=(ll)fac[i-1]*i%mod;
	for(int i=2;i<=N-5;i++) inv[i]=(ll)(mod-mod/i)*inv[mod%i]%mod;
	for(int i=2;i<=N-5;i++) inv[i]=(ll)inv[i-1]*inv[i]%mod;
	for(scanf("%d",&T);T--;clear())
	{
		scanf("%d%d",&n,&m),f[0][1]=1,tot=Pow(2,n);
		for(int i=0;i<=n;i++) i&1?tot1=cal(tot1+C(n,i)):tot0=cal(tot0+C(n,i));
		// dbg1(tot),dbg2(tot0);
		for(int i=1;i<=m;i++)
		{
			f[i][0]=(ll)f[i-1][0]*tot%mod;
			if(n&1) f[i][1]=(f[i-1][1]+(ll)f[i-1][1]*tot0)%mod;
			else f[i][0]=cal(f[i][0]+f[i-1][1]),f[i][1]=(ll)f[i-1][1]*(tot0-1)%mod;
			// dbg1(i),dbg1(f[i][0]),dbg2(f[i][1]);
		}
		printf("%d\n",cal(f[m][0]+f[m][1]));
	}
	return 0;
}