#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,vis[500500],cur,lim,dep[500500],qu[500500],it,st[500500];

vector<int> v[500500];
vector<pair<int,int> >res;

bool dfs(int x,int fa){
	vis[x]=1;
	dep[x]=dep[fa]+1;
	if(st[dep[x]]) res.push_back({x,st[dep[x]]}),st[dep[x]]=0;
	else st[dep[x]]=x;
	if(dep[x]==lim)return qu[++it]=x;
	for(auto i:v[x]){
		if(i==fa||vis[i])continue;
		if(dfs(i,x))return qu[++it]=x;
	}
	return 0;
}

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		lim=(n+1)/2;
		memset(vis,0,n*4+50);
		memset(st,0,n*4+50);
		res.clear();
		for(i=1;i<=n;i++){
			v[i].clear();
		}
		for(i=1;i<=m;i++){
			scanf("%d%d",&j,&k);
			v[j].push_back(k);
			v[k].push_back(j);
		}
		it=0;
		dfs(1,0);
		if(it){
			printf("PATH\n%d\n",it);
			for(i=it;i>=1;i--){
				printf("%d ",qu[i]);
			}puts("");
		}
		else{
			printf("PAIRING\n%d\n",res.size());
			for(auto [x,y]:res){
				printf("%d %d\n",x,y);
			}
		}
	}
}