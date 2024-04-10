#include<bits/stdc++.h>
#ifdef LOCAL_PROJECT
#define cerr if(0)cerr
#endif
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
const int mn=2e5+10;
bool vis[mn];
vector<int>g[mn];
void dfs(int x){
	vis[x]=1;
	for(int y:g[x])if(!vis[y])dfs(y);
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
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	int ans=n;
	for(int i=1;i<=n;i++)if(!vis[i])ans--,dfs(i);
	printf("%d",m-ans);
}