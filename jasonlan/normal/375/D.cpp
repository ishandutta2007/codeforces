#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
typedef long long ll;
const int maxn=200100;
int n,m;
int k[maxn],ans[maxn];
int dep[maxn],siz[maxn],son[maxn];
int col[maxn],cnt[maxn],cans[maxn];
vector<int> v[maxn],q[maxn];
inline int read(){
	int res=0;
	char ch=getchar();
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return res;
}
void dfs(int p,int f){
	siz[p]=1;
	for(register int i:v[p]){
		if(i==f)continue;
		dfs(i,p);
		if(siz[i]>siz[son[p]])
			son[p]=i;
		siz[p]+=siz[i];
	}
}
void push(int p,int f){
	++cnt[col[p]];++cans[cnt[col[p]]];
	for(register int i:v[p])
		if(i!=f)push(i,p);
}
void clear(int p,int f){
	--cans[cnt[col[p]]];--cnt[col[p]];
	for(register int i:v[p])
		if(i!=f)clear(i,p);
}
void dfs2(int p,int f){
	for(register int i:v[p])
		if(i!=f&&i!=son[p]){
			dfs2(i,p);
			clear(i,p);
		}
	if(son[p])dfs2(son[p],p);
	for(register int i:v[p])
		if(i!=f&&i!=son[p])push(i,p);
	++cnt[col[p]];++cans[cnt[col[p]]];
	for(register int i:q[p])
		ans[i]=cans[k[i]];
}
int main(){
	n=read();m=read();
	for(register int i=1,x;i<=n;++i)
		col[i]=read();
	for(register int i=1,x,y;i<n;++i){
		x=read();y=read();
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for(register int i=1,x;i<=m;++i){
		q[read()].push_back(i);
		k[i]=read();
	}
	dfs(1,0);
	dfs2(1,0);
	for(register int i=1;i<=m;++i)
		printf("%d\n",ans[i]);
	return 0;
}