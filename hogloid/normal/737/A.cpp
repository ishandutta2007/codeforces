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

int n,k,s,t;
pi car[200005];
int gas[200005];

int len[200005],m;

lint sum[200005];
int main(){
  cin>>n>>k>>s>>t;

  REP(i,n) scanf("%d%d",&car[i].fr,&car[i].sc);
  sort(car,car+n);

  REP(i,k) scanf("%d",&gas[i]);
  gas[k++]=0;
  gas[k++]=s;
  sort(gas,gas+k);

  m=k-1;
  REP(i,m) len[i]=gas[i+1]-gas[i];
  sort(len,len+m);

  REP(i,m) sum[i+1]+=sum[i]+len[i];

  REP(i,n){
    int a=car[i].sc;
    dump(car[i]);
    if(a<len[m-1]) continue;


    if(a%2==0){
      int lim=a/2;
      int p=upper_bound(len,len+m,lim)-len;
      lint time=sum[p];
      time+=(sum[m]-sum[p])*3-(lim*(m-p)*2);

      prl;
      dump(time);
      if(time<=t){
        printf("%d\n",car[i].fr);
        return 0;
      }
    }else{
      int lim=a/2;
      int p=upper_bound(len,len+m,lim)-len;
      int p2=upper_bound(len,len+m,lim+1)-len;
      lint time=sum[p2]+(p2-p);
      dump(time);
      time+=(sum[m]-sum[p2])*3-((lim*2+1)*(m-p2));
      dump(sum[m]-sum[p2]);

      dump(m-p2);
      dump(lim);

      dump(time);
      if(time<=t){
        printf("%d\n",car[i].fr);
        return 0;
      }
    }
  }
  puts("-1");
  return 0;
}