#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int maxk=24,maxn=101000;
int n,k;
int a[maxn],f[maxn][maxk<<1],g[maxk<<1];
vector <int> v[maxn];
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
void dfs(int p,int fa){
	f[p][0]^=a[p];
	for(int i=0;i<v[p].size();++i){
		if(fa==v[p][i])continue;
		dfs(v[p][i],p);
		for(int j=0;j<(k<<1);++j)
			f[p][(j+1)%(k<<1)]^=f[v[p][i]][j];
	}
}
void dfs2(int p,int fa){
	for(int i=0;i<v[p].size();++i){
		if(fa==v[p][i])continue;
		for(int j=0;j<(k<<1);++j)
			g[(j+2)%(k<<1)]=f[p][(j+1)%(k<<1)]^f[v[p][i]][j];
		for(int j=0;j<(k<<1);++j)
			f[v[p][i]][j]^=g[j];
		dfs2(v[p][i],p);
	}
}
int main(){
	n=read();k=read();
	for(int i=1,x,y;i<n;++i){
		x=read();y=read();
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for(int i=1;i<=n;++i)a[i]=read();
	dfs(1,0);dfs2(1,0);
	for(int i=1,ans;i<=n;++i){
		ans=0;
		for(int j=k;j<(k<<1);++j)ans^=f[i][j];
		printf(ans?"1 ":"0 ");
	}
	return 0;
}