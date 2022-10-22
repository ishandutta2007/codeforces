#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int n,k,ans,Ans[210000],deg[210000];
vector<pii> vec[210000];
void dfs(int u,int f,int l,int c){
	Ans[l]=c;
	for (pii t:vec[u]){
		if (t.first==f) continue;
		c=c%ans+1;
		dfs(t.first,u,t.second,c);
	}
}
int main(){
	scanf("%d%d",&n,&k);
	int u,v;
	for (int i=1;i<n;i++){
		scanf("%d%d",&u,&v);
		vec[u].push_back(pii(v,i)); deg[u]++;
		vec[v].push_back(pii(u,i)); deg[v]++;
	}
	sort(deg+1,deg+n+1);
	ans=deg[n-k]; printf("%d\n",ans);
	dfs(1,0,0,ans);
	for (int i=1;i<n;i++) printf("%d ",Ans[i]);
	return 0;
}