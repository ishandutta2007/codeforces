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

const int INF=1e9+15;
struct segtree{
	static const int MAX_N=400005;
	int val[MAX_N];
	int n;
	void init(int n_,int *a){
		n=1;
		while(n<n_) n<<=1;
		REP(i,n*2) val[i]=INF;
		REP(i,n_) val[i+n-1]=a[i];
		for(int i=n-2;i>=0;--i) val[i]=min(val[i*2+1],val[i*2+2]);
	}
	void set(int k,int a){
		k+=n-1;
		val[k]=a;
		while(k>0){
			k=(k-1)/2;
			val[k]=min(val[k*2+1],val[k*2+2]);
		}
	}
	int query(int a,int b,int i,int l,int r){
		if(a<=l && r<=b) return val[i];
		if(b<=l || r<=a) return INF;
		int md=(l+r)>>1;
		return min(query(a,b,i*2+1,l,md),query(a,b,i*2+2,md,r));
	}
};

segtree mini,maxi;
int n,s,l;
int ar[100005],flip[100005];

int till[100005];

bool able(int l,int r){//[l...r]
  return (-maxi.query(l,r+1,0,0,maxi.n)-mini.query(l,r+1,0,0,mini.n)<=s);
}

int dp[100005];

int main(){
  cin>>n>>s>>l;
  REP(i,n) scanf("%d",&ar[i]),flip[i]=-ar[i];

  mini.init(n,ar);
  maxi.init(n,flip);

  int j=0;
  REP(i,n){
    while(j<n && able(i,j)){
      ++j;
    }
    //[i...j)
    till[i]=j;
  }


  REP(i,n+1) dp[i]=INF;
  dp[0]=0;

  int st=1;
  REP(i,n){
    if(till[i]-i<l || dp[i]==INF) continue;

    for(int j=max(st,i+l);j<=till[i];++j) chmin(dp[j],dp[i]+1);
    chmax(st,till[i]);
  }

  if(dp[n]==INF) dp[n]=-1;

  printf("%d\n",dp[n]);

  return 0;
}