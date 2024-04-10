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

char s[15],s2[15];

int C[15][15];
int main(){
  REP(i,15){
    C[i][0]=1;
    REP(j,i) C[i][j+1]=C[i-1][j+1]+C[i-1][j];
  }

  cin>>s>>s2;

  int n=strlen(s);

  int pos=0;
  REP(i,n) pos+=(s[i]=='+'?1:-1);

  int pos2=0,que=0;
  REP(i,n){
    if(s2[i]=='?') ++que;
    else pos2+=(s2[i]=='+'?1:-1);
  }

  int dif=(pos-pos2)+que;

  if((dif&1) || dif<0 || dif>2*que) puts("0");
  else{
    dif>>=1;
    printf("%.10f\n",C[que][dif]/(double)(1<<que));
  }



  return 0;
}