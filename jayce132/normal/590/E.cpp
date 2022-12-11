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

const int maxn=750+20;
const int maxlen=1e7+20;

struct node {
	int ch[2],fail,id,father;
};
node t[maxlen];
int ttot=1;

int n;
vector<char>str[maxn];
int be[maxn];

inline int insert(char *S,int n)
{
	int u=1;
	REP(i,0,n-1)
	{
		int &v=t[u].ch[S[i]-'a'];
		if(!v)v=++ttot;
		u=v;
	}
	return u;
}


inline void get_fail()
{
	queue<int>q;
	t[0].ch[0]=t[0].ch[1]=1;
	q.push(1);
	while(!q.empty())
	{
		int u=q.front();q.pop();
		REP(i,0,1)
		{
			int v=t[u].ch[i];
			if(!v)t[u].ch[i]=t[t[u].fail].ch[i];
			else t[v].fail=t[t[u].fail].ch[i],q.push(v),t[v].father=t[t[v].fail].id,t[v].id=t[v].id?t[v].id:t[t[v].fail].id;
		}
	}
}

inline void init()
{
	n=read();
	REP(i,1,n)
	{
		static char S[maxlen];
		scanf("%s",S); int len=strlen(S);
		REP(j,0,len-1)str[i].push_back(S[j]);
		be[i]=insert(S,len);
		t[be[i]].id=i;
	}
	get_fail();
}

int f[maxn][maxn];
int mch[maxn],vis[maxn],to[maxn];

bool dfs(int u)
{
	REP(v,1,n)if(f[u][v] && !vis[v])
	{
		vis[v]=1;
		if(!mch[v] || dfs(mch[v]))
		{
			mch[v]=u;
			return 1;
		}
	}
	return 0;
}

int lvis[maxn],rvis[maxn];

void mark(int u)
{
	lvis[u]=1;
	REP(v,1,n)if(f[u][v] && mch[v]!=u && !rvis[v])
	{
		rvis[v]=1;
		mark(mch[v]);
	}
}

inline void doing()
{
	REP(i,1,n)
	{
		int u=1;
		REP(j,0,SZ(str[i])-1)
		{
			u=t[u].ch[str[i][j]-'a'];
			if(t[u].id)f[i][t[u].id]=1;
		}
		f[i][t[u].father]=1;
		f[i][i]=0;
	}
	REP(k,1,n)REP(i,1,n)REP(j,1,n)f[i][j]|=f[i][k]&f[k][j];
	REP(i,1,n)
	{
		memset(vis,0,sizeof(int)*(n+1));
		dfs(i);
	}
	REP(i,1,n)to[mch[i]]=i;

	REP(i,1,n)if(!to[i])mark(i);
	
	vector<int>ans;
	REP(i,1,n)if(lvis[i] && !rvis[i])ans.push_back(i);
	printf("%d\n",SZ(ans));
	REP(i,0,SZ(ans)-1)printf("%d ",ans[i]);puts("");
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("CF590E.in","r",stdin);
	freopen("CF590E.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}