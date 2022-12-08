#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
int n,hed[N],to[N<<1],nxt[N<<1],cnt=1,idv[N<<1],pare[N],d[N];
inline void adde(int u,int v){
	++cnt;to[cnt]=v,nxt[cnt]=hed[u];hed[u]=cnt;
	idv[cnt]=++d[u];
}
int anc[N][20],dep[N];
inline void dfs(int x,int pre){
	dep[x]=dep[pre]+1,anc[x][0] = pre;
	for(int i=1;i<=19;i++)anc[x][i]=anc[anc[x][i-1]][i-1];
	for(int i=hed[x];i;i=nxt[i]){
		int v=to[i];if(v==pre)continue;
		dfs(v,x);
		pare[v] = i;
	}
}
int lca(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	for(int i=19;~i;i--)if(dep[anc[x][i]]>=dep[y])x=anc[x][i];
	if(x==y)return x;
	for(int i=19;~i;i--)if(anc[x][i]!=anc[y][i])x=anc[x][i],y=anc[y][i];
	return anc[x][0];
}
const int mod = 1e9+7;
int fac[N];
struct Linktable{
	int sz,opsz,id;
	vector<int> par, pre, nxt;
	void build(int deg){
		sz=deg;
		pre.resize(deg+1),nxt.resize(deg+1);
		par.resize(deg+1);for(int i=0;i<=deg;i++)par[i]=i,nxt[i]=pre[i]=-1;
	}
	int find(int x){
		return par[x]==x?par[x]:par[x]=find(par[x]);
	}
	bool connect(int a,int b){
		// cout << id << " " << a << "->" << b << endl;
		if(~nxt[a]&&nxt[a]!=b)return false;
		if(~pre[b]&&pre[b]!=a)return false;
		int u=find(a), v=find(b);
		if(u==v){if(opsz!=sz)return false;}
		else {
			opsz++;
			nxt[a]=b,pre[b]=a;
			par[u]=v;
		}
		return true;
	}
}tbl[N];

void calc(){
	fac[0]=1;for(int i=1;i<=n;i++)fac[i]=1ll*i*fac[i-1]%mod;
	int ans = 1;
	for(int i=1;i<=n;i++){
		ans = 1ll*ans*fac[tbl[i].sz-tbl[i].opsz]%mod;
	}
	printf("%d\n",ans);
}
void EXIT(){
	puts("0");
	exit(0);
}
void Do(int a,int b){
	if(a==b){
		if(n!=1)EXIT();
		return ;
	}
	int A = a, B = b;
	int up = lca(a,b);
	vector<int> edge,dec;
	while(a!=up){
		edge.push_back(1^pare[a]);
		a=anc[a][0];
	}
	while(b!=up){
		dec.push_back(pare[b]);
		b=anc[b][0];
	}
	while(dec.size()){
		edge.push_back(dec.back());
		dec.pop_back();
	}
	if(!tbl[A].connect(0,idv[edge[0]])) EXIT();
	if(!tbl[B].connect(idv[edge.back()^1],0)) EXIT();
	for(size_t i=0;i+1<edge.size();i++){
		int e1 = edge[i]^1, e2 = edge[i+1];
		int v = to[e1^1];
		if(!tbl[v].connect(idv[e1],idv[e2]))
			EXIT();
	}
}
int main()
{
	cin >> n;
	// for(int i=1;i<=n;i++)scanf("%d",&q[i]);
	for(int i=1;i<n;i++){
		int u,v;scanf("%d%d",&u,&v);
		adde(u,v),adde(v,u);
	}
	dfs(1,0);
	for(int i=1;i<=n;i++)tbl[i].build(d[i]),tbl[i].id=i;
	for(int i=1;i<=n;i++){
		int p;scanf("%d",&p);
		if(p)Do(p,i);
	}
	calc();
}
/* 
5
1 2 5 3 4
1 2
1 3
1 4
1 5
2 3 1 4 5
 */