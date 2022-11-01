#include<bits/stdc++.h>
#define REP(i,m) for(int i=0;i<(m);++i)
#define REPN(i,m,in) for(int i=(in);i<(m);++i)
#define ALL(t) (t).begin(),(t).end()
#define CLR(a) memset((a),0,sizeof(a))
#define pb push_back
#define mp make_pair
#define fr first
#define sc second

using namespace std;


#ifndef ONLINE_JUDGE
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
#else
#define dump(x) ;
#define prl ;
template<class T> void debug(T a,T b){ ;}
#endif

template<class T> void chmin(T& a,const T& b) { if(a>b) a=b; }
template<class T> void chmax(T& a,const T& b) { if(a<b) a=b; }
typedef long long int lint;
typedef pair<int,int> pi;

namespace std{
  template<class S,class T>
  ostream &operator <<(ostream& out,const pair<S,T>& a){
    out<<'('<<a.fr<<','<<a.sc<<')';
    return out;
  }
}

lint readL(){
  lint res;
#ifdef ONLINE_JUDGE
  scanf("%I64d",&res);
#else
  scanf("%lld",&res);
#endif
  return res;
}
void printL(lint res){
#ifdef ONLINE_JUDGE
  printf("%I64d",res);
#else
  printf("%lld",res);
#endif
}

vector<pi> g[200005];
//const int INF=5e8;
stack<int> cur;
int low[200005],order[200005],cnt,group[200005],gcnt;

int dfs(int v,int p){
	order[v]=cnt++;
	low[v]=order[v];
	cur.push(v);
  for(auto e:g[v]){
    int to=e.fr,id=e.sc;
		if(id==p) continue;
		if(order[to]!=-1){
			low[v]=min(low[v],order[to]);
		}else{
			low[v]=min(low[v],dfs(to,id));
		}
	}
	if(low[v]<order[v]) return low[v];
	while(!cur.empty() && cur.top()!=v){
		group[cur.top()]=gcnt;
		cur.pop();
	}
	group[cur.top()]=gcnt;
	cur.pop();
	++gcnt;
	return low[v];
}
struct uf{

	static const int MAXN=200005;
	int par[MAXN];
	int size[MAXN];
	void init(){
		memset(par,-1,sizeof(par));
		REP(i,MAXN) size[i]=1;
	}
	int root(int a){
		if(par[a]==-1) return a;
		return par[a]=root(par[a]);
	}
	void unite(int a,int b){
		a=root(a);b=root(b);
		if(a==b) return;
		if(size[a]<size[b]) swap(a,b);

		par[b]=a;
		size[a]+=size[b];
	}
	bool same(int a,int b){
		return root(a)==root(b);
	}
};

uf u;


vector<int> g2[200005];
int n2;
int n,m,q;

int dep[200005];

int par[20][200005];

void prep(int v,int p,int d=0){
  dep[v]=d;
  par[0][v]=p;
  for(auto to:g2[v]){
    if(to==p) continue;
    prep(to,v,d+1);
  }
}

int lca(int a,int b){//assume a and b is connected
	if(dep[a]>dep[b]) swap(a,b);
	int dif=dep[b]-dep[a];
	REP(i,20) if(dif>>i&1) b=par[i][b];
	if(a==b) return a;
	for(int i=19;i>=0;--i) if(par[i][a]!=par[i][b]){
		a=par[i][a];
		b=par[i][b];
	}
	return par[0][a];
}

void build(){
	REP(i,19){
		REP(j,n2){
			if(par[i][j]==-1){
				par[i+1][j]=-1;
			}else{
				par[i+1][j]=par[i][par[i][j]];
			}
		}
	}
}

void exi(){
  puts("No");
  exit(0);
}

int dir[200005][2],mark[200005];

void dfs2(int v,int p){
  for(auto to:g2[v]){
    if(to==p) continue;
    dfs2(to,v);
    REP(t,2) dir[v][t]+=dir[to][t];
  }

  assert(dir[v][0]>=0 && dir[v][1]>=0);
  if(dir[v][0]>0 && dir[v][1]>0) exi();
}


int main(){
  cin>>n>>m>>q;

  REP(i,m){
    int a,b;scanf("%d%d",&a,&b);--a;--b;
    g[a].pb(mp(b,i));
    g[b].pb(mp(a,i));
  }

  memset(order,-1,sizeof(order));
  REP(i,n) if(order[i]==-1) dfs(i,-1);

  u.init();
  n2=gcnt;
  REP(i,n) for(auto e:g[i]){
    int to=e.fr;
    if(i<to && group[i]!=group[to]){
      g2[group[i]].pb(group[to]);
      g2[group[to]].pb(group[i]);
      u.unite(group[i],group[to]);
    }
  }




  memset(dep,-1,sizeof(dep));
  REP(i,n2) if(dep[i]==-1) prep(i,-1),mark[i]=1;

  build();

  
  memset(dir,0,sizeof(dir));//1:in from root 0:go to root
  REP(hoge,q){
    int s,d;scanf("%d%d",&s,&d);--s;--d;
    s=group[s];d=group[d];
    if(s==d) continue;

    if(!u.same(s,d)) exi();

    int L=lca(s,d);
    ++dir[s][0];
    --dir[L][0];

    ++dir[d][1];
    --dir[L][1];
  }

  REP(i,n2) if(mark[i]) dfs2(i,-1);

  puts("Yes");
  

  return 0;
}