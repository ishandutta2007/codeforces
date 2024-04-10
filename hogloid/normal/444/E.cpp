#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
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

int n;
pair<int,pi> es[3005];
vector<pi> g[3005];
int x[3005];


struct uf{

	static const int MSIZE=3005;
	int par[MSIZE];
	int size[MSIZE];

	int cap[MSIZE];
	void init(){
		memset(par,-1,sizeof(par));
		REP(i,MSIZE){
			size[i]=1;
			cap[i]=x[i];
		}
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
		cap[a]+=cap[b];
	}
	bool same(int a,int b){
		return root(a)==root(b);
	}
};

uf u;
bool check(int w){
	u.init();
	REP(i,n) if(es[i].fr<w){
		u.unite(es[i].sc.fr,es[i].sc.sc);
	}
	vector<pi> trees;
	REP(i,n) if(u.root(i)==i){
		trees.pb(mp(u.size[i],u.cap[i]));
	}
	sort(ALL(trees));
	reverse(ALL(trees));
	dump(w);dump(trees.size());
	dump(trees[0].fr);
	if(trees[0].fr*2>n){
		int othersum=0;
		REPN(i,trees.size(),1) othersum+=trees[i].sc;
		if(othersum>=trees[0].fr) return true;
		return false;
	}else return true;
}

int main(){
	cin>>n;
	REP(i,n-1){
		int a,b,c;cin>>a>>b>>c;--a;--b;
		g[a].pb(mp(b,c));
		g[b].pb(mp(a,c));
		es[i]=mp(c,mp(a,b));
	}
	REP(i,n) cin>>x[i];

	
	int lb=0,ub=10005;
	while(ub-lb>1){
		int md=(lb+ub)>>1;
		if(check(md)) lb=md;
		else ub=md;
	}
	cout<<lb<<endl;

	return 0;
}