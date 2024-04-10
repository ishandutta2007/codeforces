#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
const int maxn=400010;
struct edge{
	int next,to;
}a[maxn*2];
int head[maxn],len;
void add(int x,int y){
	a[++len]={head[x],y};
	head[x]=len;
}
int i,j,k,n,m,num[maxn],happy[maxn];
bool B;
void dfs(int now,int fa){
	for(int i=head[now];i;i=a[i].next){
		int u=a[i].to;
		if(u==fa)continue;
		dfs(u,now);
		num[now]+=num[u];
	}
	if((num[now]&1) != (happy[now]&1))B=true;
	happy[now]=(num[now]+happy[now])/2;
	if(happy[now]>num[now] || happy[now]<0)B=true;
}
void dfs2(int now,int fa){
	int all=0;
	for(int i=head[now];i;i=a[i].next){
		int u=a[i].to;
		if(u==fa)continue;
		dfs2(u,now);
		all+=happy[u];
	}if(all>happy[now])B=true;
}
int main(){
	int T;
	T=read();
	while(T--){
		B=false;
		n=read();m=read();
		for(i=1;i<=n;i++)num[i]=read();
		for(i=1;i<=n;i++)happy[i]=read();
		for(i=1;i<n;i++){
			int x=read(),y=read();
			add(x,y);add(y,x);
		}
		dfs(1,0);
		if(!B)dfs2(1,0);
		if(B)puts("NO");
		else puts("YES");
		for(i=1;i<=n;i++)head[i]=0;
		len=0;
	}
	return 0;
}