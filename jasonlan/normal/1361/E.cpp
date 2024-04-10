#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=200100;
int n,m,rt;
int head[maxn],nxt[maxn],rdc[maxn],tnt;
int ans[maxn],atop;
int dep[maxn],tag[maxn],tup[maxn];
bool inst[maxn],vis[maxn],bad[maxn];
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
void add(int u,int v){
	nxt[++tnt]=head[u];
	head[u]=tnt;
	rdc[tnt]=v;
}
bool dfs(int p){
	inst[p]=vis[p]=true;
	for(register int i=head[p];i;i=nxt[i]){
		if(!vis[rdc[i]]){
			if(!dfs(rdc[i]))return false;
			else continue;
		}
		else if(!inst[rdc[i]])return false;
	}
	inst[p]=false;
	return true;
}
void dfs2(int p){
	inst[p]=true;
	tup[p]=p;
	for(register int i=head[p];i;i=nxt[i])
		if(!inst[rdc[i]]){
			dep[rdc[i]]=dep[p]+1;
			dfs2(rdc[i]);
			tag[p]+=tag[rdc[i]];
			if(dep[tup[p]]>dep[tup[rdc[i]]])
				tup[p]=tup[rdc[i]];
		}
		else{
			++tag[p];--tag[rdc[i]];
			if(dep[tup[p]]>dep[rdc[i]])
				tup[p]=rdc[i];
		}
	if(tag[p]>1)bad[p]=true;
}
void dfs3(int p){
	inst[p]=false;
	if(!bad[p]&&bad[tup[p]])bad[p]=true;
	for(register int i=head[p];i;i=nxt[i])
		if(inst[rdc[i]])dfs3(rdc[i]);
}
int main(){
	srand(20040926);
	for(register int T=read();T;--T){
		n=read();m=read();
		tnt=0;
		for(register int i=1;i<=n;++i)
			head[i]=0;
		for(register int i=0,u,v;i<m;++i){
			u=read();v=read();add(u,v);
		}
		rt=0;
		for(register int i=0,x;i<110;++i){
			x=(1ll*rand()*i)%n+1;
			for(register int j=1;j<=n;++j)
				vis[j]=inst[j]=0;
			if(dfs(x)){
				rt=x;break;
			}
		}
		for(register int i=1;i<=n;++i){
			tag[i]=tup[i]=0;
			dep[i]=0;
			bad[i]=false;
		}
		if(!rt){
			puts("-1");continue;
		}
		dfs2(rt);
		dfs3(rt);
		atop=0;
		for(register int i=n;i;--i)
			if(!bad[i])ans[++atop]=i;
		if(5*atop<n)puts("-1");
		else{
			printf("%d",ans[atop]);
			while(--atop)printf(" %d",ans[atop]);
			putchar('\n');
		}
	}
	return 0;
}