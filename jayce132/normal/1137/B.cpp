#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,a,b) for(int i=(a),_end_=(b);i<=_end_;i++)
#define DREP(i,a,b) for(int i=(a),_end_=(b);i>=_end_;i--)
#define EREP(i,a) for(int i=start[(a)];i;i=e[i].next)
template<class T>inline void chkmax(T &a,T b){ if(a<b)a=b;}
template<class T>inline void chkmin(T &a,T b){ if(a>b)a=b;}
#define fi first
#define se second
#define mkr(a,b) make_pair(a,b)
inline int read()
{
	int sum=0,p=1;char ch=getchar();
	while(!(('0'<=ch && ch<='9') || ch=='-'))ch=getchar();
	if(ch=='-')p=-1,ch=getchar();
	while('0'<=ch && ch<='9')sum=sum*10+ch-48,ch=getchar();
	return sum*p;
}

const int maxn=5e5+20;

int n,m,nxt[maxn];
char S[maxn],T[maxn];
int n0,n1,m0,m1;

const int inf=0x3f3f3f3f;

int T1[maxn];

inline void init()
{
	scanf("%s",S+1); scanf("%s",T+1);
	n=strlen(S+1); m=strlen(T+1);
	REP(i,1,n)if(S[i]=='0')n0++;else n1++;
	int j=0;
	REP(i,1,m)T1[i]=T1[i-1]+(T[i]=='1');
	REP(i,2,m)
	{
		while(j && T[j+1]!=T[i])j=nxt[j];
		if(T[j+1]==T[i])nxt[i]=++j;
		else nxt[i]=0;
	}
	m1=T1[m]; m0=m-T1[m];
	if(n0<m0)cout<<(S+1)<<endl,exit(0);
	if(n1<m1)cout<<(S+1)<<endl,exit(0);
	n0-=m0; n1-=m1;
}


inline void doing()
{
	int ans=min(T1[m]?n1/T1[m]:inf,m-T1[m]?n0/(m-T1[m]):inf),pre=0;
	int j=nxt[m];
	
	while(j)
	{
		int u1=T1[m]-T1[j],u0=m-j-u1;
		int res=min(u0?n0/u0:inf,u1?n1/u1:inf);
		if(res>ans)ans=res,pre=j;
		j=nxt[j];
	}
	cout<<(T+1);
	REP(i,1,ans)
	{
		REP(j,pre+1,m)
		{
			printf("%c",T[j]);
			if(T[j]=='0')n0--;
			else n1--;
		}
	}
	REP(j,1,n0)printf("0");
	REP(j,1,n1)printf("1");
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("B.in","r",stdin);
#endif
	init();
	doing();
	return 0;
}