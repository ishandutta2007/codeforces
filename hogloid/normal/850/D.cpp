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

const int INF=5e8;

int m,n;
int ar[35];

const int M=62;
const int M2=M*(M-1)/2;


int dp[35][M+5][M2+5];


int main(){
#ifdef LOCAL_REDIR
  freopen("/home/hog/Dropbox/pg/working/in.txt","r",stdin);
#endif
  cin>>m;
  REP(i,m) cin>>ar[i];
  sort(ar,ar+m);
  int Ma=*max_element(ar,ar+m);
  memset(dp,-1,sizeof(dp));
  dp[0][0][0]=0;
  REP(i,m){
    for(int j=i;j<=M;++j){
      for(int k=0;k<=M2;++k) if(dp[i][j][k]!=-1){
          if(k<j*(j-1)/2) continue;
          for(int l=1;j+l<=M && k+l*ar[i]<=M2;++l){
            dp[i+1][j+l][k+l*ar[i]]=l;
          }
      }
    }
  }

  for(n=Ma+1;dp[m][n][n*(n-1)/2]==-1 && n<=M;++n);

  if(n>M){
    puts("=(");
    return 0;
  }

  vector<int> odeg,indeg(n);
  int ci=m,cj=n,ck=n*(n-1)/2;
  while(ci>0){
    int cnt=dp[ci][cj][ck];
    REP(_,cnt) odeg.pb(ar[ci-1]);
    --ci;
    cj-=cnt;
    ck-=cnt*ar[ci];
  }
  sort(ALL(odeg));
  REP(i,n) indeg[i]=n-1-odeg[i];


  char ans[100][100];
  CLR(ans);
  REP(i,n) REP(j,n) ans[i][j]='0';


  vector<int> vs;
  for(int j=0;j<n;++j) vs.pb(j);
  REP(i,n){
    sort(ALL(vs),[&](int a,int b){
      return odeg[a]<odeg[b];
    });
    int u=vs[0];
    for(int j=1;j<vs.size();++j){
      int v=vs[j];
      if(odeg[u]>0){
        ans[u][v]='1';
        ans[v][u]='0';
        --odeg[u];
      }else{
        ans[u][v]='0';
        ans[v][u]='1';
        --odeg[v];
      }
    }
    vs.erase(vs.begin());
  }

  printf("%d\n",n);
  REP(i,n) printf("%s\n",ans[i]);
  return 0;
}