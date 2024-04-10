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
//const int INF=5e8;

vector<int> g[100005];
int n,k,p;
int cnt[100005];
void dfs(int v,int p,int d=0){
	++cnt[d];
	for(auto to:g[v]){
		if(to==p) continue;
		dfs(to,v,d+1);
	}
}

int cntS[100005];

int main(){
	cin>>n>>k>>p;
	REP(i,n-1){
		int a,b;scanf("%d%d",&a,&b);--a;--b;
		g[a].pb(b);
		g[b].pb(a);
	}
	dfs(0,-1);

	REP(i,n) cntS[i+1]=cntS[i]+cnt[i];
	
	lint cost=0;
	int have=0;
	int st=1;

	int res=0;
	debug(cnt,cnt+n);
	for(int i=1;i<=n;++i){
		cost+=have;
		while(cost>p){
			cost-=cnt[st]*(i-st);
			have-=cnt[st];
			++st;
		}
		dump(st);dump(i);

		have+=cnt[i];
		dump(have);
		if(st>1) chmax(res,(int)(have+(p-cost)/(i-st+1)));
		else chmax(res,have);
	}
	chmin(res,k);
	cout<<res<<endl;

	return 0;
}