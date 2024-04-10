#include<bits/stdc++.h>
using namespace std;

int i,j,k,n,m,t,a[200500],col[200500],it,del[200500],pos[200500],in[200500];
vector<int> v0[200500];
vector<int> v3[200500];
map<pair<int,int>,int>mp; 

struct SB{
	int depth[2000500],fa[2000500],siz[2000500],head[2000500],son[2000500],root,cnt,top[2000500],n,i;
	vector<int> v[2005000];
	void dfs1(int p,int dep,int f){
	    depth[p]=dep;
	    fa[p]=f;
	    int maxv=-1;
	    siz[p]=1;
	    for(auto i:v[p]){
	    	if(i!=f){
	            dfs1(i,dep+1,p);
	            siz[p]+=siz[i];
	            if(siz[i]>maxv){
	                maxv=siz[i];
					son[p]=i;
	            }
	        }
		}
	}
	void dfs2(int p,int tp){
	    top[p]=tp;
	    if(!son[p]){return;}
	    dfs2(son[p],tp);
	    for(auto i:v[p]){
	    	if(i!=fa[p]&&i!=son[p]){
	    		dfs2(i,i);
			}
		}
	}
	int lca(int x,int y){
	    while(top[x]!=top[y]){
	    	if(depth[top[x]]>=depth[top[y]]){
				x=fa[top[x]];
			}
	        else{
				y=fa[top[y]];
			}
		}
	    return depth[x]<depth[y]?x:y;
	}
	void fuck(int l,int r){
		vector<int> v1,v2;
		int i,j,k=lca(l,r);
		while(l!=k){
			v1.push_back(mp[{l,fa[l]}]);
			l=fa[l];
		}
		while(r!=k){
			v2.push_back(mp[{r,fa[r]}]);
			r=fa[r];
		}
		reverse(v2.begin(),v2.end());
		for(auto i:v2)v1.push_back(i);
		j=0;
		for(auto i:v1){
			if(j){
				v3[j].push_back(i);
				in[i]++;
			}
			j=i;
		}
	}
}sb;

int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a[i];
		pos[a[i]]=i;
	}
	for(i=1;i<=n;i++){
		if(col[i])continue;
		j=i;it++;
		while(!col[j]){
			v0[it].push_back(j);
			col[j]=it;
			j=a[j];
		}
	}
	for(i=1;i<=m;i++){
		cin>>j>>k;
		mp[{j,k}]=mp[{k,j}]=i;
		sb.v[j].push_back(k);
		sb.v[k].push_back(j);
	}
	for(i=1;i<=it;i++){
		if(v0[i].size()==1)continue;
		int rt=v0[i][0];
		sb.dfs1(rt,0,rt);
		sb.dfs2(rt,rt);
		for(auto j:v0[i]){
			sb.fuck(pos[j],j);
		}
	}
	queue<int> q;
	for(i=1;i<=m;i++)if(!in[i])q.push(i);
	while(!q.empty()){
		k=q.front();q.pop();
		cout<<k<<' ';
		for(auto i:v3[k]){
			if(in[i]){
				in[i]--;
				if(!in[i])q.push(i);
			}
		}
	}
}