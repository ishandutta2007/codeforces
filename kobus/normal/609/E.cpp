#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define int long long
typedef long long ll;
typedef pair<int,int>pii;
#define MAXN 212345
#define INF INT_MAX/2
#define MOD 1000000


//peso,cara
vector<pii> are[MAXN];
vector<pii> arm[MAXN];

set<pii> mst;

//peso,indice,menor mano, maior mano
pair<pii,pii> edg[212345];
int h[MAXN];
int me[MAXN][21];
int lc[MAXN][21];

int pai[MAXN];
int peso[MAXN];

int find(int x){
	if(pai[x]==x)return x;
	return pai[x]=find(pai[x]);
}

void join(int a,int b){
	a=find(a);
	b=find(b);
	if(peso[a]<peso[b])pai[a]=b;
	else if(peso[b]<peso[a])pai[b]=a;
	else{
		pai[a]=b;
		peso[b]++;
	}
}

void dfs(int u, int p, int ha, int pe){\
	h[u]=ha;
	lc[u][0]=p;
	me[u][0]=pe;
	for(int i=1;i<20;i++){
		lc[u][i]=lc[lc[u][i-1]][i-1];
		me[u][i]=max(me[lc[u][i-1]][i-1],me[u][i-1]);

	}
	for(pii v:arm[u]){
		if(v.s!=p)
			dfs(v.s,u,ha+1,v.f);
	}
}

int lca(int u, int v){
	if(h[u]>h[v])swap(u,v);
	for(int i=19;i>=0;i--){
		if(h[lc[v][i]]>=h[u])v=lc[v][i];
	}
	if(u==v)return u;
	for(int i=19;i>=0;i--){
		if(lc[u][i]!=lc[v][i]){
			u=lc[u][i];
			v=lc[v][i];
		}
	}
	return lc[u][0];
}

int mxe(int u, int v){
	int resp=0;
	int dis=h[u]-h[v];
	//cout<<"dis "<<dis<<endl;
	for(int i=19;i>=0;i--){
		if((dis>>i)%2==1){
			resp=max(resp,me[u][i]);
			u=lc[u][i];
		}
	}
	return resp;
}


int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	//com lca manter a aresta de peso maximo entre o cara e certo pai
	//isso na mst
	//pra cada aresta nao na mst pegar o a aresta de peso maximo entre ela e o lca

	int n,m;
	cin>>n>>m;
	int pesomst=0;

	for(int i=0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		are[a].pb(mp(c,b));
		are[b].pb(mp(c,a));
		edg[i].f.f=c;
		edg[i].f.s=i;
		edg[i].s.f=min(a,b);
		edg[i].s.s=max(a,b);
	}

	for(int i=1;i<=n;i++){
		pai[i]=i;
	}

	sort(edg,edg+m);

	for(int i=0;i<m;i++){
		int a=edg[i].s.f;
		int b=edg[i].s.s;
		if(find(a)!=find(b)){
			join(a,b);
			pii cara=edg[i].s;
			mst.insert(cara);
			arm[a].pb(mp(edg[i].f.f,b));
			arm[b].pb(mp(edg[i].f.f,a));
			pesomst+=edg[i].f.f;
			//cout<<"na mst "<<cara.f<<" "<<cara.s<<endl;

		}
		swap(edg[i].f.f,edg[i].f.s);
	}

	sort(edg,edg+m);

	dfs(1,1,0,0);

	for(int i=0;i<m;i++){
		int a=edg[i].s.f;
		int b=edg[i].s.s;
		if(mst.find(edg[i].s)!=mst.end()){
			cout<<pesomst<<endl;
		}
		else{
			//cout<<"has "<<h[a]<<" "<<h[b]<<" "<<h[lca(a,b)]<<endl;
			//cout<<mxe(a,lca(a,b))<<" "<<mxe(b,lca(a,b))<<endl;
			cout<<pesomst+edg[i].f.s-max(mxe(a,lca(a,b)),mxe(b,lca(a,b)))<<endl;
		}
	}


	return 0;
}