#include<bits/stdc++.h>
using namespace std;

int i,j,k,n,m,x,y,t,lg[300500],dep[300500],g,mx,sb[300500];
vector<int> v[300500],de[300500];

int depth[300500],fa[300500],siz[300500],head[300500],son[300500],root,cnt,top[300500];

void dfs1(int p,int d,int f){
    depth[p]=dep[p]=d;
    fa[p]=f;
    int maxv=-1;
    siz[p]=1;
    son[p]=0;
    for(auto i:v[p]){
    	if(i!=f){
            dfs1(i,d+1,p);
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

int main(){
	ios::sync_with_stdio(0);
	for(i=1;i<=300000;i++){lg[i]=lg[i>>1]+1;}
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		sb[n+1]=0;
		for(i=1;i<=n;i++){
			v[i].clear();
			de[i].clear();
			sb[i]=0;
		}
		for(i=1;i<n;i++){
			scanf("%d%d",&x,&y);
			v[x].push_back(y);
			v[y].push_back(x);
		}
		dfs1(1,1,1);
		dfs2(1,1);
		mx=0;
		for(i=1;i<=n;i++){
			if(dep[i]>mx)g=i;
			mx=max(mx,dep[i]);
			de[dep[i]].push_back(i);
		}
		for(i=mx;i>=1;i--){
			sb[i]=sb[i+1];
			for(auto j:de[i]){
				g=lca(g,j);
				sb[i]=max(sb[i],i+mx-dep[g]*2);
			}
		}
		int nmsl=0;
		for(i=1;i<=n;i++){
			while(nmsl<mx-1){
				if(i+(sb[nmsl+2]+1)/2>nmsl)nmsl++;
				else break;
			}
			printf("%d ",nmsl);
		}
		puts("");
	}
}//