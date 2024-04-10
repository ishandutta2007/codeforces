#include<bits/stdc++.h>
#ifndef LOCAL_PROJECT
#define cerr if(0)cerr
#endif
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
const ll mod=1e9+7;
const int mn=2e5+10;
int eq[mn];
int a[mn];
vector<int>pwn[mn];
vector<int>g[mn];
bool vis[mn];
int ans;
int dfs(int x){
	vis[x]=1;
	int ret=pwn[x].size();
	for(int y:g[x])if(!vis[y])ret=max(ret,dfs(y));
	return ret;
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
	int n,q;
	cin>>n>>q;
	ans=n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		pwn[a[i]].push_back(i);
	}
	for(int i=0;i<mn;i++)if(pwn[i].size()>=2){
		eq[pwn[i][0]]++,eq[pwn[i].back()]--;
	}
	for(int i=1;i<n;i++)eq[i]+=eq[i-1];
	for(int i=0;i<n-1;i++)if(eq[i])g[a[i]].push_back(a[i+1]),g[a[i+1]].push_back(a[i]);
	for(int i=0;i<mn;i++)if(!vis[i])ans-=dfs(i);
	printf("%d",ans);
}