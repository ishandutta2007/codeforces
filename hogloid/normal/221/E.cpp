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
int a[100005],b[100005],reva[100005],revb[100005];
int mini[100005];
struct segtree{
	int n,ownN;
	int val[1200005];
	void init(int n_){
		ownN=n_;
		n=1;
		while(n<n_) n<<=1;
		REP(i,n*2) val[i]=INF;
	}
	void set(int a,int b,int i,int l,int r,int v){
		if(a<=l && r<=b){
			val[i]=min(val[i],v);
			return;
		}
		if(b<=l || r<=a) return;
		int md=(l+r)>>1;
		set(a,b,i*2+1,l,md,v);
		set(a,b,i*2+2,md,r,v);
	}
	int get(int k){
		int prevk=k;
		k+=n-1;
		int res=val[k];
		while(k>0){
			k=(k-1)/2;
			res=min(res,val[k]);
		}
		return res+prevk;
	}
	int get2(int k){
		int prevk=k;
		k+=n-1;
		int res=val[k];
		while(k>0){
			k=(k-1)/2;
			res=min(res,val[k]);
		}
		return res-prevk;
	}
};
segtree inc,decr;
int main(){
	cin>>n;
	REP(i,n) scanf("%d",&a[i]),--a[i],reva[a[i]]=i;
	REP(i,n) scanf("%d",&b[i]),--b[i],revb[b[i]]=i;
	inc.init(n);
	decr.init(n);
	REP(i,n){
		int dif=(reva[i]-revb[i]+n)%n,lim=(n-revb[i]);
		if(reva[i]>=revb[i]){
			inc.set(dif,lim,0,0,inc.n,-dif);
			decr.set(0,dif,0,0,decr.n,dif);
			decr.set(lim,n,0,0,inc.n,dif+n);
		}else{
			inc.set(dif,n,0,0,inc.n,-dif);
			inc.set(0,lim,0,0,inc.n,-dif+n);
			decr.set(lim,dif,0,0,decr.n,dif);
		}
	}
	REP(i,n){
		int res=INF;
		res=min(res,min(inc.get((n-i)%n),decr.get2((n-i)%n)));
		printf("%d\n",res);
	}
	return 0;
}