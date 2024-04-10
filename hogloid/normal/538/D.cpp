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
int n;
char buf[55][55];

char res[105][105];
int main(){
  cin>>n;
  REP(i,n) scanf("%s",buf[i]);
  REP(i,2*n-1) REP(j,2*n-1) res[i][j]='x';
  res[n-1][n-1]='o';

  REP(i,n) REP(j,n) if(buf[i][j]=='o'){
    REP(i2,n) REP(j2,n) if(buf[i2][j2]=='.'){
      res[i2-i+n-1][j2-j+n-1]='.';
    }
  }

  REP(i,n) REP(j,n) if(buf[i][j]=='o'){
    REP(i2,2*n-1) REP(j2,2*n-1) if(res[i2][j2]=='x'){
      int px=i+i2-(n-1),py=j+j2-(n-1);
      if(px>=0 && px<n && py>=0 && py<n){
        if(buf[px][py]=='x') buf[px][py]='.';
      }
    }
  }
  REP(i,n) REP(j,n) if(buf[i][j]=='x'){
    puts("NO");
    return 0;
  }
  puts("YES");
  REP(i,n*2-1) printf("%s\n",res[i]);
  return 0;
}