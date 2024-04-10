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
int n;
vector<int> g[100005];
int flip[100005];
vector<int> res;

void dfs(int v,int p,int flipCur=0,int flipNext=0){
	flip[v]^=flipCur;
	if(flip[v]){
		flipCur^=1;
		res.pb(v);
	}
	for(auto to:g[v]){
		if(to==p) continue;
		dfs(to,v,flipNext,flipCur);
	}
}

int main(){
	cin>>n;
	REP(i,n-1){
		int a,b;scanf("%d%d",&a,&b);--a;--b;
		g[a].pb(b);
		g[b].pb(a);
	}

	REP(i,n){
		int a;scanf("%d",&a);
		flip[i]^=a;
	}
	REP(i,n){
		int a;scanf("%d",&a);
		flip[i]^=a;
	}
	dfs(0,-1,0,0);

	cout<<res.size()<<endl;
	sort(ALL(res));
	REP(i,res.size()) printf("%d\n",res[i]+1);


	return 0;
}