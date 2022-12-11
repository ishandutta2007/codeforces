#include<iostream>
#include<algorithm>
#include<cstdio>
#define mid ((l+r)>>1)
using namespace std;
const int MAXN=200100;
int n,depx;
int head[MAXN],nxt[MAXN<<1],rdc[MAXN<<1];
int size[MAXN],son[MAXN],depth[MAXN],tnt;
int idpoint[MAXN];
inline int read(){
	int res=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return res;
}
void add(int u,int v,int tst){
	nxt[tst]=head[u];
	head[u]=tst;
	rdc[tst]=v;
}
void dfs1(int p,int f){
	depth[p]=depth[f]+1;
	for(register int i=head[p];i;i=nxt[i])
		if(rdc[i]!=f){
			dfs1(rdc[i],p);
			if(!son[p]||size[son[p]]<size[rdc[i]])
				son[p]=rdc[i];
			size[p]+=size[rdc[i]];
		}
	++size[p];
}
int query(char opt,int pos){
	printf("%c %d\n",opt,pos);
	fflush(stdout);
	return read();
}
int fillid(int p){
	int st=0;
	while(son[p]){
		idpoint[st++]=p;
		p=son[p];
	}
	idpoint[st]=p;
	return p;
}
int solve(int pos){
	int bottom=fillid(pos);
	if(bottom==pos)return pos;
	int dep=(depx+depth[bottom]-query('d',bottom))>>1,lca=idpoint[dep-depth[pos]];
	if(depx==depth[lca])return lca;
	else return solve(query('s',lca));
}
int main()
{
    ios::sync_with_stdio(0);
	n=read();
	int a,b;
	for(register int i=1;i<n;++i){
		a=read();b=read();
		add(a,b,(i<<1));add(b,a,(i<<1)+1);
	}
	dfs1(1,0);
	depx=query('d',1)+1;
	printf("! %d",solve(1));
	cout.flush();
	return 0;
}