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

const int maxn=420;

int num[maxn][2],tot;

int n,m,L;
char mp[maxn];

/*struct node {
	int v,next;
};
node e[maxn*maxn<<1];
int cnt,start[maxn];
inline void addedge(int u,int v){ e[++cnt]=(node){v,start[u]};start[u]=cnt;}
inline void Addedge(int u,int v){ addedge(u,v); addedge(v^1,u^1);}
*/
vector<int>ed[maxn];
inline void Addedge(int u,int v){ ed[u].push_back(v); ed[v^1].push_back(u^1);}
inline void Del(int u,int v){ ed[u].pop_back(); ed[v^1].pop_back();}

struct Edge {
	int u,v;
};
Edge E[maxn*maxn];

char NB;

char str[maxn];
int SAME;

inline void init()
{
	scanf("%s",mp+1); L=strlen(mp+1);
	NB=mp[1];
	
	n=read();m=read();
	REP(i,1,L)mp[i]=mp[i]==NB?0:1;
	SAME=1;              
	REP(i,1,L)SAME&=mp[i]==0;
	tot=1;
	REP(i,1,n)num[i][0]=++tot,num[i][1]=++tot;
	REP(i,1,m)
	{
		char uc,vc;                    
		int u,v;                       
		scanf("%d %c %d %c\n",&u,&uc,&v,&vc);
		uc=uc==NB?0:1;
		vc=vc==NB?0:1;
		E[i]=(Edge){num[u][uc],num[v][vc]};
	}
	scanf("%s",str+1);
	REP(i,1,n)str[i]-='a'-1;
}

int dfn[maxn],low[maxn],times,COL,id[maxn];

void dfs(int u)
{
	static int st[maxn],top,vis[maxn];
	dfn[u]=low[u]=++times; vis[u]=1; st[++top]=u;
	for(int v:ed[u])
	{
		if(!dfn[v])
		{
			dfs(v);
			chkmin(low[u],low[v]);
		}else if(vis[v])chkmin(low[u],dfn[v]);
	}
	if(dfn[u]==low[u])
	{
		int x; ++COL;
		do{
			x=st[top--];
			id[x]=COL;
			vis[x]=0;
		}while(x!=u);
	}
}

inline bool build(vector<int>A)
{
	if(!SAME)REP(i,1,SZ(A)-1)Addedge(num[i][A[i]^1],num[i][A[i]]);
	else REP(i,1,n)Addedge(num[i][1],num[i][0]);
	times=0; memset(dfn,0,sizeof(int)*(tot+1)); COL=0;
	REP(i,2,tot)if(!dfn[i])dfs(i);
	if(!SAME)REP(i,1,SZ(A)-1)Del(num[i][A[i]^1],num[i][A[i]]);
	else REP(i,1,n)Del(num[i][1],num[i][0]);
	
	REP(i,1,n)if(id[num[i][0]]==id[num[i][1]])return 0;
	return 1;
}

inline void FIND(vector<int>A)
{
	int NOW=SZ(A)-1;
	char ANS[2];
	ANS[0]='a';
	ANS[1]=255;
	REP(i,2,L)if(mp[i]==1){ ANS[1]=i+'a'-1; break;}
	REP(i,NOW+1,n)
	{
		REP(op,0,1)if(ANS[op]!=255)
		{
			A.push_back(op);
			if(build(A)){ printf("%c",ANS[op]); break;}
			else A.pop_back();
		}
	}
}

inline void doing()
{
	
	REP(i,1,m)Addedge(E[i].u,E[i].v);
	DREP(i,n,0)
	{
		vector<int>A(1),B;
		REP(j,1,i)A.push_back(mp[str[j]]);
		if(i==n)
		{
			if(build(A))
			{
				REP(j,1,i)printf("%c",str[j]+'a'-1);
				exit(0);
			}
		}else
		{
			B=A;
			int t0=0,t1=0;
			REP(x,str[i+1]+1,L)
			{
				if(mp[x]==0)
				{
					if(!t0)
					{
						t0=1,A.push_back(0);
						if(build(A))
						{
							REP(j,1,i)printf("%c",str[j]+'a'-1);
							printf("%c",x+'a'-1);
							FIND(A);
							exit(0);
						}
					}
				}else
				{
					if(!t1)
					{
						t1=1,B.push_back(1);
						if(build(B))
						{
							REP(j,1,i)printf("%c",str[j]+'a'-1);
							printf("%c",x+'a'-1);
							FIND(B);
							exit(0);
						}
					}
				}
			}
		}
	}
	puts("-1");
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("CF568C.in","r",stdin);
	freopen("CF568C.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}