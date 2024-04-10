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
int ar[100005];
const lint mod=1000000007;
struct segtree{
	lint val[4000005];
	int n;
	void init(int n_){
		n=1;
		while(n<n_) n<<=1;
		REP(i,n*2) val[i]=0;
	}
	void set(int k,lint a){
		k+=n-1;
		val[k]=a;
		while(k>0){
			k=(k-1)/2;
			val[k]=(val[k*2+1]+val[k*2+2])%mod;
		}
	}
	lint get(int k){
		return val[k+n-1];
	}
	lint query(int a,int b,int i,int l,int r){
		if(a<=l && r<=b) return val[i];
		if(b<=l || r<=a) return 0;
		int md=(l+r)>>1;
		return (query(a,b,i*2+1,l,md)+query(a,b,i*2+2,md,r))%mod;
	}
};
segtree seg;

int main(){
	seg.init(1000005);
	cin>>n;
	REP(i,n) scanf("%d",&ar[i]);
	
	seg.set(0,1);
	REP(i,n){
		lint lower=seg.query(0,ar[i]+1,0,0,seg.n);
		seg.set(ar[i],(lower*ar[i])%mod);
	}

	lint res=0;
	REP(i,1000005) res+=seg.get(i);
	res+=mod-1;
	res%=mod;
	cout<<res<<endl;

	return 0;
}