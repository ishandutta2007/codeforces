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
int n,q;
int ar[100005],flip[100005];
pair<pi,double> query[5005];


double dp[5005][10005];

int done[5005];

bool cmp(const pair<pi,double>& a,const pair<pi,double>& b){
  if(a.fr.fr!=b.fr.fr) return a.fr.fr<b.fr.fr;
  return a.fr.sc>b.fr.sc;
}


void sumup(int v){
  REP(i,2*q){
    dp[v][i+1]+=dp[v][i];
  }
}

segtree seg;
void rec(int v){
  done[v]=1;
  int l=query[v].fr.fr,r=query[v].fr.sc;

  vector<int> chil;
  REP(i,q) if(i!=v && !done[i]){
    if(l<=query[i].fr.fr && query[i].fr.sc<=r){
      chil.pb(i);
      rec(i);
    }
  }

  for(auto to:chil){
    sumup(to);
  }

  REP(i,q*2+1){
    dp[v][i]=1;
    for(auto to:chil){
      dp[v][i]*=dp[to][i];
    }
  }
  for(int i=2*q;i>0;--i) dp[v][i]-=dp[v][i-1];

  int mx=-seg.query(l,r,0,0,seg.n);

  REP(i,mx){
    dp[v][mx]+=dp[v][i];
    dp[v][i]=0;
  }

  double p=query[v].sc;

  for(int i=q*2;i>=0;--i){
    dp[v][i]*=(1-p);
    if(i>0) dp[v][i]+=dp[v][i-1]*p;
  }
}

int main(){
  cin>>n>>q;
  REP(i,n) scanf("%d",&ar[i]);

  int mx=*max_element(ar,ar+n);
  int base=0;
  if(mx>q){
    int dif=mx-q;
    REP(i,n) ar[i]-=dif;
    base=dif;
  }

  REP(i,n) flip[i]=-ar[i];
  seg.init(n,flip);



  REP(i,q){
    int l,r;
    double p;cin>>l>>r>>p;--l;
    query[i]=mp(mp(l,r),p);
  }

  query[q]=mp(mp(0,n),0);
  ++q;
  sort(query,query+q,cmp);


  rec(0);

  double res=0;
  REP(i,2*q+1) res+=i*dp[0][i];


  printf("%.10f\n",res+base);

  return 0;
}