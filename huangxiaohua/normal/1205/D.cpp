#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[1050],rt,f[1050],su,it,d[1050],it2;

vector<int> v[1050];
set<pair<int,int> >s;
void dfs(int x,int fa){
	a[x]++;f[x]=fa;
	bool y=1;
	for(auto i:v[x]){
		if(i==fa)continue;
		dfs(i,x);
		if(a[i]>n/2)y=0;
		a[x]+=a[i];
	}
	if(y&&a[x]+a[x]>=n)rt=x;
}

void dfs1(int x,int fa){
	for(auto i:v[x]){
		if(i==fa)continue;
		d[i]=++it;
		printf("%d %d %d\n",x,i,it-d[x]);
		dfs1(i,x);
	}
}

void dfs2(int x,int fa){
	for(auto i:v[x]){
		if(i==fa)continue;
		it2+=it;d[i]=it2;
		printf("%d %d %d\n",x,i,it2-d[x]);
		dfs2(i,x);
	}
}

int main(){
	scanf("%d",&n);
	for(i=1;i<n;i++){
		scanf("%d%d",&j,&k);
		v[j].push_back(k);
		v[k].push_back(j);
	}
	dfs(1,0);
	for(auto i:v[rt]){
		if(i==f[rt])s.insert({a[rt]-n,i});
		else s.insert({-a[i],i});
	}
	n--;
	for(auto [i,j]:s){
		if(su-i<=(n*2/3)){
			printf("%d %d %d\n",j,rt,++it);
			su-=i;
			d[j]=it;
			dfs1(j,rt);
		}
	}
	for(auto [i,j]:s){
		if(!d[j]){
			it2+=it;
			printf("%d %d %d\n",j,rt,it2);
			d[j]=it2;
			dfs2(j,rt);
		}
	}
}