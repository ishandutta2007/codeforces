#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[200500][2],vis[200500],fa[200500],x[2];
set<pair<ll,int> >s;
ll res;
vector<int> v[200500];

void dfs0(int x,int f){
	fa[x]=f;
	for(auto i:v[x]){
		if(i!=f)dfs0(i,x);
	}
}

void dfs(int x,int f,int rt){
	if(x!=rt){
		vis[x]=1;
		a[rt][1]+=a[x][1];
		a[rt][0]+=a[x][0];
	}
	for(auto i:v[x]){
		if(i!=f&&!vis[i])dfs(i,x,rt);
	}
}

int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d%d%d",&j,&k,&m);
		s.insert({j,i});
		if(k^m){a[i][k]++;x[k]++;}
	}
	if(x[1]!=x[0]){
		puts("-1");return 0;
	}
	for(i=1;i<n;i++){
		scanf("%d%d",&j,&k);
		v[j].push_back(k);
		v[k].push_back(j);
	}
	dfs0(1,0);
	for(auto [i,j]:s){
		if(vis[j])continue;
		dfs(j,fa[j],j);
		k=min(a[j][0],a[j][1]);
		res+=2*i*k;
		a[j][0]-=k;
		a[j][1]-=k;
	}
	
	cout<<res;
}