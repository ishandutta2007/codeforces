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
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch) && ch!='-')ch=getchar();
	if(ch=='-')ch=getchar(),f=-1;
	while(isdigit(ch))s=s*10+ch-'0',ch=getchar();
	return ~f?s:-s;
}

const int maxn=1e3+20;
#define pii pair<int,int>

int n;
vector<int>far[maxn];
bitset<maxn>f[maxn],g[maxn],graph[maxn];
int id[maxn],num[maxn];
int vis[maxn],rec[maxn];
int BESET[maxn],BESETSET[maxn];

inline void CHECK1()
{
	int flg=0;
	REP(i,1,n)if(((int)f[i].count())==n);
	else { flg=1;break;}
	if(!flg)
	{
		REP(i,2,n)printf("%d %d\n",1,i);
		exit(0);
	}
}

inline void init()
{
	n=read();
	REP(i,1,n)
	{
		int k=read();
		while(k--)
		{
			int x=read();
			far[i].push_back(x);
			rec[x]++;
			f[i][x]=1;
		}
	}
	CHECK1();
}

int ok[maxn];

inline void doing()
{
	int notleaf=0;
	REP(i,1,n)REP(j,i+1,n)if((f[i]&f[j]).count()==2)
	{
		bitset<maxn>T=f[i]&f[j];
		int a=T._Find_first(),b=T._Find_next(a);
		if(!graph[a][b])
		{
			printf("%d %d\n",a,b);
			vis[a]=vis[b]=1; ok[a]=ok[b]=1;
			graph[a][b]=graph[b][a]=1;
			graph[a][a]=graph[b][b]=1;
		}
	}
	REP(i,1,n)notleaf+=vis[i];

	REP(i,1,n)
	{
		g[i]=f[i];
		REP(j,1,n)if(!vis[j])g[i][j]=0;
	}
	if(notleaf==2)
	{
		int A=0,B=0;
		REP(i,1,n)if(vis[i])
		{
			if(!A)A=i;
			else B=i;
		}
		int flg=0;
		REP(i,1,n)if((int)f[i].count()!=n)
		{
			int FLG=0;
			for(int x:far[i])
			{
				if(!ok[x])
				{
					if(!flg){ printf("%d %d\n",x,A);ok[x]=1;FLG=1;}
					else { printf("%d %d\n",x,B);ok[x]=1;}
				}
			}
			if(FLG)flg=1;
		}
		exit(0);
	}
	
	REP(i,1,n)if(!vis[i])
	{
		bitset<maxn>tmp;
		int mn=n+1,p=0;
		REP(j,1,n)if(f[j][i] && (int)f[j].count()<mn)mn=(int)f[j].count(),p=j;
		REP(j,1,n)if(f[p][j] && vis[j])tmp.set(j);
		int flg=0;
		REP(j,1,n)if(tmp[j] && tmp==graph[j])
		{ flg=1;printf("%d %d\n",i,j); break;}
		if(!flg)assert(0);
	}
}

/*
  6
4 1 2 3 4
6 1 2 3 4 5 6
5 1 2 3 4 5
5 1 2 3 4 6
3 5 3 2
3 6 4 2*/

int main()
{
#ifndef ONLINE_JUDGE
	freopen("CF566E.in","r",stdin);
	freopen("CF566E.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}