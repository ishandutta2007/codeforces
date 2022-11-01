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

lint a,b,c,d;

typedef pair<double,double> pd;
pd gett(lint a,double thr){
  return mp(-a+thr,-a-thr);
}
pd gett2(pd a,pd b){
  vector<double> vals={a.fr*b.fr,a.sc*b.fr,a.fr*b.sc,a.sc*b.sc};
  double mini=1e100,maxi=-1e100;
  for(auto e:vals){
    chmin(mini,e);
    chmax(maxi,e);
  }
  return mp(mini,maxi);
}
  
bool chk(double thr){
  pd A=gett(a,thr),B=gett(b,thr),C=gett(c,thr),D=gett(d,thr);
  pd range=gett2(A,D),range2=gett2(B,C);
  if(range.fr<=range2.sc && range2.fr<=range.sc) return true;
  return false;
}

int main(){
  cin>>a>>b>>c>>d;

  double lb=0,ub=1e9+100;
  REP(hoge,100){
    double md=(lb+ub)/2;
    if(chk(md)) ub=md;
    else lb=md;
  }
  printf("%.10f\n",ub);
  return 0;
}