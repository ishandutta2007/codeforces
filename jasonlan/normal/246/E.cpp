#include<iostream>
#include<cstdio>
#include<vector>
#include<set>
using namespace std;
typedef long long ll;
const int maxn=200100;
int n,m;
string s[maxn];
int qdep[maxn],ans[maxn];
int dep[maxn],siz[maxn],son[maxn];
vector<int> v[maxn],q[maxn];
set<string> st[maxn];
inline int read(){
	int res=0;
	char ch=getchar();
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return res;
}
void dfs(int p,int f){
	siz[p]=1;
	dep[p]=dep[f]+1;
	for(register int i:v[p]){
		if(i==f)continue;
		dfs(i,p);
		if(siz[i]>siz[son[p]])
			son[p]=i;
		siz[p]+=siz[i];
	}
}
void push(int p,int f){
	st[dep[p]].insert(s[p]);
	for(register int i:v[p])
		if(i!=f)push(i,p);
}
void dfs2(int p,int f){
	for(register int i:v[p])
		if(i!=f&&i!=son[p]){
			dfs2(i,p);
			for(register int j=dep[p]+1;st[j].size();++j)
				st[j].clear();
		}
	if(son[p])dfs2(son[p],p);
	for(register int i:v[p])
		if(i!=f&&i!=son[p])push(i,p);
	st[dep[p]].insert(s[p]);
	for(register int i:q[p])
		ans[i]=st[dep[p]+qdep[i]].size();
}
int main(){
	n=read();
	for(register int i=1,x;i<=n;++i){
		cin>>s[i];
		x=read();
		if(!x)x=n+1;
		v[x].push_back(i);
	}
	m=read();
	for(register int i=1,x;i<=m;++i){
		x=read();qdep[i]=read();
		q[x].push_back(i);
	}
	dfs(n+1,0);
	dfs2(n+1,0);
	for(register int i=1;i<=m;++i)
		printf("%d\n",ans[i]);
	return 0;
}