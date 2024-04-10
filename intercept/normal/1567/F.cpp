#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[509*509];
char c[509][509];
vector<int>g[509*509];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int id(int x,int y){return (x-1)*m+y;}
void add(int x,int y){
	g[x].push_back(y);
	g[y].push_back(x);
}
void dfs(int u,int fa){
	if(a[fa]==1)a[u]=4;
	else a[u]=1;
	for(auto v:g[u]){
		if(!a[v])dfs(v,u);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%s",c[i]+1);
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(c[i][j]=='X'){
				int num=(c[i-1][j]=='.')+(c[i+1][j]=='.')+(c[i][j-1]=='.')+(c[i][j+1]=='.');
				if(num%2){
					puts("NO");
					return 0;
				}
				a[id(i,j)]=5*num/2;
				if(num==2){
					int x=0,y=0;
					for(int k=0;k<4;++k){
						int ni=i+dx[k],nj=j+dy[k];
						if(c[ni][nj]=='.'){
							if(x)y=id(ni,nj);
							else x=id(ni,nj);
						}
					}
					add(x,y);
				}
				if(num==4){
					add(id(i-1,j),id(i,j-1));
					add(id(i-1,j),id(i,j+1));
					add(id(i+1,j),id(i,j-1));
					add(id(i+1,j),id(i,j+1));
				}
			}
		}
	}
	puts("YES");
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(!a[id(i,j)]&&c[i][j]=='.')dfs(id(i,j),0);
			printf("%d%c",a[id(i,j)]," \n"[j==m]);
		}
	}
	return 0;
}