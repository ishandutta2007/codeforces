#include <bits/stdc++.h>
using namespace std;

int i,j,k,n,m,t,vis[1005000],it;
vector<pair<int,int> >a;
vector<int> v[1005000],res;

void dfs(int x){
	vis[x]=1;
	for(auto i:v[x]){
		if(i==x){res.push_back(a[x].second);return;}
		if(vis[i]){vis[i]=2;it=1;res.push_back(a[x].second);return;}
		dfs(i);
	}
	if(it){res.push_back(a[x].second);}
	if(vis[x]==2){it=0;}
}

int main() {
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);res.clear();it=0;
		a.clear();a.push_back({-1145141919,0});
		for(i=1;i<=n;i++){
			v[i].clear();vis[i]=0;scanf("%d",&k);a.push_back({k,i});
		}
		sort(a.begin(),a.end());k=0;
		for(auto [i,j]:a){v[k].push_back(k-i);k++;}
		dfs(1);
		printf("%d\n",res.size());
		for(auto i:res){printf("%d ",i);}
		puts("");
	}
}