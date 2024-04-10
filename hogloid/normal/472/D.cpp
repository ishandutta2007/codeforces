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

int n;
int mat[2005][2005];

int perm[2005];

bool cmp(int a,int b){
	return mat[0][a]<mat[0][b];
}

vector<int> g[2005];
lint mat2[2005][2005];

int cur;
int dfs(int v,int p){
	for(auto to:g[v]){
		if(to==p) continue;
		if(mat[to][cur]+mat[v][to]==mat[v][cur]) return dfs(to,v);
	}
	return v;
}

void dfs2(int v,int p,int from,lint sum){
	mat2[from][v]=sum;
	for(auto to:g[v]){
		if(to==p) continue;
		dfs2(to,v,from,sum+mat[v][to]);
	}
}



bool solve(){

	REP(i,n) if(mat[i][i]!=0) return false;
	REP(i,n) REP(j,n) if(mat[i][j]!=mat[j][i]) return false;
	REP(i,n) REP(j,n) if(i!=j && mat[i][j]==0) return false;

	REP(i,n) perm[i]=i;
	sort(perm,perm+n,cmp);

	for(int i=1;i<n;++i){
		int v=perm[i];
		cur=v;

		int link=dfs(0,-1);
		g[cur].pb(link);
		g[link].pb(cur);
	}

	REP(i,n){
		dfs2(i,-1,i,0);
	}

	REP(i,n) REP(j,n) if(mat[i][j]!=mat2[i][j]) return false;
	return true;
}

int main(){
	cin>>n;
	REP(i,n) REP(j,n) scanf("%d",&mat[i][j]);

	puts(solve()?"YES":"NO");


	return 0;
}