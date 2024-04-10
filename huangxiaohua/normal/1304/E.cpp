#include<bits/stdc++.h>
using namespace std;

int i,j,k,n,m,x,y,t,lg[1000500],fa[100500][20],dep[100500],t1,t2,t3,sb,sb2;
vector<int> v[100500];

void dfs1(int x,int f){
	fa[x][0]=f;dep[x]=dep[f]+1;
	for(int i=1;i<=lg[dep[x]];i++){
		fa[x][i]=fa[fa[x][i-1]][i-1];
	}
	for(auto i:v[x]){
		if(i==f){continue;}
		dfs1(i,x);
	}
}

int lca(int x, int y) {
	if(dep[x]<dep[y]){swap(x, y);}
	while(dep[x]>dep[y]){x = fa[x][lg[dep[x]-dep[y]] - 1];}
	if(x == y) return x;
	for(int k = lg[dep[x]] - 1; k >= 0; --k)
		if(fa[x][k] != fa[y][k])
			x = fa[x][k], y = fa[y][k];
	return fa[x][0];
}

int main(){
	for(i=1;i<=200000;i++){lg[i]=lg[i>>1]+1;}
	scanf("%d",&n);
	for(i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs1(1,0);
	scanf("%d",&t);
	while(t--){
		int a,b,c,d,e;
		scanf("%d%d%d%d%d",&c,&d,&a,&b,&e);
		sb=lca(a,b);
		t1=dep[a]+dep[b]-dep[sb]*2;
		if(t1<=e&&((t1&1)==(e&1))){
			puts("YES");goto aaa;
		}
		
		sb=lca(a,c);
		sb2=lca(b,d);
		t1=dep[a]+dep[b]+dep[c]+dep[d]-dep[sb]*2-dep[sb2]*2+1;
		if(t1<=e&&((t1&1)==(e&1))){
			puts("YES");goto aaa;
		}
		
		sb=lca(a,d);
		sb2=lca(b,c);
		t1=dep[a]+dep[b]+dep[c]+dep[d]-dep[sb]*2-dep[sb2]*2+1;
		if(t1<=e&&((t1&1)==(e&1))){
			puts("YES");goto aaa;
		}
		puts("NO");
		aaa:;
	}
}