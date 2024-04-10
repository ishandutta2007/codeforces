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
template<class T>inline void chkmax(T &a,T b){ if(a<b)a=b;}
template<class T>inline void chkmin(T &a,T b){ if(a>b)a=b;}
inline int read()
{
	int sum=0,p=1;char ch=getchar();
	while(!(('0'<=ch && ch<='9') || ch=='-'))ch=getchar();
	if(ch=='-')p=-1,ch=getchar();
	while('0'<=ch && ch<='9')sum=sum*10+ch-48,ch=getchar();
	return sum*p;
}

const int maxn=1e3+20;

int p[maxn],n,vis[maxn],trash;

inline void init()
{
	n=read();REP(i,1,n)p[i]=read();
	REP(i,1,n)if(p[i]!=i){trash=i;break;}
}

int st[maxn],top;
int s[maxn][maxn],Vis[maxn];

string SS=".\\/";

inline void doing()
{
	int tot=n;
	REP(i,1,n)if(p[i]!=i && !vis[i])
	{
		top=0;
		
		if(i==trash){ Vis[i]=1;for(int j=p[i];j!=i;j=p[j])Vis[j]=1,tot--;continue;}
		if(Vis[i])continue;
		for(int j=i;!vis[j];j=p[j])vis[j]=1,st[++top]=j;

		
		int St=tot;
		REP(j,2,top)
		{
			if(st[j]>st[j-1])s[tot][st[j]]=s[tot][st[j-1]]=2;
			else s[tot][st[j]]=s[tot][st[j-1]]=1;
			tot--;
		}
		if(st[1]!=trash)
		{
			s[tot][st[top]]=1;
			s[tot][trash]=1;
			s[St][trash]=2;
			s[St][st[1]]=2;
			tot--;
		}
	}
	tot=n;top=0;
	for(int j=trash;!vis[j];j=p[j])vis[j]=1,st[++top]=j;
	REP(j,3,top)
	{
		if(st[j]>st[j-1])s[tot][st[j]]=s[tot][st[j-1]]=2;
		else s[tot][st[j]]=s[tot][st[j-1]]=1;
		tot--;
	}

	{
		s[tot][st[top]]=1;
		s[tot][st[1]]=1;
		tot--;
	}
	
	
	printf("%d\n",n-(trash>0));
	DREP(i,n,1)
	{
		REP(j,1,n)printf("%c",SS[s[i][j]]);
		puts("");
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("lasers.in","r",stdin);
	freopen("lasers.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}