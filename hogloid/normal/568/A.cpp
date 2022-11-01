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

const int M=1200000;
int table[M+5];
lint pi[M+5],rub[M+5];
stringstream ss;
string itos(int n){
  ss.clear();
  ss.str("");
  ss<<n;
  return ss.str();
}
bool ispalin(int n){
  if(n==0) return false;
  string a=itos(n);
  string b=a;reverse(ALL(b));
  return a==b;
}
int main(){
  memset(table,1,sizeof(table));
  table[0]=table[1]=0;
  for(int i=2;i*i<=M;++i) if(table[i]){
    for(int j=i*i;j<=M;j+=i) table[j]=0;
  }
  REP(i,M+1) pi[i+1]=pi[i]+(table[i]?1:0);
 
  CLR(table);
  REP(i,M+1) rub[i+1]=rub[i]+(ispalin(i)?1:0); 

  int p,q;cin>>p>>q;
  for(int i=M;i>=1;--i){
    if(pi[i+1]*q<=p*rub[i+1]){
      printf("%d\n",i);
      return 0;
    }
  }
  return 0;
}