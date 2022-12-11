#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
const int maxn=501000;
int n,m,col[maxn],dis[maxn];
int head[maxn],nxt[maxn],rdc[maxn],type[maxn],tnt;
bool vis[maxn];
queue <int> q;
inline int read(){
    int res=0;
    char ch=getchar(),ch1=ch;
    while(!isdigit(ch))ch1=ch,ch=getchar();
    while(isdigit(ch))res=res*10+ch-'0',ch=getchar();
    return ch1=='-'?-res:res;
}
void add(int u,int v,int z){
	nxt[++tnt]=head[u];
	head[u]=tnt;
	rdc[tnt]=v;
	type[tnt]=z;
} 
void spfa(){
	q.push(n);vis[n]=1;col[n]=0;
	while(q.size()){
		int p=q.front();
		q.pop();
		for(register int i=head[p];i;i=nxt[i]){
			if(!(~col[rdc[i]]))
				col[rdc[i]]=!type[i];
			else if(col[rdc[i]]==type[i]&&!vis[rdc[i]]){
				dis[rdc[i]]=dis[p]+1;
				vis[rdc[i]]=true;
				q.push(rdc[i]);
			}
		}
	}
}
int main(){
	n=read();m=read();
	for(register int i=1;i<=n;++i)
		col[i]=-1;
	for(register int i=0,u,v,z;i<m;++i){
		u=read();v=read();z=read();
		add(v,u,z);
	}
	spfa();
	if(!vis[1])puts("-1");
	else printf("%d\n",dis[1]);
	for(register int i=1;i<=n;++i)
		printf("%d",~col[i]?col[i]:0);
    return 0;
}