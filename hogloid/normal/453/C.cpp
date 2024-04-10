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

int n,m;
int x[100005];
vector<int> g[100005];

int done[100005];
vector<int> res;

int flag;
void dfs(int v,int p){
	res.pb(v);
	done[v]=1;
	int vis=1;
	for(auto to:g[v]){
		if(to==p || done[to]) continue;
		
		dfs(to,v);
		res.pb(v);
		vis^=1;
	}
	x[v]^=(vis&1);
	if(x[v]) {

		if(p==-1){
			flag=1;
			x[v]=0;
		}
		else{
			x[p]^=1;
			res.pb(p);
			res.pb(v);
			x[v]=0;
		}
	}
}


int main(){
	cin>>n>>m;
	REP(i,m){
		int a,b;scanf("%d%d",&a,&b);--a;--b;
		g[a].pb(b);
		g[b].pb(a);
	}
	REP(i,n) scanf("%d",&x[i]);
	
	int st=-1;
	REP(i,n) if(x[i]) st=i;

	if(st==-1){
		puts("0");
		return 0;
	}

	dfs(st,-1);
	
	REP(i,n) if(x[i]){
		puts("-1");
		return 0;
	}
	

	if(flag) res.erase(res.begin());

	cout<<res.size()<<endl;
	REP(i,res.size()) printf("%d%c",res[i]+1,i==res.size()-1?'\n':' ');

	return 0;
}