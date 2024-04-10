#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#define REP(i,m) for(int i=0;i<(int)m;++i)
#define REPN(i,m,in) for(int i=in;i<(int)m;++i)
#define pb push_back
#define mp make_pair
#define fr first
#define ALL(t) (t).begin(),(t).end()
#define sc second
#define INF ((int)5e8)
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define prl cerr<<"called:"<< __LINE__<<endl;
using namespace std;
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
typedef long long int lint;
typedef pair<int,int> pi;
struct uf{
	int par[100005];
	int size[100005];
	uf(){
		memset(par,-1,sizeof(par));
		REP(i,100005) size[i]=1;
	}
	int root(int a){
		if(par[a]==-1) return a;
		return par[a]=root(par[a]);
	}
	void unite(int a,int b){
		a=root(a);b=root(b);
		if(a==b) return;
		par[a]=b;
		size[b]+=size[a];
	}
};
uf u;
vector<int> comp;
int main(){
	int n,m,k;scanf("%d%d%d",&n,&m,&k);
	REP(i,m){
		int a,b;scanf("%d%d",&a,&b);--a;--b;
		u.unite(a,b);
	}
	REP(i,n) if(u.root(i)==i) comp.pb(u.size[i]);
	lint mod=k;
	lint res=1%mod;
	if(comp.size()>=2){
		REP(i,comp.size()) res*=comp[i],res%=mod;
		REP(i,comp.size()-2) res*=n,res%=mod;
	}
	cout<<res<<endl;
	return 0;
}