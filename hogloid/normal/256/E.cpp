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
const lint mod=777777777;
int ok[3][3];
struct segtree{
	struct node{
		int left,right;
		lint a[3][3];
		node(){
			memset(a,0,sizeof(a));
		}
	};
	int where[400005];
	void merge(node& a,node& b,node& res){
		res=node();
		REP(i,3) REP(j,3) if(a.a[i][j]) REP(k,3) if(ok[j][k]) REP(l,3) if(b.a[k][l]) res.a[i][l]=
				(res.a[i][l]+a.a[i][j]*b.a[k][l])%mod;
	}
	node val[400005];
	int n;
	void build(int i,int l,int r){
		val[i].left=l;val[i].right=r;
		if(r-l==1){
			where[l]=i;
			REP(t,3) val[i].a[t][t]=1;
			return;
		}
		int md=(l+r)>>1;
		build(i*2+1,l,md);
		build(i*2+2,md,r);
		merge(val[i*2+1],val[i*2+2],val[i]);
	}
	void init(int n_){
		n=n_;
		build(0,0,n);
	}
	void set(int k,int a){
		k=where[k];
		val[k]=node();
		if(a>=0) val[k].a[a][a]=1;
		else REP(i,3) val[k].a[i][i]=1;
		while(k>0){
			k=(k-1)/2;
			merge(val[k*2+1],val[k*2+2],val[k]);
		}
	}

	int q(){
		int res=0;
		REP(i,3) REP(j,3) res=(res+val[0].a[i][j])%mod;
		return res;
	}
};
segtree seg;
int n,m;
int main(){
	cin>>n>>m;
	REP(i,3) REP(j,3) cin>>ok[i][j];
	seg.init(n);
	REP(hoge,m){
		int v,t;cin>>v>>t;
		--v;--t;
		seg.set(v,t);
		cout<<seg.q()<<endl;
	}
	return 0;
}