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


int cnt1,cnt2,x,y;

lint lcm(lint x,lint y){
  return x/__gcd(x,y)*y;
}
int main(){
  cin>>cnt1>>cnt2>>x>>y;

  lint lb=1,ub=1e10;
  while(ub-lb>1){
    lint md=(lb+ub)>>1;

    lint X=md/x,Y=md/y,both=md/lcm(x,y);
    X-=both;Y-=both;

    int cnt12=cnt1-Y;
    int cnt22=cnt2-X;

    chmax(cnt12,0);
    chmax(cnt22,0);

    lint other=md-X-Y-both;
    if(cnt12+cnt22<=other) ub=md;
    else lb=md;
  }
  cout<<ub<<endl;


    

  return 0;
}