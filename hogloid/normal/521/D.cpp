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

//const int INF=5e8;

int k,n,m;
int ar[100005];

vector<pi> add[100005];
pi ass[100005];
vector<pi> mult;

pair<pi,pi> eve[100005];

bool cmp(const pair<pi,pi>& a,const pair<pi,pi>& b){
  if(a.fr.fr/a.fr.sc!=b.fr.fr/b.fr.sc)
    return a.fr.fr/a.fr.sc<b.fr.fr/b.fr.sc;
  return (a.fr.fr%a.fr.sc)*b.fr.sc<(b.fr.fr%b.fr.sc)*a.fr.sc;
}

int main(){
  cin>>k>>n>>m;
  REP(i,k) scanf("%d",&ar[i]);

  REP(i,n) ass[i]=mp(-1,-1);

  REP(i,n){
    int t,j,b;scanf("%d%d%d",&t,&j,&b);
    --j;
    if(t==1){
      chmax(ass[j],mp((lint)b,(lint)i+1));
    }else if(t==2){
      add[j].pb(mp(b,i+1));
    }else{
      mult.pb(mp(b,i+1));
    }
  }

  REP(i,k){
    if(ass[i].fr>ar[i]) add[i].pb(mp(ass[i].fr-ar[i],-ass[i].sc));
  }

  int cnt=0;
  REP(i,k){
    sort(ALL(add[i]),greater<pi>());
    lint ever=ar[i];
    for(auto e:add[i]){
      eve[cnt++]=mp(mp(ever+e.fr,ever),mp(abs(e.sc),(e.sc>0?2:1)));
      ever+=e.fr;
    }
  }
  for(auto e:mult){
    eve[cnt++]=mp(mp(e.fr,1),mp(e.sc,3));
  }
  sort(eve,eve+cnt,cmp);
  reverse(eve,eve+cnt);

  chmin(m,cnt);
  
  vector<pi> res;
  REP(i,m){
    res.pb(mp(eve[i].sc.sc,eve[i].sc.fr));
  }
  cout<<res.size()<<endl;
  sort(ALL(res));
  REP(i,res.size()) printf("%d\n",(int)res[i].sc);


  return 0;
}