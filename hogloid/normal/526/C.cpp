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
lint c,h1,h2,w1,w2;
int main(){
  cin>>c>>h1>>h2>>w1>>w2;
  lint res=0;
  if(c>=w1*w2*2){
    lint prevc=c;
    c%=(w1*w2);
    c+=w1*w2;
    lint dif=(prevc-c)/(w1*w2);
    res+=dif*max(w1*h2,w2*h1);
  }
  if(w1>w2){
    swap(w1,w2);
    swap(h1,h2);
  }
  lint base=res;
  REP(i,w1*2+1){
    lint rest=c-w2*i;
    if(rest<0) continue;
    lint tmp=base+h2*i;
    tmp+=(rest/w1)*h1;
    chmax(res,tmp);
  }
  cout<<res<<endl;
  return 0;
}