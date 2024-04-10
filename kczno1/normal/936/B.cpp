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
#define mp make_pair
#define gc (c=getchar())
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
vector<int>lk[N],son[N];
vector<pii>huan;
int fa[N],deep[N];
bool vis[N],in[N];
int ans=-1;
void dfs(int x,int fr,int dep)
{
	vis[x]=1;in[x]=1;
	fa[x]=fr;deep[x]=dep;
	for(auto y:lk[x])
	{
		if(vis[y])
		{
			if(in[y])
			{
				ans=0;
				if((deep[x]-deep[y])%2==0)huan.push_back(mp(y,x));
			}
			else
			{
				son[x].push_back(y);
			}
		}
		else
		{
			son[x].push_back(y);
			dfs(y,x,dep+1);
		}
	}
	in[x]=0;
}
int dp[N][2];
int can[N];int s[N];

int main()
{
//	freopen("1.in","r",stdin);//freopen("1.out","r",stdin);
	int n,m;
	cin>>n>>m;
	rep(i,1,n)
	{
		int c=read();
		while(c--)lk[i].push_back(read());
	}
	int S=read();
	dfs(S,0,0);
	memset(dp,-1,sizeof(dp));
	rep(x,1,n)dp[x][deep[x]%2]=fa[x];
	static int du[N];
	rep(x,1,n)
	for(auto y:son[x])++du[y];
	static int q[N];
	int tail=1;
	q[1]=S;
	rep(head,1,tail)
	{
		int x=q[head];
		if(lk[x].empty())
		{
		if(dp[x][1]!=-1)
		{
			puts("Win");
			static int st[N];
			int top=0;
			bool j=1;
			while(x){st[++top]=x;x=dp[x][j];j^=1;}
			per(i,top,1)printf("%d ",st[i]);
			return 0;
		}
		 can[x]=x;
		}
		for(auto y:son[x])
		{
			rep(j,0,1)
			if(dp[x][j]!=-1&&dp[y][j^1]==-1)dp[y][j^1]=x;
			if(!--du[y])q[++tail]=y;
		}
	}
	per(head,tail,1)
//	for(int head=tail;head;--head)
	{
		int x=q[head];
		for(auto y:son[x])
		if(can[y])
		{
			can[x]=y;
			break;
		}
	}
	rep(head,1,tail)
	{
		int x=q[head];
		s[x]=s[fa[x]]+bool(can[x]);
	}
	for(auto pr:huan)
	{
		int x=pr.first,y=pr.second;
		if(s[y]-s[fa[x]])
		{
			static int ans[N*2];
			int top=0;
			int i=x;
			while(i){ans[++top]=i;i=fa[i];}
			reverse(ans+1,ans+top+1);
			int t1=top;
			i=y;
			while(i!=x){ans[++top]=i;i=fa[i];}
			reverse(ans+t1+1,ans+top+1);
			i=x;
			while(1)
			{
				ans[++top]=i;
				if(can[i]==i)break;
				i=can[i];
			}
			puts("Win");
			rep(i,1,top)printf("%d ",ans[i]);
			return 0;
		}
	}

	if(ans==0)puts("Draw");
	else puts("Lose");
}