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
int n,m;
lint a[120005];
struct BIT{
	int n;
	lint val[220005];
	void init(int n_){
		n=1;
		while(n<n_) n<<=1;
		REP(i,n+1) val[i]=0;
	}
	void add(int k,lint a){
		++k;
		while(k>0){
			val[k]+=a;
			k-=k&-k;
		}
	}
	lint query(int k){
		++k;
		lint res=0;
		while(k<=n){
			res+=val[k];
			k+=k&-k;
		}
		return res;
	}
};
BIT bit[7][12];
int main(){
	scanf("%d",&n);
	REPN(z,7,2){
		int sz=z*2-2;
		REP(j,sz) bit[z][j].init(n+20);
	}
	REP(i,n){
		int A;
		scanf("%d",&A);
		a[i]=A;
		REPN(z,7,2){
			int sz=z*2-2;
			REP(j,sz){
				int p=(i%sz-j+sz)%sz,mul=p+1;
				if(mul>z) mul-=(mul-z)*2;
				bit[z][j].add(i,a[i]*mul);
			}
		}
	}
	scanf("%d",&m);
	REP(hoge,m){
		int t;scanf("%d",&t);
		if(t==1){
			int i,v;scanf("%d%d",&i,&v);--i;
			lint dif=v-a[i];
			a[i]=v;
			REPN(z,7,2){
				int sz=z*2-2;
				REP(j,sz){
					int p=(i%sz-j+sz)%sz,mul=p+1;
					if(mul>z) mul-=(mul-z)*2;
					bit[z][j].add(i,dif*mul);
				}
			}
		}else{
			int l,r,z;scanf("%d%d%d",&l,&r,&z);--l;
			int sz=z*2-2;
			int R=(r-l+sz-1)/sz*sz+l;
			lint res=bit[z][l%sz].query(l)-bit[z][R%sz].query(R);
			for(int i=r;i<R;++i){
				int p=(i-l)%sz,mul=p+1;
				if(mul>z) mul-=(mul-z)*2;
				res-=mul*a[i];
			}
			cout<<res<<endl;
		}
	}
			
	return 0;
}