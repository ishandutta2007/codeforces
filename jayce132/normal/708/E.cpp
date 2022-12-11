#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<vector>
using namespace std;
#define ll long long
#define REP(i,a,b) for(int i=(a),_end_=(b);i<=_end_;i++)
#define DREP(i,a,b) for(int i=(a),_end_=(b);i>=_end_;i--)
#define EREP(i,a) for(int i=start[(a)];i;i=e[i].next)
inline int read()
{
	int sum=0,p=1;char ch=getchar();
	while(!(('0'<=ch && ch<='9') || ch=='-'))ch=getchar();
	if(ch=='-')p=-1,ch=getchar();
	while('0'<=ch && ch<='9')sum=sum*10+ch-48,ch=getchar();
	return sum*p;
}

const int mod=1e9+7;
const int maxn=1e4+20;

inline int power(int a,int b)
{
	int ans=1;
	while(b)
	{
		if(b&1)ans=(ll)ans*a%mod;
		b>>=1;
		a=(ll)a*a%mod;
	}
	return ans;
}

int n,m,p,t;
int down[maxn],jc[maxn],jcn[maxn],inv[maxn];
int ds[maxn];

inline int C(int n,int m){ return (ll)jc[n]*jcn[m]%mod*jcn[n-m]%mod;}

inline void init()
{
	n=read();m=read();
	int a=read(),b=read();
	p=(ll)a*power(b,mod-2)%mod;
	t=read();
	
	jc[0]=jc[1]=jcn[0]=jcn[1]=inv[1]=1;
	REP(i,2,m+1)inv[i]=(ll)(mod-mod/i)*inv[mod%i]%mod,jc[i]=(ll)i*jc[i-1]%mod,jcn[i]=(ll)inv[i]*jcn[i-1]%mod;

	int C=1;
	REP(i,0,m)if(i<=t)down[i]=(ll)power(p,i)*power(1+mod-p,t-i)%mod*C%mod,C=(ll)C*(t-i)%mod*inv[i+1]%mod; else break;
	int tmp=0; REP(i,0,m-1)tmp=(tmp+down[i])%mod; down[m]=(1-tmp+mod)%mod;
	
	ds[0]=down[0]; REP(i,1,m)ds[i]=(ds[i-1]+down[i])%mod;
}

int g[1520][maxn],s[1520][1520],s1[1520][1520];

inline void doing()
{
	g[0][m]=1;
	REP(i,1,m)s[0][i]=(s[0][i-1]+g[0][i])%mod,s1[0][i]=(s1[0][i-1]+(ll)s[0][i]*down[i])%mod;
	REP(i,1,n)
	{
		REP(r,1,m)
		{
			g[i][r]=(ll)down[m-r]*((ll)ds[r-1]*s[i-1][m]%mod-(ll)ds[r-1]*s[i-1][m-r]%mod-s1[i-1][r-1]+mod*2)%mod;
			s[i][r]=(s[i][r-1]+g[i][r])%mod;
			s1[i][r]=(s1[i][r-1]+(ll)s[i][r]*down[r])%mod;
		}
	}
	printf("%d\n",s[n][m]);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("shot.in","r",stdin);
	freopen("shot.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}