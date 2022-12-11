#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
typedef long long ll;
const int maxn=100010;
int n;
int siz[maxn],son[maxn];
int c[maxn],tnt[maxn],mx;
ll mcnt,ans[maxn];
vector<int> v[maxn];
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
void add(int x){
	++tnt[x];
	if(tnt[x]>mx){
		mx=tnt[x];mcnt=x;
	}
	else if(tnt[x]==mx)
		mcnt+=x;
}
void push(int p,int f){
	add(c[p]);
	for(register int i:v[p])
		if(i!=f)push(i,p);
}
void clear(int p,int f){
	tnt[c[p]]=0;
	for(register int i:v[p])
		if(i!=f)clear(i,p);
}
void dfs2(int p,int f){
	for(register int i:v[p])
		if(i!=f&&i!=son[p]){
			dfs2(i,p);
			mx=mcnt=0;clear(i,p);
		}
	if(son[p])dfs2(son[p],p);
	for(register int i:v[p])
		if(i!=f&&i!=son[p])push(i,p);
	add(c[p]);
	ans[p]=mcnt;
}
int main(){
	n=read();
	for(register int i=1;i<=n;++i)
		c[i]=read();
	for(register int i=1,x,y;i<n;++i){
		x=read();y=read();
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1,0);
	dfs2(1,0);
	for(register int i=1;i<=n;++i)
		printf("%lld ",ans[i]);
	return 0;
}