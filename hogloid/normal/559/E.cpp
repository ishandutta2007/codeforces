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

const int INF=5e8;

int n;
pi light[105];
int zip[305],zn;

int dp[2][305][305][305];
int L[105],R[105],P[105];
int getp(int a){
  return lower_bound(zip,zip+zn,a)-zip;
}
int getlen(int a,int b,int x,int y){
  if(a>=b) return 0;
  if(x>=y) return b-a;
  if(a<=x && y<=b) return b-a-(y-x);
  if(a<=x) return min(b,x)-a;
  if(y<=b) return b-max(y,a);
  return b-a;
}

int mask[305];

int flag[305];
/*
int test(int i,int j,int l,int r){
  int res=-1;
  REP(bit,1<<i){
    CLR(flag);
    REP(i2,i){
      if(bit>>i2&1) REPN(j2,R[i2],P[i2]) flag[j2]=1;
      else REPN(j2,P[i2],L[i2]) flag[j2]=1;
    }
    int tot=0;
    REP(i2,zn-1) if(flag[i2]) tot+=zip[i2+1]-zip[i2];
    bool fail=false;
    REPN(i2,r,l) if(!flag[i2]) fail=1;
    if(j>0 && !flag[j-1]) fail=1;
    if(1) chmax(res,tot);
  }
  return res;
}*/

int main(){
  cin>>n;
  REP(i,n){
    cin>>light[i].fr>>light[i].sc;
    zip[zn++]=light[i].fr;
    zip[zn++]=light[i].fr+light[i].sc;
    zip[zn++]=light[i].fr-light[i].sc;
  }
  zip[zn++]=-INF;
  sort(zip,zip+zn);
  zn=unique(zip,zip+zn)-zip;

  sort(light,light+n);

  REP(i,n){
    P[i]=getp(light[i].fr);
    mask[P[i]]|=1;
    R[i]=getp(light[i].fr+light[i].sc);
    mask[R[i]]|=2;
    L[i]=getp(light[i].fr-light[i].sc);
    mask[L[i]]|=4;
  }
  debug(light,light+n);

  int cur=0,nxt=1;
  REP(t,2) REP(j,zn) REP(l,zn+1) REP(r,zn+1) dp[t][j][l][r]=-INF;
  dp[cur][0][P[0]][P[0]]=0;
  mask[0]=7;
  P[n]=zn;
  REP(i,n){
    REP(j,zn) if(mask[j]&3) REP(l,zn) if(mask[l]&1) REP(r,zn) if(dp[cur][j][l][r]>=0){
      int val=dp[cur][j][l][r];

      int np=P[i+1];
      if(np<=r) chmax(dp[nxt][j][l][r],val);
      else if(l<r) chmax(dp[nxt][r][np][np],val);
      else chmax(dp[nxt][j][np][np],val);

      if(np<r) chmax(dp[nxt][np][np][r],val+max(0,zip[l]-max(zip[L[i]],zip[j])));
      else chmax(dp[nxt][r][np][np],val+max(0,zip[l]-max(zip[L[i]],zip[j])));

      if(r<R[i]){
        if(np<=R[i]) chmax(dp[nxt][j][l][R[i]],val+zip[R[i]]-zip[r]);
        else chmax(dp[nxt][R[i]][np][np],val+zip[R[i]]-zip[r]);
      }
    }
    swap(cur,nxt);
    REP(j,zn) REP(l,zn) REP(r,zn) dp[nxt][j][l][r]=-INF;
  }

  int res=-INF;
  REP(j,zn) chmax(res,dp[cur][j][zn][zn]);
  cout<<res<<endl;
  return 0;
}