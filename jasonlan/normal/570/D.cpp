#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
typedef long long ll;
const int maxn=500010;
int n,m;
char s[maxn];
int rt[maxn],qdep[maxn];
int dep[maxn],siz[maxn],son[maxn];
int tnt[maxn][26];
bool ans[maxn];
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
	dep[p]=dep[f]+1;
	for(register int i:v[p]){
		if(i==f)continue;
		dfs(i,p);
		if(siz[i]>siz[son[p]])
			son[p]=i;
		siz[p]+=siz[i];
	}
}
bool check(int d){
	int cnt=0;
	for(register int i=0;i<26;++i)
		cnt+=tnt[d][i]&1;
	return cnt<=1;
}
void push(int p,int f){
	++tnt[dep[p]][s[p]-'a'];
	for(register int i:v[p])
		if(i!=f)push(i,p);
}
void clear(int p,int f){
	tnt[dep[p]][s[p]-'a']=0;
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
	++tnt[dep[p]][s[p]-'a'];
	for(register int i:q[p])
		ans[i]=check(qdep[i]);
}
int main(){
	n=read();m=read();
	for(register int i=2;i<=n;++i)
		v[read()].push_back(i);
	scanf("%s",s+1);
	for(register int i=1,rt;i<=m;++i){
		rt=read();qdep[i]=read();
		q[rt].push_back(i);
	}
	dfs(1,0);
	dfs2(1,0);
	for(register int i=1;i<=m;++i)
		puts(ans[i]?"Yes":"No");
	return 0;
}