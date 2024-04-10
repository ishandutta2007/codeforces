#include<bits/stdc++.h>
using namespace std;

#define cout cerr
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)

typedef long long ll;
typedef pair<int,int> pii;
#define FR first
#define SE second

inline void rd(int &x){
	x=0;char ch=getchar();int f=1;
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	x*=f;
} 

const int Mod=1000000007;
namespace modular{
	int add(int a,int b){return a+b>=Mod?a+b-Mod:a+b;}
	int dec(int a,int b){return a-b<0?a-b+Mod:a-b;}
	int mul(int a,int b){return 1ll*a*b%Mod;}
}using namespace modular;

int n;
#define Maxn 205
int head[Maxn],v[Maxn<<1],nxt[Maxn<<1],tot=0;
inline void add_edge(int s,int e){
	tot++;v[tot]=e;nxt[tot]=head[s];head[s]=tot;
	tot++;v[tot]=s;nxt[tot]=head[e];head[e]=tot;
}

int Ans=0; 

int seq[Maxn],in[Maxn],out[Maxn],dfk;
int inv[Maxn],dep[Maxn];

void pre_dfs(int u,int f){
	in[u]=++dfk;seq[dfk]=u;
	for(int i=head[u];i;i=nxt[i])
		if(v[i]!=f){
			dep[v[i]]=dep[u]+1;
		pre_dfs(v[i],u);
	} 
	out[u]=dfk;
}

void dfs(int u,int f,int t){
	if(u<t)Ans=add(Ans,1);
	for(int i=head[u];i;i=nxt[i])
		if(v[i]!=f)dfs(v[i],u,t); 
} 

int F[Maxn][Maxn];

void gao(int u,int f){
	dfs(u,f,u);
	for(int i=head[u];i;i=nxt[i])
		if(v[i]!=f){
			gao(v[i],u);
			int t=v[i];
			rep(j,in[u]+1,in[t]-1)rep(k,in[t],out[t])
				if(seq[j]<seq[k]){
					int All=dep[seq[j]]+dep[seq[k]]-2*dep[u];
					//F[dep[seq[j]]-dep[u]][dep[seq[k]]-dep[u]]
					Ans=add(Ans,F[dep[seq[j]]-dep[u]][dep[seq[k]]-dep[u]]);
				}else{
					int All=dep[seq[j]]+dep[seq[k]]-2*dep[u];
					Ans=add(Ans,F[dep[seq[k]]-dep[u]][dep[seq[j]]-dep[u]]);
				}
		}
}

void calc(int rt){
	dfk=0;
	dep[rt]=0;
	pre_dfs(rt,0);
	gao(rt,0);
}

int main(){
	rd(n);
	inv[0]=inv[1]=1;
	rep(i,2,n)inv[i]=mul(Mod-Mod/i,inv[Mod%i]);
	rep(i,0,n)
		rep(j,0,n)
			if(i==0)F[i][j]=0;
			else if(j==0)F[i][j]=1;
			else F[i][j]=mul(inv[2],add(F[i-1][j],F[i][j-1]));
	int s,e;
	rep(i,1,n-1){
		rd(s);rd(e);
		add_edge(s,e);
	}
	rep(rt,1,n)calc(rt);
	printf("%d\n",mul(Ans,inv[n]));
	return 0;
}