#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
using namespace std;

const int mod=1e9+7;
int n,m,dis[2000005],ans[2000005],cnt,pre[2000005],ti;
int q[2000005],b,e;
vector<pair<int,int> > adj[2000005];
vector<pair<int,int> > chu;

bool cmp(pair<int,int> x,pair<int,int> y)
{
	return x.second<y.second;
}

void add(int x,int y,int t)
{
	int lst=y;
	while (t)
	{
		int val=t%10;
		t/=10;
		if (t)
		{
			cnt++;
			adj[cnt].push_back(make_pair(lst,val));
			lst=cnt;
		}
		else
		{
			adj[x].push_back(make_pair(lst,val));
		}
	}
}

int main()
{
	int i,j;
	
	scanf("%d%d",&n,&m);
	
	cnt=n;
	rep(i,m)
	{
		int x,y;
		//x=rand()%n+1;y=rand()%n+1;
		scanf("%d%d",&x,&y);
		add(x,y,i);
		add(y,x,i);
	}
	
	memset(dis,0x3f,sizeof(dis));
	q[b=e=1]=1;pre[1]=-1;dis[1]=0;
	ans[1]=0;
	while (b<=e)
	{
		chu.clear();
		ti++;
		int t=b,yangben=q[b];
		while (t<=e&&dis[q[t]]==dis[q[b]]&&pre[q[t]]==pre[q[b]]&&ans[q[t]]==ans[q[b]])
		{
			for (i=0;i<adj[q[t]].size();i++)
			{
				chu.push_back(adj[q[t]][i]);
			}
			t++;
		}
		b=t;
		
		sort(chu.begin(),chu.end(),cmp);
		for (i=0;i<chu.size();i++)
		{
			if (dis[chu[i].first]==0x3f3f3f3f)
			{
				dis[chu[i].first]=dis[yangben]+1;
				pre[chu[i].first]=ti;
				ans[chu[i].first]=(10ll*ans[yangben]+chu[i].second)%mod;
				q[++e]=chu[i].first;
			}
		}
	}
	
	for (i=2;i<=n;i++)
	{
		printf("%d\n",ans[i]); 
	}
	return 0;
}