#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,in[1005000],d1[1005000],rt,l[1005000],r[1005000],it,dep[1005000],sz[1005000],son[1005000];
vector<int> v[1005000];
bool vis[1005000];
int q[66],ans[66];

struct SB{
	int f[1005000],vis[1005000],it;
	void add(int x,int y){
		for(;x;x-=(-x&x)){
			if(f[x]<0)vis[++it]=x;
			f[x]=max(f[x],y);
		}
	}
	int get(int x,int y=-1e9){
		x=max(x,1);
		for(;x<=n;x+=(-x&x)){y=max(y,f[x]);}return y;
	}
	void clr(){
		while(it){
			f[vis[it]]=-1e9;it--;
		}
	}
}sb;

void dfs0(int x,int fa){
	l[x]=++it;
	sz[x]=1;
	dep[l[x]]=dep[l[fa]]+1;
	for(auto i:v[x]){
		if(i==fa)continue;
		dfs0(i,x);
		sz[x]+=sz[i];
		if(sz[i]>sz[son[x]])son[x]=i;
	}
	r[x]=it;
}

void dfs(int x,int fa,int ty){
	int i,j,k,t1,t2;
	for(auto i:v[x]){
		if(i==fa||son[x]==i)continue;
		dfs(i,x,0);
	}
	if(son[x]){
		dfs(son[x],x,1);
		for(auto i:v[x]){
			if(i==fa||i==son[x])continue;
			for(j=l[i];j<=r[i];j++){
				for(k=1;k<=t;k++){
					while(1){
						t1=sb.get((ans[k]+1)+2*dep[l[x]]-dep[j]);
						if(t1+d1[j]+q[k]>ans[k])ans[k]++;
						else break;
					}
				}
			}
			for(int j=l[i];j<=r[i];j++){
				sb.add(dep[j],d1[j]);
			}
		}
		
		for(k=1;k<=t;k++){
			while(1){
				t1=sb.get((ans[k]+1)+2*dep[l[x]]-dep[l[x]]);
				if(t1+d1[l[x]]+q[k]>ans[k])ans[k]++;
				else break;
			}
		}
	}
	sb.add(dep[l[x]],d1[l[x]]);
	if(!ty)sb.clr();
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(i=2;i<=n;i++){
		cin>>k;
		v[k].push_back(i);
		v[i].push_back(k);
		in[i]++;in[k]++;
	}
	for(i=1;i<=n;i++){
		if(in[i]>1)rt=i;
		sb.f[i]=-1e9;
	}
	cin>>t;
	for(i=1;i<=t;i++)cin>>q[i];
	dfs0(rt,0);
	queue<int> q1;
	for(i=1;i<=n;i++){
		if(in[i]==1){
			q1.push(i);vis[i]=1;
		}
	}
	while(!q1.empty()){
		k=q1.front();q1.pop();
		for(auto i:v[k]){
			if(!vis[i]){
				d1[l[i]]=d1[l[k]]+1;
				vis[i]=1;
				q1.push(i);
			}
		}
	}
	dfs(rt,0,0);
	for(i=1;i<=t;i++)cout<<ans[i]<<' ';
}