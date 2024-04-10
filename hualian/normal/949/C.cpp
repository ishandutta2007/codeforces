#include<bits/stdc++.h>
using namespace std;
const int N=1e5+9;
int n,m,p,idx,top,color,cnt;
int a[N];
int last[N];
struct edge{
	int pre,to;
}e[N*4];
int dfn[N],low[N];
int sta[N],insta[N];
int id[N];
int sum[N];
void tarjan(int u)
{
	low[u]=dfn[u]=++idx;
	sta[++top]=u;
	insta[u]=1;
	for(int i=last[u];i;i=e[i].pre){
		int to=e[i].to;
		if(!dfn[to]){
			tarjan(to);
			low[u]=min(low[u],low[to]);
		}
		else if(insta[to])low[u]=min(low[u],dfn[to]);
	}
	if(dfn[u]==low[u]){
		int v;
		color++;
		do{
			v=sta[top--];
			sum[color]++;
			id[v]=color;
			insta[v]=false;
		}while(v!=u);
	}
}
void add(int x,int y){
	cnt++;
	e[cnt].pre=last[x];
	e[cnt].to=y;
	last[x]=cnt;
}
inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int flag[N];
void dfs(){
	for(int i=1;i<=n;i++){
		for(int j=last[i];j;j=e[j].pre){
			int to=e[j].to;
			if(id[i]!=id[to])flag[id[i]]=true;
		}
	}
}
int main(){
	n=read(),m=read(),p=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	for(int i=1;i<=m;i++){
		int x=read(),y=read();
		if((a[x]+1)%p==a[y])add(x,y);
		if((a[y]+1)%p==a[x])add(y,x);
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i])tarjan(i);
	dfs();
	int mn=1e9,c=0;
	for(int i=1;i<=color;i++){
		if(sum[i]<mn&&!flag[i]){
			mn=sum[i];
			c=i;
		}
	}
	printf("%d\n",mn);
	for(int i=1;i<=n;i++){
		if(id[i]==c)printf("%d ",i);
	}
	return 0;
}