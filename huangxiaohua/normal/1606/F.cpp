#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,res[200500],f[200500],fa[200500],a[200500],dep[200500],it,s[200500];
vector<pair<int,int>> qu[200500];
vector<int> v[200500],son[200500],tmp[200500];
bool vis[200500],vis2[200500],vis3[200500];
priority_queue<int> q;

void dfs0(int x,int FA){
	fa[x]=FA;dep[x]=dep[FA]+1;
	for(auto i:v[x]){
		if(i==FA)continue;
		a[x]++;dfs0(i,x);
	}
}

void dfs(int x,int fa){
	f[x]=a[x];
	for(auto i:v[x]){
		if(i==fa)continue;
		dfs(i,x);
	}
	f[fa]+=max(0,f[x]-1-i);
}

int get(int c,int x){
	vis2[x]=1;
	for(auto i:son[x]){
		if(!vis[dep[i]]){
			vis[dep[i]]=1;q.push(dep[i]);
		}
		tmp[dep[i]].push_back(i);
		vis2[i]=1;
	}
	while(!q.empty()){
		k=q.top();q.pop();
		vis[k]=0;
		for(auto i:tmp[k]){
			vis2[i]=0;
			j=fa[i];
			f[j]+=max(0,a[i]+f[i]-1-c);
			if(!vis3[j]){s[++it]=j;vis3[j]=1;}
			if(!vis2[j]&&(f[j]+a[j])>c){
				vis2[j]=1;
				tmp[dep[j]].push_back(j);
				if(!vis[dep[j]]){
					vis[dep[j]]=1;
					q.push(dep[j]);
				}
			}
			f[i]=0;
		}
		tmp[k].clear();
	}
	vis2[x]=0;
	return f[x]+a[x];
}

int main() {
	#define N 30
	cin.tie(0);
	cin>>n;
	for(i=1;i<n;i++){
		cin>>j>>k;
		v[j].push_back(k);
		v[k].push_back(j);
	}
	dfs0(1,0);
	for(i=1;i<=n;i++){
		if(a[i]>N){
			k=fa[i];
			while(k){
				son[k].push_back(i);k=fa[k];
			}
		}
	}
	cin>>t;
	for(i=1;i<=t;i++){
		cin>>j>>k;
		qu[k].push_back({i,j});
	}
	for(i=0;i<=N;i++){
		dfs(1,0);
		for(auto [x,y]:qu[i]){
			res[x]=f[y];
		}
		memset(f,0,sizeof(f));
	}
	for(i=N+1;i<=200000;i++){
		for(auto [x,y]:qu[i]){
			res[x]=get(i,y);
			while(it){f[s[it]]=vis3[s[it]]=0;it--;}
		}
	}
	for(i=1;i<=t;i++){
		cout<<res[i]<<endl;
	}
}