#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
const int mn=4e5+10;
vector<int>g[mn];
vector<int>ans;
bool vis[mn];
int val[mn];
void dfs(int x){
	vis[x]=1;
	val[x]=1;
	for(int y:g[x]){
		if(!vis[y])dfs(y);
		val[x]=max(val[x],val[y]+1);
	}
	if(val[x]>=3)ans.push_back(x),val[x]=0;
}
int main(){
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
		freopen("error.txt","w",stderr);
	#else
		cin.tie(0);
		cin.sync_with_stdio(0);
	#endif
	int tc;
	cin>>tc;
	while(tc--){
		int n,m;
		cin>>n>>m;
		ans.clear();
		for(int i=1;i<=n;i++)vis[i]=0,val[i]=1;
		for(int i=1;i<=n;i++)g[i].clear();
		for(int i=0;i<m;i++){
			int a,b;
			cin>>a>>b;
			g[b].push_back(a);
		}
		for(int i=n;i>=1;i--)if(!vis[i])dfs(i);
		printf("%d\n",ans.size());
		for(int x:ans)printf("%d ",x);
		printf("\n");
	}
}