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

typedef vector<lint> vec;
typedef vector<vec> mat;
const lint mod=1000000007;
mat mult(const mat&a, const mat& b){
  int n=a.size();
  mat res(n,vec(n));

  REP(i,n) REP(j,n) REP(k,n) res[i][k]+=a[i][j]*b[j][k],res[i][k]=(res[i][k]%mod+mod)%mod;
  return res;
}

mat matpow(mat a,lint k){
  int n=a.size();
  mat res(n,vec(n));
  REP(i,n) res[i][i]=1;
  while(k>0){
    if(k&1) res=mult(res,a);
    a=mult(a,a);
    k>>=1;
  }
  return res;
}

int main(){
  int x,y,n;scanf("%d%d%d",&x,&y,&n);

  mat M(2,vec(2));

  M[0][0]=1;M[0][1]=-1;
  M[1][0]=1;

  mat M_k=matpow(M,n-1);

  lint res=M_k[1][0]*y+M_k[1][1]*x;

  res=(res%mod+mod)%mod;
  printL(res);

  return 0;
}