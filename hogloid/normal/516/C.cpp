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
typedef pair<lint,lint> pi;

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

const lint INF=1e18;
int n,m;
lint d[200005],h[200005];


struct segtree{
	static const int MAX_N=800005;
	pi val[MAX_N];
	int n;
	void init(int n_){
		n=1;
		while(n<n_) n<<=1;
    REP(i,n_) val[i+n-1].sc=i;
    for(int i=n-2;i>=0;--i) val[i].sc=val[i*2+1].sc;

		REP(i,n*2) val[i].fr=-INF;
	}
	void set(int k,lint a){
		k+=n-1;
		val[k].fr=a;
		while(k>0){
			k=(k-1)/2;
			val[k]=max(val[k*2+1],val[k*2+2]);
		}
	}
	pi query(int a,int b,int i,int l,int r){
		if(a<=l && r<=b) return val[i];
		if(b<=l || r<=a) return mp(-INF,0);
		int md=(l+r)>>1;
		return max(query(a,b,i*2+1,l,md),query(a,b,i*2+2,md,r));
	}
};

segtree R,L;

int main(){
  cin>>n>>m;
  REP(i,n){
    int a;scanf("%d",&a);
    d[i+1]=d[i+n+1]=a;
  }
  REP(i,n){
    int a;scanf("%d",&a);
    h[i]=h[i+n]=a*2;
  }

  REP(i,n*2) d[i+1]+=d[i];

  R.init(n*2);
  L.init(n*2);

  REP(i,n*2){
    R.set(i,h[i]+d[i]);
    L.set(i,h[i]-d[i]);
  }

  REP(hoge,m){
    int a,b;scanf("%d%d",&a,&b);
    int l,r;
    if(a<=b){
      --a;
      l=b;r=a+n;
    }else{
      --a;
      l=b;
      r=a;
    }

    pi R1=R.query(l,r,0,0,R.n),
    R2=max(R.query(l,R1.sc,0,0,R.n),R.query(R1.sc+1,r,0,0,R.n));

    pi L1=L.query(l,r,0,0,R.n),
    L2=max(L.query(l,L1.sc,0,0,R.n),L.query(L1.sc+1,r,0,0,R.n));

    lint res=0;
    if(R1.sc==L1.sc){
      res=max(R1.fr+L2.fr,R2.fr+L1.fr);
    }else{
      res=R1.fr+L1.fr;
    }

    printL(res);
    putchar('\n');
  }
  return 0;
}