/*********************************************************************
 * Source - lyp
 * ProblemCF1260F
 * Authorhydd
 * Date2020/9/8
 * EncodingSimplified Chinese (GB2312)
*********************************************************************/
#include<cstdio>
#include<vector>
//#define File(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout)
using namespace std;
const int Mod=1e9+7;
typedef long long ll;
int n,l[110000],r[110000],len[110000],inv[110000],dep[110000];
int tree1[110000],tree2[110000];
int edgenum,vet[210000],Next[210000],Head[110000];
int cnt,top[110000],son[110000],dfn[110000],sz[110000],fa[210000];
vector<int> L[110000],R[110000];
char Getchar(){
	static char now[1<<20],*S,*T;
	if (T==S){
		T=(S=now)+fread(now,1,1<<20,stdin);
		if (T==S) return EOF;
	}
	return *S++;
}
int read(){
	int x=0,f=1;
	char ch=Getchar();
	while (ch<'0'||ch>'9'){
		if (ch=='-') f=-1;
		ch=Getchar();
	}
	while (ch<='9'&&ch>='0') x=x*10+ch-'0',ch=Getchar();
	return x*f;
}
ll qpow(ll x,ll a){
    ll res=1;
    while (a){
        if (a&1) res=res*x%Mod;
        x=x*x%Mod; a>>=1;
    }
    return res;
}
void addedge(int u,int v){
	vet[++edgenum]=v;
	Next[edgenum]=Head[u];
	Head[u]=edgenum;
}
void dfs(int u){
	sz[u]=1; dep[u]=dep[fa[u]]+1;
	int mx=-1;
	for (int e=Head[u];e;e=Next[e]){
		if (vet[e]==fa[u]) continue;
		fa[vet[e]]=u; dfs(vet[e]);
		sz[u]+=sz[vet[e]];
		if (sz[vet[e]]>mx){
			mx=sz[vet[e]];
			son[u]=vet[e];
		}
	}
}
void dfs2(int u,int tp){
	dfn[u]=++cnt; top[u]=tp;
	if (son[u]) dfs2(son[u],tp);
	for (int e=Head[u];e;e=Next[e])
		if (!dfn[vet[e]]) dfs2(vet[e],vet[e]);
}
void add(int x,int y){
	for (int i=x;i<=n;i+=i&-i){
		tree1[i]=(tree1[i]+y)%Mod;
		tree2[i]=(tree2[i]+1ll*y*x)%Mod;
	}
}
int getsum(int x){
	int res=0;
	for (int i=x;i;i-=i&-i){
		res=(res+1ll*(x+1)*tree1[i])%Mod;
		res=(res-tree2[i]+Mod)%Mod;
	}
	return res;
}
void change(int l,int r,int x){ add(l,x); add(r+1,Mod-x);}
int query(int l,int r){ return (getsum(r)-getsum(l-1)+Mod)%Mod;}
int Query(int u){
	int x=u;
	int sum=0;
	while (x){
		sum=(sum+query(dfn[top[x]],dfn[x]))%Mod;
		x=fa[top[x]];
	}
	return 1ll*sum*inv[u]%Mod;
}
void ADD(int u){
	int x=u;
	while (x){
		change(dfn[top[x]],dfn[x],inv[u]);
		x=fa[top[x]];
	}
}
void DEL(int u){
	int x=u;
	while (x){
		change(dfn[top[x]],dfn[x],Mod-inv[u]);
		x=fa[top[x]];
	}
}
int main(){
	n=read(); int s=1;
	for (int i=1;i<=n;i++){
		l[i]=read(); r[i]=read();
		L[l[i]].push_back(i); R[r[i]+1].push_back(i);
		len[i]=r[i]-l[i]+1; inv[i]=qpow(len[i],Mod-2);
		s=1ll*s*len[i]%Mod;
	}
	int u,v;
	for (int i=1;i<n;i++){
		u=read(); v=read();
		addedge(u,v); addedge(v,u);
	}
	dfs(1); dfs2(1,1);
	int sum1=0,sum2=0,sum3=0,sum=0,ans=0;
	for (int i=1;i<=100000;i++){
		for (int x:R[i]){
			sum1=(sum1-1ll*dep[x]*inv[x]%Mod+Mod)%Mod;
			sum2=(sum2-1ll*dep[x]*inv[x]%Mod*inv[x]%Mod+Mod)%Mod;
			sum3=(sum3-inv[x]+Mod)%Mod;
			DEL(x); sum=(sum-Query(x)+Mod)%Mod;
		}
		for (int x:L[i]){
			sum1=(sum1+1ll*dep[x]*inv[x])%Mod;
			sum2=(sum2+1ll*dep[x]*inv[x]%Mod*inv[x])%Mod;
			sum3=(sum3+inv[x])%Mod;
			sum=(sum+Query(x))%Mod; ADD(x);
		}
		ans=(ans+1ll*sum1*sum3%Mod+(Mod-sum2)+(Mod-sum)+(Mod-sum))%Mod;
		//printf("%lld\n",(1ll*sum1*sum3+Mod+(Mod-sum2)+(Mod-sum)*2)%Mod*s%Mod);
	}
	printf("%lld\n",1ll*s*ans%Mod);
	return 0;
}
/*
2
1 1
1 1
1 2
*/