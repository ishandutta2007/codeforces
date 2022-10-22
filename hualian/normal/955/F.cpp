#include<bits/stdc++.h>
#define rep(i,  a) for(register int i=1,i##end=a;i<=i##end;i++)
#define For(i,a,b) for(register int i=(a),i##END=(b);i<=i##END;i++)
#define Rof(i,b,a) for(register int i=(b),i##END=(a);i>=i##END;i--)
#define go(u) for(int i=head[u];i;i=nxt[i])
using namespace std;
//char buf[(1<<21)+5],*p1,*p2;
//#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
void chmx(int &x,int y){(x<y)?(x=y):(0);}
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
const int N=3e5+10;
int n;
int max(int x,int y){return x>y?x:y;}
int head[N],to[N<<1],nxt[N<<1],cnt;
void add(int u,int v){
	to[++cnt]=v,nxt[cnt]=head[u],head[u]=cnt;
}int deg[N];vector<int> g[N];
void pre(int u,int f){go(u)if(to[i]!=f)g[u].push_back(to[i]),deg[u]++,pre(to[i],u);}
int k,S;
int F[N];long long ans;
bool cmp1(int x,int y){return F[x]>F[y];}
int sta[N],top,G[N];
int fa[N];
void dfs1(int u){
//	F[u]=1;
	for(int v:g[u])fa[v]=u,dfs1(v);
	sta[++top]=u;
//	if(deg[u]<k)return;
//	assert(g[u].size()>=k);
//	nth_element(g[u].begin(),g[u].begin()+k-1,g[u].end(),cmp1);
//	F[u]=F[g[u][k-1]]+1;
}
void calc(int u){
	for(int v:g[u])calc(v),F[u]=max(F[u],F[v]);
	ans+=F[u]; 
}
bool cmp2(int x,int y){return deg[x]>deg[y];}
void dfs2(int u){
	for(int v:g[u])dfs2(v),deg[u]=max(deg[u],deg[v]);
	if(deg[u]>S)ans+=deg[u]-S;
}
signed main(){
	For(i,2,n=read()){
		int u=read(),v=read();
		add(u,v),add(v,u);
	}pre(1,0),S=min(n,(int)sqrt(n)+2);
	dfs1(1);
	int u;
	rep(i,n)G[i]=1;
	for(k=1;k<=S;k++){
		rep(j,top){
			u=sta[j];F[u]=1;
			if(deg[u]<k){chmx(G[fa[u]],G[u]);ans+=G[u];G[u]=1;continue;}
			nth_element(g[u].begin(),g[u].begin()+k-1,g[u].end(),cmp1);
			F[u]=F[g[u][k-1]]+1;
			chmx(G[u],F[u]);chmx(G[fa[u]],G[u]);
			ans+=G[u];G[u]=1;
		}
//		For(i,1,n)printf("f(%d,%d) = %d\n",k,i,F[i]);
	}
	dfs2(1),ans+=1ll*(n-S)*n;
	cout<<ans<<endl;
	return 0;
}