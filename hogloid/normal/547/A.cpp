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
int m;
bool vis[1000005];
void solve(lint& r,lint& T){
  int h,a,x,y;cin>>h>>a>>x>>y;
  CLR(vis);
  r=T=0;
  while(h!=a){
    if(vis[h]){
      r=0;
      T=-2;
      return;
    }
    vis[h]=1;
    h=(h*(lint)x+y)%m;
    ++r;
  }
  REP(i,m+1){
    h=(h*(lint)x+y)%m;
    if(h==a){
      T=i+1;
      return;
    }
  }
  T=-1;
}
int main(){
  cin>>m;
  lint r1,T1,r2,T2;
  solve(r1,T1);
  solve(r2,T2);

  lint res;
  if(T1==-2  || T2==-2) res=-1;
  else if(r1==r2) res=r1;
  else{
    res=-1;
    REP(i,m*4+10){
      if(r1==r2){
        res=r1;
        break;
      }else if(r1<r2){
        if(T1==-1) break;
        r1+=T1;
      }else if(r1>r2){
        if(T2==-1) break;
        r2+=T2;
      }
    }
  }
  cout<<res<<endl;

  return 0;
}