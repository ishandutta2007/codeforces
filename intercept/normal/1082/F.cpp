#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,m,sz=0,num=0,ans=1e9;
int c[509][13],val[509],f[509][509][13],g[509][509][13];
bool vis[509][509];
char s[509];
int read(){
	int rex=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){rex=rex*10+ch-'0';ch=getchar();}
	return rex*f;
}
void insert(int x){
	int u=0,l=strlen(s+1);num+=l*x;
	for(int i=1;i<=l;++i){
		int v=s[i]-'0';
		if(!c[u][v])c[u][v]=++sz;
		u=c[u][v];
		val[u]+=x;
	}
}
void dfs(int u,int dep){
	if(vis[u][dep])return;
	vis[u][dep]=1;
	for(int i=0;i<=9;++i){
		if(!c[u][i])continue;
		dfs(c[u][i],1);
		for(int j=m-1;j>=1;--j){
			for(int k=0;k<=j;++k){
				f[u][dep][j]=max(f[u][dep][j],f[u][dep][k]+f[c[u][i]][1][j-k]);
			}
		}
		dfs(c[u][i],dep+1);
		for(int j=m;j>=1;--j){
			for(int k=0;k<=j;++k){
				g[u][dep][j]=max(g[u][dep][j],g[u][dep][k]+f[c[u][i]][dep+1][j-k]);
			}
		}
	}
	for(int i=m;i>=1;--i)f[u][dep][i]=max(f[u][dep][i-1]+val[u]*dep,g[u][dep][i]);	
}
int main(){
	n=read(),m=read();
	for(int i=1,x;i<=n;++i){
		scanf("%s",s+1);x=read();
		insert(x);
	}
	dfs(0,0);
	printf("%d\n",num-f[0][0][m]);
	return 0;
}