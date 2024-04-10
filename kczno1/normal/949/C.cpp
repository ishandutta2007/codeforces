//by kcz 1552920354@qq.com
//if you find any bug in my code
//please tell me
#include<bits/stdc++.h>
using namespace std;

template <typename T> void chmin(T &x,const T &y)
{
	if(x>y)x=y;
}
template <typename T> void chmax(T &x,const T &y)
{
	if(x<y)x=y;
}
typedef long long ll;
typedef pair<int,int> pii;
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
#define pb push_back
#define mp make_pair
#define gc (c=getchar())
char readc()
{
	char c;
	while(gc<'-');
	return c;
}
int read()
{
    char c;
    while(gc<'-');
    if(c=='-')
    {
        int x=gc-'0';
        while(gc>='0')x=x*10+c-'0';
        return -x;
    }
    int x=c-'0';
    while(gc>='0')x=x*10+c-'0';
    return x;
}
#undef gc

const int N=1e5+5;
vector<int>lk[N];
int dfn[N],low[N],tot;
int belong[N];
bool have[N];int cnt[N];int bcnt;

bool in[N];
int st[N],top;
void dfs(int x)
{
	dfn[x]=low[x]=++tot;
	in[x]=1;
	st[++top]=x;
	for(auto y:lk[x])
	{
		if(dfn[y])
		{
			if(in[y])chmin(low[x],low[y]);
			continue;
		}
		dfs(y);
		chmin(low[x],low[y]);
	}
	if(dfn[x]==low[x])
	{
		++bcnt;
		while(1)
		{
			int y=st[top--];
			belong[y]=bcnt;
			++cnt[bcnt];
			in[y]=0;
			if(y==x)break;
		}
	}
}

int main()
{
//	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
	int n=read(),m=read(),h=read();
	static int u[N];
	rep(i,1,n)u[i]=read();
	rep(i,1,m)
	{
		int x=read(),y=read();
		if((u[x]+1)%h==u[y])
		{
			lk[x].pb(y);
		}
		if((u[y]+1)%h==u[x])
		{
			lk[y].pb(x);
		}
	}

	rep(i,1,n)
	if(!dfn[i])dfs(i);

	rep(x,1,n)
	for(auto y:lk[x])
	if(belong[x]!=belong[y])have[belong[x]]=1;
	pii ans=mp(n+1,0);
	rep(i,1,bcnt)
	if(!have[i])chmin(ans,mp(cnt[i],i));
	printf("%d\n",ans.first);
	rep(x,1,n)
	if(belong[x]==ans.second)printf("%d ",x);
}