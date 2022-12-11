#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
typedef long long ll;
const int maxn=200100;
int n,m;
int k[maxn],ans[maxn];
int dep[maxn],siz[maxn],son[maxn],f[17][maxn];
int cnt[maxn];
vector<int> v[maxn],q[maxn];
inline int read(){
	int res=0;
	char ch=getchar();
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return res;
}
void dfs(int p){
	siz[p]=1;
	for(register int i=1;i<17;++i)
		f[i][p]=f[i-1][f[i-1][p]];
	for(register int i:v[p]){
		dep[i]=dep[p]+1;
		dfs(i);
		if(siz[i]>siz[son[p]])
			son[p]=i;
		siz[p]+=siz[i];
	}
}
void push(int p){
	++cnt[dep[p]];
	for(register int i:v[p])
		push(i);
}
void clear(int p){
	--cnt[dep[p]];
	for(register int i:v[p])
		clear(i);
}
void dfs2(int p){
	for(register int i:v[p])
		if(i!=son[p]){
			dfs2(i);
			clear(i);
		}
	if(son[p])dfs2(son[p]);
	for(register int i:v[p])
		if(i!=son[p])push(i);
	++cnt[dep[p]];
	for(register int i:q[p])
		ans[i]=cnt[dep[p]+k[i]];
}
int main(){
	n=read();
	for(register int i=1,x;i<=n;++i){
		if(!(x=read()))x=n+1;
		v[x].push_back(i);
		f[0][i]=x;
	}
	f[0][n+1]=n+1;
	dfs(n+1);
	m=read();
	for(register int i=1,rp;i<=m;++i){
		rp=read();k[i]=read();
		for(register int j=0;j<17;++j)
			if((k[i]>>j)&1)rp=f[j][rp];
		if(rp==n+1)ans[i]=1;
		else q[rp].push_back(i);
	}
	dfs2(n+1);
	for(register int i=1;i<=m;++i)
		printf("%d ",ans[i]-1);
	return 0;
}