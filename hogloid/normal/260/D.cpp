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

int n;
int col[100005],sum[100005];
struct uf{
	int par[100005];
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
	bool same(int a,int b){
		return root(a)==root(b);
	}
};
uf u;
pair<pi,int> es[100005];
int main(){
	scanf("%d",&n);
	REP(i,n) scanf("%d %d\n",&col[i],&sum[i]);
	int j=0,m=0;
	REP(i,n) if(col[i]==0){
		while(j<n && sum[i]>0){
			if(col[j]==0 || sum[j]==0){
				++j;
				continue;
			}
			int v=min(sum[i],sum[j]);
			es[m++]=mp(mp(i,j),v);
			sum[i]-=v;sum[j]-=v;
			u.unite(i,j);
		}
	}
	int colA,colB;
	REP(i,n){
		if(col[i]==0) colA=i;
		else colB=i;
	}
	REP(i,n){
		if(col[i]==0 && u.same(i,colB)==false){
			u.unite(i,colB);
			es[m++]=mp(mp(i,colB),0);
		}
		if(col[i]==1 && u.same(i,colA)==false){
			u.unite(i,colA);
			es[m++]=mp(mp(i,colA),0);
		}
	}
	REP(i,m) printf("%d %d %d\n",es[i].fr.fr+1,es[i].fr.sc+1,es[i].sc);
	return 0;
}