#include<bits/stdc++.h>
using namespace std;

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

int it,x,y,t,m,j,k,shit;

int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(i=1;i<n;i++){
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs1(1,0,1);
	dfs2(1,1);
	cin>>t;
	
	while(t--){
		x=y=shit=0;
		int mn=1e9;
		cin>>m;
		vector<pair<int,int> > v0;
		for(i=1;i<=m;i++){
			cin>>k;
			v0.push_back({-depth[k],k});
			mn=min(mn,depth[k]);
		}
		sort(v0.begin(),v0.end());
		for(auto [i,j]:v0){
			if(!x){
				x=j;continue;
			}
			if(lca(x,j)!=j){
				if(!y){
					y=j;continue;
				}
				else if(lca(y,j)!=j){
					cout<<"NO\n";goto aaa;
				}
			}
		}
		if(x&&y&&depth[lca(x,y)]>mn){
			cout<<"NO\n";
		}
		else cout<<"YES\n";
		aaa:;
	}
}