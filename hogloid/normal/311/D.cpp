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
const lint mod=95542721;
const int L=48;
struct segtree{
	lint val[400005][50];
	int sh[400005];
	int n;
	inline lint pow3(lint a){
		return a*a%mod*a%mod;
	}
	void init(int n_,int* ar){
		n=1;
		while(n<n_) n<<=1;
		REP(i,n_){
			val[i+n-1][0]=ar[i];
			REP(j,L-1){
				val[i+n-1][j+1]=pow3(val[i+n-1][j]);
			}
		}
		memset(sh,0,sizeof(sh));
		for(int i=n-2;i>=0;--i) REP(j,L) val[i][j]=(val[i*2+1][j]+val[i*2+2][j])%mod;
	}
	lint tmp[50],tmp2[50];
	void shift(int i,int k){
		REP(j,L){
			tmp[j]=val[i][(j+k)%L];
		}
		REP(j,L) val[i][j]=tmp[j];
		sh[i]+=k;
	}

	void push(int i){
		if(sh[i]==0) return;
		shift(i*2+1,sh[i]);
		shift(i*2+2,sh[i]);
		sh[i]=0;
	}


	lint query(int a,int b,int i,int l,int r){
		if(a<=l && r<=b) return val[i][0];
		if(b<=l || r<=a) return 0;
		push(i);
		int md=(l+r)>>1;
		return (query(a,b,i*2+1,l,md)+query(a,b,i*2+2,md,r))%mod;
	}
	void update(int a,int b,int i,int l,int r){
		if(a<=l && r<=b){
			shift(i,1);
			return;
		}
		if(b<=l || r<=a) return;
		int md=(l+r)>>1;
		push(i);
		update(a,b,i*2+1,l,md);
		update(a,b,i*2+2,md,r);

		REP(j,L) val[i][j]=(val[i*2+1][j]+val[i*2+2][j])%mod;
	}
};
int n;
int ar[100005];
segtree seg;
int main(){
	scanf("%d",&n);
	REP(i,n) scanf("%d",&ar[i]);


	seg.init(n,ar);
	int q;scanf("%d",&q);
	REP(hoge,q){
		int t,l,r;scanf("%d%d%d",&t,&l,&r);
		--l;
		if(t==2) seg.update(l,r,0,0,seg.n);
		else printf("%d\n",(int)seg.query(l,r,0,0,seg.n));
	}
	return 0;
}