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


int n,m;
pi isl[200005];

lint ar[200005];

pair<pi,int> range[200005];

bool cmp(const pair<pi,int>& a,const pair<pi,int>& b){
  if(a.fr.sc!=b.fr.sc) return a.fr.sc<b.fr.sc;
  return a<b;
}

set<pair<lint,int> >exist;

int res[200005];
int main(){
  cin>>n>>m;
  REP(i,n){
    isl[i].fr=readL();
    isl[i].sc=readL();
  }
  REP(i,m) ar[i]=readL();

  REP(i,m) exist.insert(mp(ar[i],i));

  REP(i,n-1){
    lint lb=isl[i+1].fr-isl[i].sc;
    lint ub=isl[i+1].sc-isl[i].fr;

    range[i]=mp(mp(lb,ub),i);
  }
  --n;
  sort(range,range+n,cmp);

  REP(i,n){
    lint l=range[i].fr.fr,r=range[i].fr.sc;
    auto it=exist.lower_bound(mp(l,-1));
    if(!(it==exist.end() || it->fr>r)){
      res[range[i].sc]=it->sc;
      exist.erase(it);
    }else{
      puts("No");
      return 0;
    }
  }
  puts("Yes");
  REP(i,n) printf("%d\n",res[i]+1);
  return 0;
}