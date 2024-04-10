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

//const int INF=5e8;

int q;
int n=4;
static const int MAXN=1000015,LOG_MAX=20;

vector<int> g[MAXN];

int dep[MAXN];
int par[LOG_MAX][MAXN];

void prep(int v,int p,int d=0){
	par[0][v]=p;
	dep[v]=d;

	for(auto to:g[v]){
		if(to==p) continue;
		prep(to,v,d+1);
	}
}


int lca(int a,int b){
	if(dep[a]>dep[b]) swap(a,b);
	int dif=dep[b]-dep[a];
	REP(i,LOG_MAX) if(dif>>i&1) b=par[i][b];
	if(a==b) return a;
	for(int i=LOG_MAX-1;i>=0;--i) if(par[i][a]!=par[i][b]){
		a=par[i][a];
		b=par[i][b];
	}
	return par[0][a];
}

int getpar(int a,int k){
	REP(i,LOG_MAX) if(k>>i&1) a=par[i][a];
	return a;
}	
void build(){
	prep(0,-1);
	REP(i,LOG_MAX-1){
		REP(j,n){
			if(par[i][j]==-1){
				par[i+1][j]=-1;
			}else{
				par[i+1][j]=par[i][par[i][j]];
			}
		}
	}
}
int main(){
	g[0].pb(1);
	g[0].pb(2);
	g[0].pb(3);
	cin>>q;

	REP(hoge,q){
		int v;scanf("%d",&v);--v;
		g[v].pb(n++);
		g[v].pb(n++);
	}
	build();
	
	int res=2;
	int mostd=1,who=1;
	REP(i,q){
		int a=4+i*2,b=5+i*2;

		if(dep[a]>mostd){
			++res;
			mostd=dep[a];
			who=a;
		}else{
			int l=lca(a,who);
			if(res<dep[a]+dep[who]-dep[l]*2){
				res=dep[a]+dep[who]-dep[l]*2;
			}
		}
		printf("%d\n",res);
	}






	return 0;
}