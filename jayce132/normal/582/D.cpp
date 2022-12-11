#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,a,b) for(int i=(a),_end_=(b);i<=_end_;i++)
#define DREP(i,a,b) for(int i=(a),_end_=(b);i>=_end_;i--)
#define EREP(i,u) for(int i=start[u];i;i=e[i].next)
#define fi first
#define se second
#define mkr(a,b) make_pair(a,b)
#define SZ(A) ((int)A.size())
template<class T>inline void chkmin(T &a,T b){ if(a>b)a=b;}
template<class T>inline void chkmax(T &a,T b){ if(a<b)a=b;}
inline void myassert(bool a,string s){ if(!a)cerr<<s<<endl,exit(0);}
inline int read()
{
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch) && ch!='-')ch=getchar();
	if(ch=='-')ch=getchar(),f=-1;
	while(isdigit(ch))s=s*10+ch-'0',ch=getchar();
	return ~f?s:-s;
}

const int maxn=4e3+20;
const int mod=1e9+7;

int p,m;
int A[maxn],Alen;
int B[maxn],Blen;

inline void init()
{
	p=read();m=read();
	static char str[maxn];
	scanf("%s",str+1); int len=strlen(str+1);
	REP(i,1,len)A[len-i+1]=str[i]-'0'; Alen=len;
	A[0]=-1;
	while(Alen)
	{
		static int g[maxn]={-1};
		ll s=0;
		DREP(i,Alen,1)
		{
			s=s*10+A[i];
			g[i]=s/p;
			s%=p;
		}
		B[++Blen]=s;
		memcpy(A,g,sizeof(g));
		while(!A[Alen])--Alen;
	}
}

int dp[maxn][maxn][2];
int f[maxn][2];

inline void pls(int &a,int b){ a+=b; a-=a>=mod?mod:0;}

inline void doing()
{
	dp[0][0][0]=1;
	REP(i,1,Blen)
	{
		//int x=p-1;
		DREP(j,Blen,0)
		{
			REP(op,0,1)if(dp[i-1][j][op])
			{
				ll num0=((ll)(p+1-op)*(p-op)>>1)%mod,num1=((ll)p*p-num0+mod)%mod;
				dp[i][j][0]=(dp[i][j][0]+(ll)num0*dp[i-1][j][op])%mod;
				dp[i][j+1][1]=(dp[i][j+1][1]+(ll)num1*dp[i-1][j][op])%mod;
			}
		}
	}
	int ans=0;
	f[0][0]=1;
	DREP(i,Blen,1)
	{
		int x=B[i]-(i>1);
		DREP(j,Blen,0)REP(op2,0,1)pls(dp[i-1][j][op2],dp[i-1][j+1][op2]);
		REP(op1,0,1)REP(op2,0,1)
		{
			REP(j,0,Blen)if(f[j][op1])
			{
				int lim=m-j;
				chkmax(lim,0); chkmin(lim,Blen+1);
				int num1=((ll)(x+2-op2)*(x+1-op2)>>1)%mod;
				int res=0;
				if(op1==0)res=num1;else res=((ll)(x+1)*p-num1)%mod;
				ans=(ans+(ll)res*f[j][op1]%mod*dp[i-1][lim][op2])%mod;
				res=0;
			}
		}
		int y=B[i];
		DREP(j,Blen,0)
		{
			int tmp[2]={f[j][0],f[j][1]};f[j][0]=f[j][1]=0;
			REP(op,0,1)
			{
				ll num1=(y+1-op)%mod ,num2=(p-num1)%mod; num1%=mod;
				f[j+op][op]=(f[j+op][op]+(ll)tmp[0]*num1)%mod;
				f[j+op][op]=(f[j+op][op]+(ll)tmp[1]*num2)%mod;
			}
		}
	}
	
	printf("%d\n",ans);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("CF582D.in","r",stdin);
	freopen("CF582D.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}