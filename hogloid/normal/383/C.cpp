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

static const int MAXN=200005;
struct BIT{
	int val[MAXN*2+2];
	int n;
	void init(int n_){
		n=1;
		while(n<n_) n<<=1;
		REP(i,n+1) val[i]=0;
	}
	void add(int k,int a){
		++k;
		while(k<=n){
			val[k]+=a;
			k+=k&-k;
		}
	}
	int query(int k){	//[0,k)
		int res=0;
		while(k>0){
			res+=val[k];
			k-=k&-k;
		}
		return res;
	}
};


int n,m;
vector<int> g[200005];
int dep[200005];
int start[200005],fin[200005],cnt;
void dfs(int v,int p,int depth=0){
	start[v]=cnt;++cnt;
	dep[v]=depth+1;
	for(auto to:g[v]){
		if(to==p) continue;
		dfs(to,v,depth+1);
	}
	fin[v]=cnt;
}

int init[200005];

BIT bit[2];
int main(){
	cin>>n>>m;
	REP(i,n) scanf("%d",&init[i]);
	REP(i,n-1){
		int a,b;scanf("%d%d",&a,&b);--a;--b;
		g[a].pb(b);
		g[b].pb(a);
	}

	dfs(0,-1);

	bit[0].init(n);
	bit[1].init(n);

	REP(hoge,m){
		int t,x;scanf("%d%d",&t,&x);
		--x;
		if(t==1){
			int val;scanf("%d",&val);
			bit[dep[x]&1].add(start[x],val);
			bit[dep[x]&1].add(fin[x],-val);
		}else{
			int flag=(dep[x]&1);
			int res=bit[flag].query(start[x]+1)-bit[flag^1].query(start[x]+1)+init[x];

			printf("%d\n",res);
		}
	}


	return 0;
}