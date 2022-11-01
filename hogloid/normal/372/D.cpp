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

const int INF=5e8;

int n,k;
vector<int> g[100005];

static const int MAXN=100005,LOG_MAX=19;


int dep[MAXN];
int par[LOG_MAX][MAXN];
int visit[100005],fin[100005],cnt;
int rev[100005];//vis->id
void prep(int v,int p,int d=0){
	par[0][v]=p;
	dep[v]=d;
	rev[cnt]=v;
	visit[v]=cnt++;
	for(auto to:g[v]){
		if(to==p) continue;
		prep(to,v,d+1);
	}
	fin[v]=cnt;
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


int getcon(int i,const set<int>& vs){
	auto it=vs.lower_bound(visit[i]);
	int l1=0,l2=0;
	if(it!=vs.end()){
		l1=lca(i,rev[*it]);
	}
	if(it!=vs.begin()){
		--it;
		l2=lca(i,rev[*it]);
	}
	if(dep[l1]<dep[l2]) swap(l1,l2);
	return l1;
}

set<int> vs;
int root;
void ins(int i){
	if(vs.empty()){
		cnt=1;
		root=i;
	}else{
		int l1=getcon(i,vs);

		if(dep[l1]<dep[root]){
			cnt+=dep[root]-dep[l1];
			root=l1;
		}
		cnt+=dep[i]-dep[l1];
	}
	vs.insert(visit[i]);
}

void del(int v){
	int del=v;
	vs.erase(visit[del]);

	if(vs.empty()){
		cnt=0;
		root=0;
		return;
	}

	int l1=getcon(del,vs);
	cnt-=dep[del]-dep[l1];

	int st=rev[*vs.begin()],en=rev[*(--vs.end())];
	int nroot=lca(st,en);
	cnt-=dep[nroot]-dep[root];

	root=nroot;
}


int check(){
	cnt=0;
	
	int res=0;
	int j=0;
	ins(0);
	REP(i,n){
		while(j+1<n){
			ins(j+1);
			if(cnt<=k){
				++j;
			}else{
				del(j+1);
				break;
			}
		}
		chmax(res,j+1-i);
		del(i);
	}
	return res;
}



int main(){
	cin>>n>>k;
	REP(i,n-1){
		int a,b;scanf("%d%d",&a,&b);--a;--b;
		g[a].pb(b);
		g[b].pb(a);
	}
	build();
	int lb=check();
	cout<<lb<<endl;

	return 0;
}