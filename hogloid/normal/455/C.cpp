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
struct uf{
	static const int MAXN=300005;
	int par[MAXN];
	int size[MAXN];
	int len[MAXN];
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
	void merge(int x,int y){
		x=root(x);y=root(y);
		if(x==y) return;
		if(size[x]<size[y]) swap(x,y);
		int l1=len[x],l2=len[y];

		par[y]=x;
		size[x]+=size[y];
		len[x]=max({(l1+1)/2+(l2+1)/2+1,l1,l2});
	}
};
uf u;

int n,m,q;

vector<int> g[300005];

pi rec(int v,int p){
	pi res=mp(0,v);
	for(auto to:g[v]){
		if(to==p) continue;
		pi nxt=rec(to,v);
		++nxt.fr;
		chmax(res,nxt);
	}
	return res;
}

int main(){
	u.init();
	cin>>n>>m>>q;
	REP(i,m){
		int a,b;scanf("%d%d",&a,&b);--a;--b;
		u.unite(a,b);
		g[a].pb(b);
		g[b].pb(a);
	}

	REP(i,n) if(u.root(i)==i){
		pi v1=rec(i,-1);
		pi v2=rec(v1.sc,-1);
		u.len[i]=v2.fr;
	}

	REP(hoge,q){
		int t,x;scanf("%d%d",&t,&x);--x;
		if(t==1){
			x=u.root(x);
			printf("%d\n",u.len[x]);
		}else{
			int y;scanf("%d",&y);--y;
			u.merge(x,y);
		}
	}





	return 0;
}