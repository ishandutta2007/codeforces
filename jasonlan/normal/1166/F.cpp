#include<iostream>
#include<cstdio>
#include<set>
#include<map>
using namespace std;
const int maxn=101000;
int n,m,c,q;
int fa[maxn];
map <int,int> mp[maxn];
set <int> st[maxn];
inline int read(){
	int res=0;
	char ch=getchar();
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return res;
}
int getf(int x){
	return fa[x]==x?x:(fa[x]=getf(fa[x]));
}
void merge(int u,int v){
	u=getf(u);v=getf(v);
	if(u==v)return;
	if(st[u].size()>st[v].size())swap(u,v);
	set <int>::iterator it=st[u].begin();
	while(it!=st[u].end())st[v].insert(*it),it++;
	fa[u]=v;
}
void add_edge(){
	int u=read(),v=read(),w=read();
	st[getf(u)].insert(v);
	st[getf(v)].insert(u);
	if(mp[u][w])merge(v,mp[u][w]);
	else mp[u][w]=v;
	if(mp[v][w])merge(u,mp[v][w]);
	else mp[v][w]=u;
}
void query(){
	int u=read(),v=read();
	if(getf(u)==getf(v)||st[getf(u)].count(v))puts("Yes");
	else puts("No");
}
int main(){
	n=read();m=read();c=read();q=read();
	for(register int i=1;i<=n;++i)fa[i]=i;
	while(m--)add_edge();
	while(q--){
		char op;cin>>op;
		if(op=='?')query();
		else add_edge();
	}
	return 0;
}