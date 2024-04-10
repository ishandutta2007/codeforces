#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#define REP(i,m) for(int i=0;i<m;++i)
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
int n,m1,m2;
int fail[2005];
struct uf{
	int par[2005],size[2005];
	uf(){
		memset(par,-1,sizeof(par));
		REP(i,2005) size[i]=1;
	}
	int root(int a){
		if(par[a]==-1) return a;
		return par[a]=root(par[a]);
	}
	void unite(int a,int b){
		a=root(a);b=root(b);
		if(a==b) return;
		size[b]+=size[a];
		par[a]=b;
	}
	bool same(int a,int b){
		return root(a)==root(b);
	}
};
uf u;
int main(){
	scanf("%d%d",&n,&m1);
	REP(i,m1){
		int a,b;scanf("%d%d",&a,&b);--a;--b;
		u.unite(a,b);
	}
	scanf("%d",&m2);
	REP(i,m2){
		int a,b;scanf("%d%d",&a,&b);--a;--b;
		if(u.same(a,b)) fail[u.root(a)]=1;
	}
	int res=0;
	REP(i,n) if(fail[u.root(i)]==0) res=max(res,u.size[u.root(i)]);
	printf("%d\n",res);


	return 0;
}