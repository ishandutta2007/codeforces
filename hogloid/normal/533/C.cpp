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

int main(){
  int x1,y1,x2,y2;
  cin>>x1>>y1>>x2>>y2;
  if(x2<y2){
    swap(x1,y1);
    swap(x2,y2);
  }
  bool first=false;
  if(x2-y2<x1-y1){
    int c1=(x1-y1)-(x2-y2);
    int c2=y2-y1;
    if(c1<=c2) first=true;
  }else{
    if(y1<(x2-y2)-(x1-y1)){
      int c1=y1;
      int c2=(x2-x1);
      if(c1<=c2) first=true;
    }else{
      int c1=(x2-y2)-(x1-y1);
      int c2=(x2-x1);
      if(c1<=c2) first=true;
    }
  }
  puts(first?"Polycarp":"Vasiliy");

  return 0;
}