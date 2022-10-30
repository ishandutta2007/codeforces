#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define add() v1[sb].push_back(x);it++;if(it==lim){it=0;sb++;}

int i,j,k,n,m,t,w,it,sb=1,vis[200500],lim;
vector<int> v[200500],v1[200500];

void dfs(int x,int fa){
	vis[x]=1;
	add();
	for(auto i:v[x]){
		if(vis[i]||i==fa)continue;
		dfs(i,x);
		add();
	}
}

int main(){
	scanf("%d%d%d",&n,&m,&t);
	lim=(n+n+t-1)/t;
	for(i=1;i<=m;i++){
		scanf("%d%d",&j,&k);
		v[j].push_back(k);
		v[k].push_back(j);
	}
	dfs(1,0);
	for(i=1;i<=t;i++){
		if(v1[i].empty())printf("1 1");
		else{
			printf("%d ",v1[i].size());
			for(auto j:v1[i])printf("%d ",j);
		}
		puts("");
	}
}