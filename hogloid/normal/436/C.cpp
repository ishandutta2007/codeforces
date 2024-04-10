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
struct uf{

	static const int MSIZE=1005;
	int par[MSIZE];
	int size[MSIZE];
	void init(){
		memset(par,-1,sizeof(par));
		REP(i,MSIZE) size[i]=1;
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
int n,m,k,w;
char buf[1005][11][11];
pair<int,pi> es[1000005];

vector<int> g[1005];

int fix(int a){
	if(a==k) return 0;
	return a+1;
}
void dfs(int v,int p=-1){
	REP(i,g[v].size()){
		int to=g[v][i];
		if(to==p) continue;
		printf("%d %d\n",fix(to),fix(v));
		dfs(to,v);
	}
}


int main(){
	cin>>n>>m>>k>>w;
	REP(i,k){
		REP(j,n) scanf("%s",buf[i][j]);
	}
	
	int cnt=0;
	REP(i,k) REP(j,i){
		int dif=0;
		REP(y,n) REP(x,m) if(buf[i][y][x]!=buf[j][y][x]) ++dif;
		es[cnt++]=mp(dif*w,mp(i,j));
	}
	REP(i,k) es[cnt++]=mp(n*m,mp(i,k));

	
	u.init();
	sort(es,es+cnt);
		
	int res=0;
	REP(i,cnt){
		pi& p=es[i].sc;
		if(!u.same(p.fr,p.sc)){
			u.unite(p.fr,p.sc);
			res+=es[i].fr;
			g[p.fr].pb(p.sc);
			g[p.sc].pb(p.fr);
		}
	}
	cout<<res<<endl;

	dfs(k);



	return 0;
}