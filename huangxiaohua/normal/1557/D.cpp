#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,t,n,m,a[300500],f[300500],nxt[300500],res,vis[300500];

vector<pair<int,int> >v0;
vector<int> v[300500];
set<int> s;

void dfs(int x){
	if(vis[x]){return;}vis[x]=1;
	for(auto i:v[x]){
		dfs(i);
		if(f[i]>f[x]){f[x]=f[i];nxt[x]=i;}
	}
	f[x]++;res=max(res,f[x]);
}

int main(){
	scanf("%d%d",&n,&m);
	s.insert(0);s.insert(11451419);
	for(i=1;i<=m;i++){
		scanf("%d%d%d",&t,&j,&k);
		v0.push_back({j,t});
		v0.push_back({k+1,-t});
	}
	sort(v0.begin(),v0.end());
	for(auto [i,j]:v0){
		if(j<0){if(!--a[-j]){s.erase(-j);}continue;}
		if(!a[j]++){s.insert(j);}
		auto it=s.upper_bound(j);
		if((*it)<=n){v[j].push_back(*it);}
		it--;it--;
		if((*it)){v[*it].push_back(j);}
	}
	for(i=1;i<=n;i++){v[0].push_back(i);}
	dfs(0);
	j=nxt[0];while(j){vis[j]=0;j=nxt[j];}
	printf("%d\n",n-res+1);
	for(i=1;i<=n;i++){if(vis[i]){printf("%d ",i);}}
}