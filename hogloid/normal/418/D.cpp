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
const int INF=5e8;
vector<int> g[100005];
int n,m;

int dep[100005];
int par[20][100005];
vector<pi> maxlen[100005];
int climb[20][100005],climb2[20][100005];
int upper[100005];
void prep(int v,int p,int d=0){
	par[0][v]=p;
	dep[v]=d;

	for(auto to:g[v]){
		if(to==p) continue;
		prep(to,v,d+1);
		
		maxlen[v].pb(mp(maxlen[to][0].fr+1,to));
	}
	maxlen[v].pb(mp(0,-1));
	sort(ALL(maxlen[v]),greater<pi>());
}

int getexc(int v,int exc,int exc2=-2){
	if(maxlen[v][0].sc!=exc && maxlen[v][0].sc!=exc2) return maxlen[v][0].fr;
	if(maxlen[v][1].sc!=exc2 && maxlen[v][1].sc!=exc) return maxlen[v][1].fr;
	return maxlen[v][2].fr;
}
void prep2(int v,int p){
	if(p!=-1){
		upper[v]=max(upper[p],getexc(p,v))+1;
		climb[0][v]=getexc(p,v)-dep[p];
		climb2[0][v]=getexc(p,v)+dep[p];
		dump(climb[0][v]);dump(climb2[0][v]);
	}else{
		climb2[0][v]=climb[0][v]=-INF;
	}
	for(auto to:g[v]){
		if(to==p) continue;
		prep2(to,v);
	}
}

int lca(int a,int b){
	if(dep[a]>dep[b]) swap(a,b);
	int dif=dep[b]-dep[a];
	REP(i,20) if(dif>>i&1) b=par[i][b];
	if(a==b) return a;
	for(int i=19;i>=0;--i) if(par[i][a]!=par[i][b]){
		a=par[i][a];
		b=par[i][b];
	}
	return par[0][a];
}

int getpar(int a,int k){
	REP(i,20) if(k>>i&1) a=par[i][a];
	return a;
}

int climbUp(int a,int k){
	int res=-INF;
	REP(i,20) if(k>>i&1){
		chmax(res,climb[i][a]);
		a=par[i][a];
	}
	return res;
}
int climbDown(int a,int k){
	int res=-INF;
	REP(i,20) if(k>>i&1){
		chmax(res,climb2[i][a]);
		a=par[i][a];
	}
	return res;
}


int main(){
	cin>>n;
	REP(i,n-1){
		int a,b;scanf("%d%d",&a,&b);--a;--b;
		g[a].pb(b);
		g[b].pb(a);
	}
	prep(0,-1);

	prep2(0,-1);


	REP(i,19){
		REP(j,n){
			if(par[i][j]==-1){
				par[i+1][j]=-1;
				climb[i+1][j]=climb[i][j];
				climb2[i+1][j]=climb2[i][j];
			}else{
				par[i+1][j]=par[i][par[i][j]];
				climb[i+1][j]=max(climb[i][j],climb[i][par[i][j]]);
				climb2[i+1][j]=max(climb2[i][j],climb2[i][par[i][j]]);
			}
		}
	}
	debug(climb[0],climb[0]+n);
	debug(climb2[0],climb2[0]+n);

	cin>>m;

	REP(hoge,m){
		int a,b;scanf("%d%d",&a,&b);--a;--b;
		if(dep[b]<dep[a]) swap(a,b);
		int L=lca(a,b),length=dep[a]+dep[b]-dep[L]*2;
		
		int div=getpar(b,(length-1)/2);
		
		int res=0;
		if(a!=L){
			chmax(res,maxlen[a][0].fr);
			chmax(res,maxlen[b][0].fr);
			chmax(res,climbUp(b,(length-1)/2)+dep[b]);
			chmax(res,climbUp(a,dep[a]-dep[L]-1)+dep[a]);
			chmax(res,getexc(L,getpar(a,dep[a]-dep[L]-1),getpar(b,dep[b]-dep[L]-1))+dep[a]-dep[L]);
			chmax(res,upper[L]+dep[a]-dep[L]);
			chmax(res,climbDown(div,dep[div]-dep[L]-1)-dep[L]+dep[a]-dep[L]);
		}else{
			dump(L);dump(div);dump(length);
			chmax(res,maxlen[b][0].fr);
			dump(res);
			chmax(res,getexc(L,getpar(b,dep[b]-dep[L]-1)));
			dump(res);
			chmax(res,climbUp(b,(length-1)/2)+dep[b]);
			dump(res);
			chmax(res,climbDown(div,dep[div]-dep[L]-1)-dep[L]);
			chmax(res,upper[a]);
			chmax(res,climbDown(div,dep[div]-dep[L]-1)-dep[L]);
		}
		printf("%d\n",res);
	}

	return 0;
}