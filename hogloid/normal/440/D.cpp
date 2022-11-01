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

int n,k;
vector<pi> g[405];

int dp[405][405];
vector<int> dp2[405][405];
const int INF=5e8;
int tmp[405];
void merge(int* a,int* b,int as,int bs){
	REP(i,n+1) tmp[i]=INF;
	REP(i,as+1) REP(j,bs+1) chmin(tmp[i+j],a[i]+b[j]);
	REP(i,n+1) a[i]=tmp[i];
}

vector<int> tmp2[405];
void merge2(int* a,int* b,vector<int>* a2,vector<int>* b2,int as,int bs){
	REP(i,n+1) tmp[i]=INF;
	REP(i,as+1) REP(j,bs+1) if(tmp[i+j]>a[i]+b[j]){
		tmp[i+j]=a[i]+b[j];
		tmp2[i+j]=a2[i];
		REP(k,b2[j].size()) tmp2[i+j].pb(b2[j][k]);
	}
	REP(i,n+1) a[i]=tmp[i],a2[i]=tmp2[i];
}
int size[405];

void rec(int v,int p){
	REP(j,405) dp[v][j]=INF;
	dp[v][1]=0;
	size[v]=1;
	int chil=0;
	for(pi e:g[v]){
		int to=e.fr;
		if(to==p) continue;
		rec(to,v);
		++chil;

		merge(dp[v],dp[to],size[v],size[to]);
		size[v]+=size[to];
	}
	if(p!=-1){
		dp[v][0]=1;
	}
}

void rec2(int v,int p,int id){
	REP(j,405) dp[v][j]=INF;
	dp[v][1]=0;

	size[v]=1;
	int chil=0;
	for(pi e:g[v]){
		int to=e.fr;
		if(to==p) continue;
		rec2(to,v,e.sc);
		++chil;

		merge2(dp[v],dp[to],dp2[v],dp2[to],size[v],size[to]);
		size[v]+=size[to];
	}
	if(p!=-1){
		dp[v][0]=1;
		dp2[v][0].pb(id);
	}
}

int main(){
	cin>>n>>k;
	REP(i,n-1){
		int a,b;scanf("%d%d",&a,&b);--a;--b;
		g[a].pb(mp(b,i+1));
		g[b].pb(mp(a,i+1));
	}
	
	int cost=INF;
	int root;
	REP(i,n){
		
		rec(i,-1);
		if(dp[i][k]<cost){
			cost=dp[i][k];
			root=i;
		}
	}

	printf("%d\n",cost);
	{
		rec2(root,-1,-1);
		vector<int> res=dp2[root][k];

		REP(i,res.size()) printf("%d%c",res[i],i==res.size()-1?'\n':' ');
	}


	


	return 0;
}