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

const int mod=1e9+7;

const int maxn=2e5+20;

const int seed=191;

int n,s0[maxn];
int s[maxn],p[maxn],S[maxn];
char str[maxn];

inline int Calc(int l,int r)
{
	int len=(s0[r]-s0[l-1]);
	int t=(s[r]-(ll)s[l-1]*p[len]%mod+mod)%mod;
	if(l%2==0)t=(S[len]-t+mod)%mod;
	return t;
}

int main()
{
	n=read();
	scanf("%s",str+1);
	p[0]=1; REP(i,1,n)p[i]=(ll)p[i-1]*seed%mod;
	REP(i,1,n)S[i]=((ll)S[i-1]*seed+3)%mod;
	REP(i,1,n)
	{
		s0[i]=s0[i-1]+(str[i]=='0');
		if(str[i]=='1')s[i]=s[i-1];
		else s[i]=((ll)s[i-1]*seed+((i&1)+1))%mod;
	}
	int q=read();
	REP(i,1,q)
	{
		int a=read(),b=read(),len=read();
		if(s0[a+len-1]-s0[a-1] == s0[b+len-1]-s0[b-1] && Calc(a,a+len-1)==Calc(b,b+len-1))
			puts("YES");
		else puts("NO");
	}
	return 0;
}