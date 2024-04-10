#include<cstdio>
#include<vector>
using namespace std;
const int Mod=1e9+7;
typedef long long ll;
int n,m,cnt,u[510000],v[510000],deg[510000],inv2[510000];
int top,s[510000],pos[510000],vis[510000],sz[510000];
int sum[510000],sum2[510000],tot[510000];
int edgenum=1,vet[1100000],Next[1100000],Head[510000];
vector<int> c[510000];
inline int add(int x,int y){ return x+y>=Mod?x+y-Mod:x+y;}
inline int dec(int x,int y){ return x-y<0?x-y+Mod:x-y;}
inline ll mul(int x,int y){ return 1ll*x*y%Mod;}
inline ll sqr(int x){ return mul(x,x);}
void addedge(int u,int v){
    vet[++edgenum]=v;
    Next[edgenum]=Head[u];
	Head[u]=edgenum;
}
void dfs(int u,int fa){
	vis[u]=1; s[++top]=u; pos[u]=top;
	int v;
	for (int e=Head[u];e;e=Next[e]){
		v=vet[e];
		if (v==fa||vis[v]==2) continue;
		if (!vis[v]) dfs(v,u);
		else{
			cnt++; sz[cnt]=pos[u]-pos[v]+1;
			for (int i=pos[v];i<=pos[u];i++){
				c[cnt].push_back(s[i]);
				sum[s[i]]=add(sum[s[i]],inv2[sz[cnt]]);
				sum2[s[i]]=add(sum2[s[i]],sqr(inv2[sz[cnt]]));
				tot[cnt]=add(tot[cnt],deg[s[i]]-2);
			}
		}
	}
	vis[u]=2; top--;
}

inline int E_v(){ return mul(n,inv2[1]);}
inline int E_e(){ return mul(m,inv2[2]);}
inline int E_c(){
	int res=0;
	for (int i=1;i<=cnt;i++) res=add(res,inv2[sz[i]]);
	return res;
}

inline int E_vv(){ return mul(mul(n,n+1),inv2[2]);}
inline int E_ee(){
	int res=0;
	for (int i=1;i<=m;i++){
		res=add(res,inv2[2]);								//
		res=add(res,mul(deg[u[i]]+deg[v[i]]-2,inv2[3]));	//
		res=add(res,mul(m-deg[u[i]]-deg[v[i]]+1,inv2[4]));	// 
	}
	return res;
}
inline int E_cc(){
	int s=0,res=0;
	//=ans*1+ans*1/2 +ans*1/(2^size) 
	for (int i=1;i<=cnt;i++) s=add(s,inv2[c[i].size()]);
	res=mul(s,s);
	//
	for (int i=1;i<=cnt;i++) res=dec(res,sqr(inv2[c[i].size()]));
	res=add(res,s);
	//
	for (int i=1;i<=n;i++) res=add(res,dec(sqr(sum[i]),sum2[i]));
	return res;
}
inline int E_ve(){ return mul(m,add(mul(inv2[2],2),mul(inv2[3],n-2)));}// 
inline int E_vc(){
	int res=0;
	for (int i=1;i<=cnt;i++){
		res=add(res,mul(sz[i],inv2[sz[i]]));				//
		res=add(res,mul(n-sz[i],inv2[sz[i]+1]));			// 
	}
	return res;
}
inline int E_ec(){
	int res=0;
	for (int i=1;i<=cnt;i++){
		res=add(res,mul(sz[i],inv2[sz[i]]));				//
		res=add(res,mul(tot[i],inv2[sz[i]+1]));				// 
		res=add(res,mul(m-tot[i]-sz[i],inv2[sz[i]+2]));		// 
	}
	return res; 
}

inline int getans2(){
	int x1=add(E_vv(),add(E_ee(),E_cc()));
	int x2=dec(E_vc(),add(E_ve(),E_ec())); x2=add(x2,x2);
	return add(x1,x2);
}
inline int getans(){ return add(dec(E_v(),E_e()),E_c());}
int main(){
	inv2[0]=1; inv2[1]=5e8+4;
	for (int i=2;i<=500005;i++) inv2[i]=mul(inv2[i-1],inv2[1]);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		scanf("%d%d",&u[i],&v[i]);
		deg[u[i]]++; deg[v[i]]++;
		addedge(u[i],v[i]); addedge(v[i],u[i]);
	}
	dfs(1,0);
	printf("%d\n",dec(getans2(),sqr(getans())));
	return 0;
}