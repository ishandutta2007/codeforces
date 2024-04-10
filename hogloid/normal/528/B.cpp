#include<bits/stdc++.h>
#define REP(i,m) for(int i=0;i<(m);++i)
#define REPN(i,m,in) for(int i=(in);i<(m);++i)
#define ALL(t) (t).begin(),(t).end()
#define CLR(a) memset((a),0,sizeof(a))
#define pb push_back
#define mp make_pair
#define fr first
#define sc second

using namespace std;


#ifndef ONLINE_JUDGE
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
#else
#define dump(x) ;
#define prl ;
template<class T> void debug(T a,T b){ ;}
#endif

template<class T> void chmin(T& a,const T& b) { if(a>b) a=b; }
template<class T> void chmax(T& a,const T& b) { if(a<b) a=b; }
typedef long long int lint;
typedef pair<int,int> pi;

namespace std{
  template<class S,class T>
  ostream &operator <<(ostream& out,const pair<S,T>& a){
    out<<'('<<a.fr<<','<<a.sc<<')';
    return out;
  }
}

lint readL(){
  lint res;
#ifdef ONLINE_JUDGE
  scanf("%I64d",&res);
#else
  scanf("%lld",&res);
#endif
  return res;
}
void printL(lint res){
#ifdef ONLINE_JUDGE
  printf("%I64d",res);
#else
  printf("%lld",res);
#endif
}

const int INF=5e8;
struct segtree{
	static const int MAX_N=800000;
	int val[MAX_N];
	int n;
	void init(int n_){
		n=1;
		while(n<n_) n<<=1;
		REP(i,n*2) val[i]=-INF;
	}
	void set(int k,int a){
		k+=n-1;
		val[k]=max(a,val[k]);
		while(k>0){
			k=(k-1)/2;
			val[k]=max(val[k*2+1],val[k*2+2]);
		}
	}
	int query(int a,int b,int i,int l,int r){
		if(a<=l && r<=b) return val[i];
		if(b<=l || r<=a) return -INF;
		int md=(l+r)>>1;
		return max(query(a,b,i*2+1,l,md),query(a,b,i*2+2,md,r));
	}
};
segtree seg;
int n;
pi ps[200005];
int zip[200005];
int main(){
  cin>>n;
  REP(i,n) scanf("%d%d",&ps[i].fr,&ps[i].sc);
  REP(i,n) zip[i]=ps[i].fr+ps[i].sc;
  sort(zip,zip+n);
  int zn=unique(zip,zip+n)-zip;
  seg.init(zn);
  sort(ps,ps+n);

  int res=0;
  REP(i,n){
    int d=ps[i].fr-ps[i].sc;
    int p=upper_bound(zip,zip+zn,d)-zip;

    int tmp=max(0,seg.query(0,p,0,0,seg.n));
    int p2=lower_bound(zip,zip+zn,ps[i].fr+ps[i].sc)-zip;
    seg.set(p2,tmp+1);
    chmax(res,tmp+1);
  }
  cout<<res<<endl;
  return 0;
}