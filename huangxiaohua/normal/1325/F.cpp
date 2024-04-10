#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007

int i,j,k,n,m,vis[200500],vis2[200500],x,y,lim,st[6666],sb;
vector<int> res,v[200500];

void dfs(int x){
	if(x==sb){
		if(m&&m<lim){return;}
		if(m>=lim){
			printf("2\n%d\n",m);
			for(int i=1;i<=m;i++){
				printf("%d ",st[i]);
			}exit(0);
		}
	}
	if(vis[x]){return;}
	st[++m]=x;
	vis[x]=1;
	for(auto i:v[x]){
		dfs(i);
	}
	m--;
}

void dfs0(int x){
	vis[x]=1;
	for(auto i:v[x]){
		if(vis[i]){continue;}
		dfs0(i);
	}
	if(!vis2[x]&&res.size()!=lim){
		res.push_back(x);
		for(auto i:v[x]){
			vis2[i]=1;
		}
	}
}

int main(){
	scanf("%d%d",&n,&m);
	lim=sqrt(n);
	if(lim*lim<n){lim++;}
	for(i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	memset(vis,0,sizeof(vis));m=0;
	res.clear();
	dfs0(1);
	if(res.size()==lim){
		puts("1");
		for(auto i:res){
			printf("%d ",i);
		}return 0;
	}
	memset(vis,0,sizeof(vis));m=0;
	sb=1;
	dfs(1);
	mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count()+1);
	uniform_int_distribution<int>lim(1,n);
	while(1){
		memset(vis,0,sizeof(vis));m=0;
		sb=lim(rng);
		dfs(sb);
	}
}