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
struct segtree{
	vector<int> val[2200000];
	int n;
	void init(int n_,int *ar){
		n=1;
		while(n<n_) n<<=1;
		REP(i,n_){
			val[i+n-1].pb(ar[i]);
		}
		for(int i=n-2;i>=0;--i){
			val[i].resize(val[i*2+1].size()+val[i*2+2].size());
			merge(ALL(val[i*2+1]),ALL(val[i*2+2]),val[i].begin());
		}
	}
	int query(int a,int b,int i,int l,int r,int ub,int lb){
		if(a<=l && r<=b){
			return lower_bound(ALL(val[i]),ub)-
					lower_bound(ALL(val[i]),lb);
		}
		if(b<=l || r<=a) return 0;
		int md=(l+r)>>1;
		return query(a,b,i*2+1,l,md,ub,lb)+query(a,b,i*2+2,md,r,ub,lb);
	}
};
segtree seg;
int n;
int perm[1000005],perm2[1000005];
int pos2[1000005],crsp[1000005];

int x=0;
int f(int a){
	return (a-1+x)%n;
}

int main(){
	scanf("%d",&n);
	REP(i,n){
		scanf("%d",&perm[i]);
		--perm[i];
	}
	REP(i,n){
		scanf("%d",&perm2[i]);
		--perm2[i];
		pos2[perm2[i]]=i;
	}

	REP(i,n) crsp[i]=pos2[perm[i]];

	seg.init(n,crsp);

	int m;scanf("%d",&m);
	REP(hoge,m){
		int a,b,c,d;scanf("%d%d%d%d",&a,&b,&c,&d);
		int A=f(a),B=f(b),
			C=f(c),D=f(d);

		int l1=min(A,B),r1=max(A,B),
			l2=min(C,D),r2=max(C,D);
		++r1;++r2;
		

		int res=seg.query(l1,r1,0,0,seg.n,r2,l2);
		x=res+1;
		printf("%d\n",res);
	}



	return 0;
}