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

lint extgcd(lint a,lint b,lint& x,lint& y){
	if(b==0){
		x=1;y=0;
		return a;
	}
	lint d=extgcd(b,a%b,y,x);
	y-=a/b*x;
	return d;
}
typedef pair<lint,lint> pi;
typedef vector<lint> vl;
const lint INF=1e18;
lint n,m;
int a,b;
lint x[100005],y[100005];

vector<lint> X[200005],Y[200005];
void exi(){
  puts("-1");
  exit(0);
}

lint getrank(lint a){
  lint x,y;
  extgcd(m,n,x,y);
  while(x<0) x+=n;
  x*=a;
  x%=n;
  return x;
}

lint solve(vl X, vl Y){//n<=m
  if(X.empty() && Y.empty()) return INF;

  if(X.size()==n) return -1;

  int a=X.size(),b=Y.size();

  vector<pi>ps;//(rank,time)
  REP(i,a){
    int rank=getrank(X[i]);
    ps.pb(mp(rank,X[i]));
  }
  REP(i,b){
    int rank=getrank(Y[i]%n);
    ps.pb(mp(rank,Y[i]));
  }
  sort(ALL(ps));
  lint back=-1,time=INF;
  int n2=ps.size();
  REP(i,ps.size()*2){
    chmin(ps[i%n2].sc,(ps[i%n2].fr-back+n)%n*m+time);
    back=ps[i%n2].fr;time=ps[i%n2].sc;
  }

  lint res=0;
  REP(i,ps.size()) if(ps[(i+1)%n2].fr!=ps[i].fr || ps.size()==1){
    lint cost=(ps[(i+1)%n2].fr-ps[i].fr+n-1)%n*m+ps[i].sc;

    chmax(res,cost);
  }


  return res;
}

int main(){
  cin>>n>>m;
  cin>>a;
  REP(i,a) cin>>x[i];

  cin>>b;
  REP(i,b) cin>>y[i];

  int g=__gcd(n,m);
  if(g>n+m) exi();

  REP(i,a) X[x[i]%g].pb(x[i]/g);
  REP(i,b) Y[y[i]%g].pb(y[i]/g);

  lint res=0;
  n/=g;
  m/=g;
  REP(i,g){
    lint tmp,tmp2;
    if(n<=m){
      tmp=solve(X[i],Y[i]);
      swap(n,m);
      tmp2=solve(Y[i],X[i]);
      swap(n,m);
    }else{
      swap(n,m);
      tmp=solve(Y[i],X[i]);
      swap(n,m);
      tmp2=solve(X[i],Y[i]);
    }

    if(tmp>=INF || tmp2>=INF) exi();

    if(tmp<0) tmp=0;
    else tmp=tmp*g+i;
    if(tmp2<0) tmp2=0;
    else tmp2=tmp2*g+i;

    chmax(res,max(tmp,tmp2));
  }
  if(res>=INF) res=-1;
  cout<<res<<endl;



  return 0;
}