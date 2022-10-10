#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
const int maxn=100010;
struct edge{
	int next,to;
}e[maxn*2];
int head[maxn],len;
void add(int x,int y){
	e[++len]={head[x],y};
	head[x]=len;
}
int i,j,k,n,m,T,is[maxn],w[2],deep[maxn];
void dfs(int now,int fa){
	deep[now]=deep[fa]+1;
	for(int i=head[now];i;i=e[i].next){
		int u=e[i].to;is[now]++;
		if(u==fa)continue;
		dfs(u,now);
	}is[now]=is[now]<=1?1:0;
}
int ans=0,ans2=0;
void dfs2(int now,int fa){
	int b=is[fa];
	if(is[now])w[deep[now]%2]=1;
	for(int i=head[now];i;i=e[i].next){
		int u=e[i].to;
		if(u==fa)continue;
		b|=is[u];
		dfs2(u,now);
		if(is[now] || is[u]);else ans++;
	}ans+=b;
}
int main(){
	cin>>n;
	for(i=1;i<n;i++){
		int x=read(),y=read();
		add(x,y);
		add(y,x);
	}dfs(1,0);
	dfs2(1,0);
	cout<<(w[0]+w[1])*2-1<<' '<<ans<<endl;
	return 0;
}