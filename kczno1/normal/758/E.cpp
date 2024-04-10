#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,l,r) for(int i=l;i<=r;++i)
const int N=2e5+5,D=1e9+7;
int n;ll mn[N],mx[N],del[N];
int fa[N],w[N],p[N];
int ey[N];
vector<int>son[N];
#define forson(i,x) for(vector<int>::iterator i=son[x].begin();i!=son[x].end();++i)
bool dp(int x)
{
	forson(i,x)
	{
		int y=*i;
		if(dp(y))return 1;
		mn[x]+=w[y]-min(w[y]-1LL,p[y]-mn[y])+mn[y];
		mx[x]+=w[y]+mx[y];
	}
	
	if(x==1)return 0;
	
	if(mn[x]>p[x]) return 1;
	if(mx[x]>p[x])
	{
		del[x]=mx[x]-p[x];
		mx[x]=p[x];
	}
	return 0;
}

void dfs(int x)
{
	forson(i,x)
	{
		int y=*i;
		ll now=min(del[x],mx[y]-mn[y]);
		del[x]-=now;del[y]+=now;
		
		int ed=min(del[x],min(w[y]-1LL,p[y]-(mx[y]-now)));
		del[x]-=ed;
		w[y]-=ed;p[y]-=ed;
		
		dfs(y);
	}
}

int main()
{
    scanf("%d",&n);
    rep(i,1,n-1) 
    {
    	int x,y;
    	scanf("%d%d",&x,&y);
    	ey[i]=y;
    	fa[y]=x;son[x].push_back(y);
    	scanf("%d%d",w+y,p+y);
    }
    if(dp(1))puts("-1");
    else
    {
    	dfs(1);
    	printf("%d\n",n);
    	rep(i,1,n-1)
    	{
    		int y=ey[i];
    		printf("%d %d %d %d\n",fa[y],y,w[y],p[y]);
    	}
    }
    //printf("%d\n",n);
}