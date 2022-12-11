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
inline int read()
{
	int s=0,f=1; char ch=getchar();
	while(!isdigit(ch) && ch!='-')ch=getchar();
	if(ch=='-')ch=getchar(),f=-1;
	while(isdigit(ch))s=s*10+ch-'0',ch=getchar();
	return ~f?s:-s;
}

const int mod=998244353;
int inv[50020],jc[50020],jcn[50020];

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

inline int C(int n,int m){ if(n<0 || n<m)return 0;return 1ll*jc[n]*jcn[m]%mod*jcn[n-m]%mod;}

int n,m,r;

inline void init()
{
	jc[0]=jc[1]=jcn[0]=jcn[1]=inv[1]=1;
	REP(i,2,5e4)inv[i]=(ll)(mod-mod/i)*inv[mod%i]%mod,jc[i]=(ll)jc[i-1]*i%mod,jcn[i]=(ll)jcn[i-1]*inv[i]%mod;
	n=read();m=read();r=read();
}

inline void doing()
{
	int ans=0,fas=0;
	fas=C(m-r+n-1,n-1);
//REP(x,r,m)fas=(fas+C(m-x+n-2,n-2))%mod;
	REP(x,r,m)
	{
		REP(num,1,n)if(num*x<=m)
		{
			int rest=m-num*x,renum=n-num,xs=(ll)inv[num]*C(n-1,num-1)%mod;

			if(renum==0)
			{
				if(rest==0)ans=(ans+xs)%mod;
			}
			else
			{
				REP(j,0,n-num)
				{
					int re=rest-j*x;
					if(re>=0)ans=(ans+(j&1?-1:1)*(ll)C(re+renum-1,renum-1)*xs%mod*C(renum,j))%mod;
				}
			}
		}
	}
	ans=(ans+mod)%mod;
	ans=(ll)ans*power(fas,mod-2)%mod;
	printf("%d\n",ans);
}

int main()
{
	init();
	doing();
	return 0;
}