#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 998244353

#define b(x) (1<<((x)-1))
#define N 100500

int i,j,k,n,m,t,l,r,md,res=2e9,it,a[N];
vector<pair<int,int> >v[N];

struct bian{
	int id,l,r,w;
}b[N];

int no,vis[N],wt[N],v2[N];

void dfs0(int u) {
	vis[u]=1;v2[u]=1;
	for(auto [i,j]:v[u]){
		if(j<=md){continue;}
		if(v2[i]){no=1;return;}
		dfs0(i);
	}
	v2[u]=0;
}

bool chk(){
	memset(vis,0,sizeof(vis));
	memset(v2,0,sizeof(vis));
	no=0;
	for(i=1;i<=n;i++){
		if(!vis[i]){dfs0(i);}
	}
	return 1-no;
}

vector<int> ans;

int main() {
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++){
		scanf("%d%d%d",&b[i].l,&b[i].r,&b[i].w);
		v[b[i].l].push_back({b[i].r,b[i].w});
	}
	l=0;r=1e9+5;
	while(l<=r){
		md=(l+r)/2;
		if(chk()){
			res=min(res,md);r=md-1;
		}
		else{
			l=md+1;
		}
	}
	for(i=1;i<=m;i++){
		if(b[i].w>res){a[b[i].r]++;}
	}
	queue<int> q;
	for(i=1;i<=n;i++){
		if(!a[i]){
			wt[i]=++it;q.push(i);
		}
	}
	while(!q.empty()){
		i=q.front();q.pop();
		for(auto [x,y]:v[i]){
			if(wt[x]||y<=res){continue;}
			a[x]--;
			if(!a[x]){
				wt[x]=++it;q.push(x);
			}
		}
	}
	for(i=1;i<=m;i++){
		if(b[i].w>res){continue;}
		if(wt[b[i].l]>wt[b[i].r]){
			ans.push_back(i);
		}
	}
	printf("%d %d\n",res,ans.size());
	for(auto i:ans){
		printf("%d ",i);
	}
}