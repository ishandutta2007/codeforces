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
#define dumpR(x) cerr<<"\x1b[31m"<<#x<<" = " <<(x)<<"\x1b[39m"<<endl
#define dumpY(x) cerr<<"\x1b[33m"<<#x<<" = " <<(x)<<"\x1b[39m"<<endl
#define dumpG(x) cerr<<"\x1b[32m"<<#x<<" = " <<(x)<<"\x1b[39m"<<endl
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
#else
#define dump(x) ;
#define dumpR(x) ;
#define dumpY(x) ;
#define dumpG(x) ;
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
lint ar[100005];

lint zip[100005];
int cnt[100005];
int zn;

int del[100005];
bool check(int K){
  CLR(cnt);
  CLR(del);
  REP(i,n){
    ++cnt[lower_bound(zip,zip+zn,ar[i])-zip];
  }
  REP(i,K){
    lint cur=1;
    while(1){
      int p=lower_bound(zip,zip+zn,cur)-zip;
      if(zip[p]!=cur) break;
      if(cnt[p]==0) break;
      --cnt[p];
      cur*=2;
    }
    ++del[(lower_bound(zip,zip+zn,cur)-zip)-1];
  }
  for(int i=zn-1;i>=0;--i){
    if(cnt[i]>del[i]) return false;
    del[i]-=cnt[i];
    if(i) del[i-1]+=del[i];
  }
  return true;
}
int main(){
  cin>>n;
  REP(i,n) ar[i]=readL(),zip[i]=ar[i];
  sort(zip,zip+n);
  zn=unique(zip,zip+n)-zip;
  int ocnt=0;
  REP(i,n) if(ar[i]==1) ++ocnt;
  if(check(ocnt)==false){
    puts("-1");
    return 0;
  }
  int lb=0,ub=ocnt;
  while(ub-lb>1){
    int md=(lb+ub)>>1;
    if(check(md)) ub=md;
    else lb=md;
  }
  dump(ub);
  for(int i=ub;i<=ocnt;++i) printf("%d\n",i);
  return 0;
}