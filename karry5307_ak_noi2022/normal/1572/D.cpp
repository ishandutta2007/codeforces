#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>

using namespace std;

int a[1<<20];
int cntbit[1<<20],lg[1<<20];

pair<int,int> E[11000000];vector<pair<int,int> > ton[2100000];

bool used_v[1<<20];vector<int> ed[300],curE;int maxpos[300][2];int eid[1<<20][20];

int fnd(int x,int y){return eid[x][lg[x^y]];}

bool vis[300];int fa[300];
void dfs(int u,int f)
{
	
	vis[u]=1;fa[u]=f;//printf("DFS %d %d %d\n",u,f,fa[u]);
	for(int i=0;i<ed[u].size();i++)if(!vis[ed[u][i]])dfs(ed[u][i],u);
}

int main()
{
	//freopen("CF1572D.in","r",stdin);
	int n=0,k=0;scanf("%d%d",&n,&k);for(int i=0;i<(1<<n);i++)scanf("%d",&a[i]);
	k=min(k,(1<<n)/2);
	lg[0]=-1;for(int i=1;i<(1<<n);i++)cntbit[i]=cntbit[i>>1]+(i&1),lg[i]=lg[i>>1]+1;
	for(int i=0;i<(1<<n);i++)
	{
		if(cntbit[i]&1)
		{
			for(int j=0;j<n;j++)
			{
				ton[a[i]+a[i^(1<<j)]].push_back(make_pair(i,i^(1<<j)));
			}
		}
	}
	int m=0;for(int i=2000000;i>=0;i--)for(int j=0;j<ton[i].size();j++)E[++m]=ton[i][j];
	for(int i=1;i<=m;i++)eid[E[i].first][lg[E[i].first^E[i].second]]=i;
	
	long long ans=0;
	while(k--)
	{
		long long cur=0;int fp=0;for(int i=1;i<=m;i++)if(!used_v[E[i].first]&&!used_v[E[i].second]){cur=a[E[i].first]+a[E[i].second];fp=i;break;}
		
		for(int i=0;i<curE.size();i++)ed[i].clear();
		for(int i=0;i<curE.size();i++)
		{
			maxpos[i][0]=maxpos[i][1]=-1;
			for(int j=0;j<n;j++)
			{
				if(!used_v[E[curE[i]].first^(1<<j)])
				{
					int u=E[curE[i]].first^(1<<j);
					if(maxpos[i][0]==-1||a[u]>a[maxpos[i][0]])maxpos[i][0]=u;
				}
				if(!used_v[E[curE[i]].second^(1<<j)])
				{
					int u=E[curE[i]].second^(1<<j);
					if(maxpos[i][1]==-1||a[u]>a[maxpos[i][1]])maxpos[i][1]=u;
				}
			}
			for(int j=0;j<curE.size();j++)
			{
				if(cntbit[E[curE[i]].second^E[curE[j]].first]==1&&i!=j)ed[i].push_back(j);
			}
		}
		
		long long maxn=-1;int maxi=-1,maxj=-1;
		for(int i=0;i<curE.size();i++)
		{
			if(maxpos[i][0]==-1)continue;
			memset(vis,0,sizeof(vis));dfs(i,-1);//printf("Fa: %d\n",fa[i]);
			for(int j=0;j<curE.size();j++)
			{
				if(!vis[j]||maxpos[j][1]==-1)continue;
				if(a[maxpos[i][0]]+a[maxpos[j][1]]>maxn)maxn=a[maxpos[i][0]]+a[maxpos[j][1]],maxi=i,maxj=j;
			}
		}
		//printf("%lld %d %d\n",maxn,maxi,maxj);
		if(cur>maxn)
		{
			curE.push_back(fp);used_v[E[fp].first]=used_v[E[fp].second]=1;//printf("%d %d\n",E[fp].first,E[fp].second);
			ans+=cur;
		}
		else
		{
			memset(vis,0,sizeof(vis));dfs(maxi,-1);used_v[maxpos[maxi][0]]=used_v[maxpos[maxj][1]]=1;
			curE.push_back(fnd(E[curE[maxi]].first,maxpos[maxi][0])),
			curE.push_back(fnd(maxpos[maxj][1],E[curE[maxj]].second));
			//printf("M: %d %d %d\n",maxi,maxj,fa[0]);
			for(int u=maxj;u!=-1;u=fa[u])
			{
				/*printf("%d\n",u);*/if(u!=maxi)curE.push_back(fnd(E[curE[u]].first,E[curE[fa[u]]].second));
				curE[u]=0;
			}
			sort(curE.begin(),curE.end());reverse(curE.begin(),curE.end());while(curE.back()==0)curE.pop_back();
			ans+=a[maxpos[maxi][0]]+a[maxpos[maxj][1]];
			//printf("%d %d\n",maxpos[maxi][0],maxpos[maxj][1]);
		}
		//for(int i=0;i<curE.size();i++)printf("%d %d\n",E[curE[i]].first,E[curE[i]].second);puts("");
	}
	printf("%d",ans);
}