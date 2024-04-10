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

//const int INF=5e8;
int n;
pi ps[200005];
map<pi,vector<int> > ids;
bool judge(const pi&a){
  return a==mp(-1,-1);
}

pi stk[200005];
long double divv(const pi&a ,const pi&b){
  //assume a.fr<b.fr, a.sc>b.sc
  long double dif=1.0/b.sc-1.0/a.sc;
  long double S=dif/(1.0/a.fr-1.0/b.fr);
  return S;
}
int main(){
  cin>>n;
  REP(i,n){
    scanf("%d%d",&ps[i].fr,&ps[i].sc);
    ids[ps[i]].pb(i);
  }

  sort(ps,ps+n);
  int rmax=-1;
  for(int i=n-1;i>=0;--i){
    if(rmax>=ps[i].sc){
      ps[i]=mp(-1,-1);
    }
    chmax(rmax,ps[i].sc);
  }
  n=remove_if(ps,ps+n,judge)-ps;

  int m=0;
  REP(i,n){
    while(m>1 && divv(stk[m-2],stk[m-1])>divv(stk[m-1],ps[i])+1e-10){
      --m;
    }
    stk[m++]=ps[i];
  }
  vector<int> res;
  REP(i,m){
    for(auto e:ids[stk[i]]) res.pb(e);
  }
  sort(ALL(res));
  for(auto e:res) printf("%d\n",e+1);
  return 0;
}