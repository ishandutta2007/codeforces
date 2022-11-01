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
int h,w;
char buf[2005][2005];


void exi(){
  puts("Not unique");
  exit(0);
}

int dx[]={1,0,-1,0},dy[]={0,-1,0,1};
char sign[]=">^<v";
void rec(int y,int x){
  int deg=0;
  REP(d,4){
    int px=x+dx[d],py=y+dy[d];
    if(px<0 || py<0 || px>=w || py>=h || buf[py][px]!='.') continue;
    ++deg;
  }
  if(deg==0) exi();
  if(deg==1){
    REP(d,4){
      int px=x+dx[d],py=y+dy[d];
      if(px<0 || py<0 || px>=w || py>=h || buf[py][px]!='.') continue;
      buf[y][x]=sign[d^2];
      buf[py][px]=sign[d];

      REP(d2,4){
        int px2=px+dx[d2],py2=py+dy[d2];
        if(px2<0 || py2<0 || px2>=w || py2>=h || buf[py2][px2]!='.') continue;
        rec(py2,px2);
      }
    }
  }
}

int c1,c2;
void dfs(int y,int x){
  buf[y][x]='x';
  if((x+y)&1) ++c1;
  else ++c2;

  REP(d,4){
    int px=x+dx[d],py=y+dy[d];
    if(px<0 || py<0 || px>=w || py>=h || buf[py][px]!='.') continue;
    dfs(py,px);
  }
}
int main(){
  cin>>h>>w;
  REP(i,h) scanf("%s",buf[i]);

  REP(i,h) REP(j,w) if(buf[i][j]=='.'){
    rec(i,j);
  }

  bool emp=false;


  REP(i,h) REP(j,w) if(buf[i][j]=='.'){
    emp=true;
    dfs(i,j);
    if(c1!=c2) exi();
  }
  if(!emp){
    REP(i,h) printf("%s\n",buf[i]);
  }else exi();

  return 0;
}