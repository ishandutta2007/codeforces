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
int n,q;
int cnt[300005];
int till[300005];

pi ar[300005];
int main(){
  int pend=0;
  int m=0;


  int adv=0;
  cin>>n>>q;
  REP(i,q){
    char s[5];int x;
    scanf("%s%d",s,&x);--x;
    if(s[0]=='1'){
      ar[m++]=mp(x,cnt[x]);
      ++cnt[x];
      ++pend;
    }else if(s[0]=='2'){
      pend-=cnt[x]-till[x];
      till[x]=cnt[x];
    }else{
      ++x;
      while(adv<x){
        int p=ar[adv].sc;
        int kind=ar[adv].fr;
        if(p>=till[kind]){
          ++till[kind];
          --pend;
        }
        ++adv;
      }
    }
    printf("%d\n",pend);
  }
  return 0;
}