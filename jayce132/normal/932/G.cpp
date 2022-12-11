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

const int maxn=1e6+20;
const int mod=1e9+7;

int n;
char str[maxn],s[maxn];

struct Palineromic_Tree {
	int last,len[maxn],tot,ch[maxn][26],fail[maxn],diff[maxn],top[maxn];
	inline void init(){ len[tot=1]=-1;fail[0]=fail[1]=1;top[1]=top[0]=1;}
	inline void add(int n,char *s){
		int p=last;
		int x=s[n]-'a';
		while(s[n-len[p]-1]!=s[n])p=fail[p];
		if(!ch[p][x])
		{
			int np=++tot,q=fail[p];
			len[np]=len[p]+2;
			while(s[n-len[q]-1]!=s[n])q=fail[q];
			fail[np]=ch[q][x];ch[p][x]=np;
			diff[np]=len[np]-len[fail[np]];
			if(diff[np]==diff[fail[np]])top[np]=top[fail[np]];
			else top[np]=fail[np];
		}
		last=ch[p][x];
	}
}A;

int dp[maxn],g[maxn];

inline void init()
{
	scanf("%s",str+1);
	n=strlen(str+1);
	REP(i,1,n/2)s[i*2-1]=str[i];
	DREP(i,n,n/2+1)s[(n-i+1)*2]=str[i];
	A.init();
	dp[0]=1;
	REP(i,1,n)
	{
		A.add(i,s);
		for(int u=A.last;u>1;u=A.top[u])
		{
			g[u]=dp[i-A.len[A.top[u]]-A.diff[u]];
			if(A.diff[u]==A.diff[A.fail[u]])g[u]=(g[u]+g[A.fail[u]])%mod;
			dp[i]=(dp[i]+g[u])%mod;
		}
		if(i&1)dp[i]=0;
	}
	printf("%d\n",dp[n]);
}


int main()
{
#ifndef ONLINE_JUDGE
	freopen("pp.in","r",stdin);
	freopen("pp.out","w",stdout);
#endif
	init();
 	return 0;
}