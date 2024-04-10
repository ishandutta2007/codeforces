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

lint conv[300];
lint getv(){
  string s;cin>>s;
  reverse(ALL(s));
  lint res=0;
  REP(i,s.size()) res+=conv[s[i]]<<(4*i);
  return res;
}


lint dp[20][2][2];//dp[digit][equal?][maximum digit used?]

typedef vector<int> vi;
char conv2[]="0123456789abcdef";
vi itos(lint n){
  vi res;
  while(n){
    res.pb(n%16);
    n/=16;
  }
  reverse(ALL(res));
  return res;
}

lint solve(lint U){//...U]
  if(U<0) return 0;
  vi ar=itos(U);
  lint res=0;
  REPN(i,16,1){//i: maximal hexadecimal digit
    CLR(dp);
    int d=ar.size();
    dp[0][1][0]=1;

    int idx=d-1-i/4,dig=i%4;
    if(idx<0) continue;
    REP(j,d) REP(t,2) REP(t2,2) if(dp[j][t][t2]){
      REP(k,i+1){
        if(t && ar[j]<k) continue;
        if(j==idx && !(k>>dig&1)) continue;

        dp[j+1][t&(ar[j]==k?1:0)][t2|(k==i?1:0)]+=dp[j][t][t2];
      }
    }
    res+=dp[d][0][1]+dp[d][1][1];
  }
  return res;
}
int main(){
  REP(i,10) conv[i+'0']=i;
  REP(i,6) conv['a'+i]=10+i;

  int q;cin>>q;
  while(q--){
    lint L=getv();
    lint R=getv();
    lint res=solve(R)-solve(L-1);
    cout<<res<<endl;
  }

  return 0;
}