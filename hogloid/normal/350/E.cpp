#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#define REP(i,m) for(int i=0;i<m;++i)
#define REPN(i,m,in) for(int i=in;i<m;++i)
#define ALL(t) (t).begin(),(t).end()
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
using namespace std;
static const int INF =500000000; 
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
typedef long long int lint;
typedef pair<int,int> pi;

int n,m,k;
int mark[305];

struct uf{
	int par[305];
	uf(){
		memset(par,-1,sizeof(par));
	}
	int root(int a){
		if(par[a]==-1) return a;
		return par[a]=root(par[a]);
	}
	void unite(int a,int b){
		a=root(a);b=root(b);
		if(a==b) return;
		par[a]=b;
	}
};
uf u;
pi es[100005];
int main(){
	cin>>n>>m>>k;
	REP(i,k){
		int a;cin>>a;
		--a;
		mark[a]=1;
	}

	if(k==n || m>=n*(n-1)/2-k+2) puts("-1");
	else{
		int unm;
		REP(i,n) if(!mark[i]) unm=i;
		
		int a=-1,b=-1;
		REP(i,n) if(mark[i] && unm!=i) a=i;
		if(a==-1) REP(i,n) if(unm!=i) a=i;

		REP(i,n) if(mark[i] && unm!=i && a!=i) b=i;
		if(b==-1) REP(i,n) if(unm!=i && a!=i) b=i;
		
		u.unite(a,unm);
		u.unite(b,unm);
		
		int cnt=0;
		
		es[cnt++]=mp(a,unm);
		es[cnt++]=mp(unm,b);
		REP(i,n) if(u.root(i)!=u.root(unm)){
			es[cnt++]=mp(i,unm);
			u.unite(i,unm);
		}
		
		REP(i,n) REP(j,i) if(i!=unm && i!=a && i!=b &&
				j!=unm && j!=a && j!=b){
			es[cnt++]=mp(i,j);
		}
		REP(i,n) if(i!=unm && i!=a && i!=b){
			if(!mark[i]){
				es[cnt++]=mp(a,i);
				es[cnt++]=mp(i,b);
			}
			if(mark[i]) es[cnt++]=mp(a,i);
		}
		
		REP(i,m) printf("%d %d\n",es[i].fr+1,es[i].sc+1);
	}
	return 0;
}