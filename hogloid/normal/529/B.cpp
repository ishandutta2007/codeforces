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

const int INF=1e9+10;

int n;
pi rect[1005];
int main(){
  cin>>n;
  REP(i,n) cin>>rect[i].fr>>rect[i].sc;

  int res=INF;
  for(int h=1;h<=1000;++h){
    vector<int> dif;
    int baseW=0;
    int flip=0;
    bool fail=false;
    REP(i,n){
      if(rect[i].sc<=h && rect[i].fr<=h){
        baseW+=rect[i].fr;
        if(rect[i].sc-rect[i].fr<0) dif.pb(rect[i].sc-rect[i].fr);
      }else if(rect[i].sc<=h){
        baseW+=rect[i].fr;
      }else if(rect[i].fr<=h){
        flip++;
        baseW+=rect[i].sc;
      }else{
        fail=1;
        break;
      }
    }
    if(fail || flip*2>n) continue;
    int rest=n/2-flip;
    sort(ALL(dif));
    chmin(rest,(int)dif.size());
    REP(i,rest) baseW+=dif[i];
    chmin(res,baseW*h);
  }
  cout<<res<<endl;




  return 0;
}