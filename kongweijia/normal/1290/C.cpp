#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=(a);i<=(n);i++)
#define per(i,a,n) for(int i=(n);i>=(a);i--)

#define pb push_back
#define mp make_pair
#define xx first
#define yy second
#define INF 0x3f3f3f3f

using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> PII;
typedef vector<int> VI;

const int maxn=300000;
//head

char s[maxn+5];
VI lst[maxn+5];
int fa[maxn+5],val[maxn+5];
int v[maxn+5];
PII sz[maxn+5];

int getfa(int x)
{
	if(fa[x]==x) return x;
	int tmp=fa[x];
	fa[x]=getfa(tmp);
	val[x]^=val[tmp];
	return fa[x];
}

int cal(int x)
{
	x=getfa(x);
	if(v[x]==-1) return min(sz[x].xx,sz[x].yy);
	if(v[x]==0) return sz[x].xx;
	if(v[x]==1) return sz[x].yy;
	assert(0);
}

int main()
{
	int n,k; scanf("%d%d",&n,&k);
	scanf("%s",s+1);
	rep(i,1,k)
	{
		int c; scanf("%d",&c);
		while(c--)
		{
			int x; scanf("%d",&x);
			lst[x].pb(i);
		}
	}
	rep(i,1,k) fa[i]=i;
	rep(i,1,k) sz[i]=mp(1,0);
	rep(i,1,k) v[i]=-1;
	int ans=0;
	rep(i,1,n)
	{
		int b=1^(s[i]=='1');
		if(lst[i].size()==1)
		{
			int x=lst[i][0];
			int fx=getfa(x);
			ans-=cal(fx);
			if((val[x]^b)==1) v[fx]=0;
			else v[fx]=1;
			ans+=cal(fx); 
		}
		else if(lst[i].size()==2)
		{
			int x=lst[i][0];
			int y=lst[i][1];
			int fx=getfa(x);
			int fy=getfa(y);
			if(fx!=fy)
			{
				ans-=cal(fx);
				ans-=cal(fy);
				//printf("?? %d: %d, %d,   %d\n",i,fx,fy,ans);
				//printf("!! %d, %d\n",sz[fx].xx,sz[fx].yy);
				//printf("!! %d, %d\n",sz[fy].xx,sz[fy].yy);
				if((b^val[x]^val[y])==0)
				{
					fa[fy]=fx;
					val[fy]=0;
					sz[fx].xx+=sz[fy].xx;
					sz[fx].yy+=sz[fy].yy;
					if(v[fy]!=-1) v[fx]=v[fy];
				}
				else
				{
					fa[fy]=fx;
					val[fy]=1;
					sz[fx].xx+=sz[fy].yy;
					sz[fx].yy+=sz[fy].xx;
					if(v[fy]!=-1) v[fx]=v[fy]^1;
				}
				ans+=cal(fx);
			}
		}
		else assert(lst[i].size()==0);
		printf("%d\n",ans);
	}
    return 0;
}