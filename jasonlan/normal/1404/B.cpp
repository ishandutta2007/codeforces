#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=101000;
int n,a,b,da,db; 
int head[maxn],nxt[maxn<<1],rdc[maxn<<1],tnt;
int dis[maxn],mdis[maxn],str;
inline int read(){
    int res=0;
    char ch=getchar(),ch1=ch;
    while(!isdigit(ch))ch1=ch,ch=getchar();
    while(isdigit(ch))res=(res<<1)+(res<<3)+ch-'0',ch=getchar();
    return ch1=='-'?-res:res;
}
void add(int u,int v){
	nxt[++tnt]=head[u];
	head[u]=tnt;
	rdc[tnt]=v;
}
void dfs(int p,int f){
	mdis[p]=dis[p];
	for(register int i=head[p];i;i=nxt[i])
		if(rdc[i]!=f){
			dis[rdc[i]]=dis[p]+1;
			dfs(rdc[i],p);
			str=max(str,mdis[p]+mdis[rdc[i]]-2*dis[p]);
			mdis[p]=max(mdis[p],mdis[rdc[i]]);
		}
}
int main(){
	for(register int T=read();T;--T){
		n=read();a=read();b=read();da=read();db=read();
		for(register int i=1;i<=n;++i)
			head[i]=0;
		for(register int i=1,u,v;i<n;++i){
			u=read();v=read();
			add(u,v);add(v,u);
		}
		if(da*2>=db){
			puts("Alice");continue;
		}
		dis[a]=str=0;
		dfs(a,0);
		if(dis[b]<=da||2*da>=str){
			puts("Alice");continue;
		}
		puts("Bob");
	}
    return 0;
}