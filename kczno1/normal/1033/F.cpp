#include<bits/stdc++.h>
using namespace std;

#define rep(i,l,r) for(int i=l;i<=r;++i)
const int W=13,S=1<<12;
int w,mi_3[W],sum[S],dy[S];vector<int>sum1;

int need[128][2],nneed[W][2];
char query[W];int ans;
void dfs(int i,int s,int s1)
{
	if(i>=w)
	{
		ans+=sum[s]*sum1[s1];
		return ;
	}
	rep(j,0,1)
	if(nneed[i][j]!=-1)dfs(i+1,s|(j<<i),s1+nneed[i][j]*mi_3[i]);
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);
#endif
	int n,m;
	cin>>w>>n>>m;
	rep(i,1,n)
	{
		int x;
		scanf("%d",&x);
		++sum[x];
	}
	
	mi_3[0]=1;
	rep(i,1,w)mi_3[i]=mi_3[i-1]*3;
	sum1.resize(mi_3[w]);
	
	rep(s,0,(1<<w)-1)
	rep(j,0,w-1)
	if((s>>j)&1)dy[s]+=mi_3[j];
	
	rep(s2,0,(1<<w)-1)
	{
		int i=dy[s2]*2;
		int ns2=(1<<w)-1-s2;
		rep(s,0,(1<<w)-1)sum1[i+dy[s&ns2]]+=sum[s];
	}
	
	need['A'][0]=2;need['A'][1]=0;
	need['O'][0]=0;need['O'][1]=-1;
	rep(i,0,1){need['X'][i]=i;need['x'][i]=i^1;}
	need['a'][1]=1;need['a'][0]=-1;
	need['o'][1]=2;need['o'][0]=1;
	
	while(m--)
	{
		scanf("%s",query);
		reverse(query,query+w);
		rep(i,0,w-1)
		rep(j,0,1)nneed[i][j]=need[query[i]][j];
		ans=0;
		dfs(0,0,0);
		printf("%d\n",ans);
	}
}