#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

struct BCJ
{
	int fa[2000],sz[2000];
	void init(int n){for(int i=1;i<=n;i++)fa[i]=i,sz[i]=1;}
	int fnd(int x){return x==fa[x]?x:fa[x]=fnd(fa[x]);}
	void conn(int x,int y){x=fnd(x),y=fnd(y);if(x==y)return;fa[x]=y,sz[y]+=sz[x];}
}B;

vector<int> V;

int main()
{
	int n=0,d=0;scanf("%d%d",&n,&d);B.init(n);
	for(int i=1,x=0,y=0;i<=d;i++)
	{
		scanf("%d%d",&x,&y);B.conn(x,y);
		int cnt=0;V.clear();
		for(int u=1;u<=n;u++)if(B.fnd(u)==u)cnt++,V.push_back(B.sz[u]);//,printf("%d ",B.sz[u]);puts("");
		sort(V.begin(),V.end());
		int ans=0;for(int j=0;j<i-(n-cnt)+1;j++)ans+=V[V.size()-1-j];printf("%d\n",ans-1);
	}
}