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
int m,n;
int ar[100005];

bool mark[200005];

lint mpow(lint a,lint k){
  lint res=1;
  while(k){
    if(k&1) res=res*a%m;
    a=a*a%m;
    k>>=1;
  }
  return res;
}
lint inv(int x){
  return mpow(x,m-2);
}
bool check(lint A,lint D){
  REP(i,n){
    int tmp=(A+D*i)%m;
    if(binary_search(ar,ar+n,tmp)==false) return false;
  }
  return true;
}
pi solve(){
  sort(ar,ar+n);
  int dif=ar[1]-ar[0];
  int cnt=0;
  REP(i,n) if(binary_search(ar,ar+n,(ar[i]+dif)%m)) ++cnt;
  int K=n-cnt;
  lint D=dif*inv(K)%m;

  lint S=0;
  REP(i,n) S+=ar[i];
  S-=n*(lint)(n-1)/2%m*D%m;
  S=(S%m+m)%m;
  S=S*inv(n)%m;

  lint A=S;

  if(check(A,D)) return {A,D};
  return {-1,-1};
}
int main(){
  cin>>m>>n;

  REP(i,n) scanf("%d",&ar[i]);
  if(n==1){
    printf("%d %d\n",ar[0],0);
    return 0;
  }
  if(n==m){
    printf("%d %d\n",0,1);
    return 0;
  }
  if(n==m-1){
    REP(i,n) mark[ar[i]]=1;
    int p=-2;
    REP(i,m) if(!mark[i]) p=i;
    printf("%d %d\n",(p+1)%m,1);
    return 0;
  }

  pi res;
  if(m>2*n){
    res=solve();
  }else{
    REP(i,m) mark[i]=1;
    REP(i,n) mark[ar[i]]=0;

    int n2=n;
    n=m-n;
    int cnt=0;
    REP(i,m) if(mark[i]) ar[cnt++]=i;

    pi tmp=solve();
    if(tmp.fr==-1) res={-1,-1};
    else{
      res={(tmp.fr+n*(lint)tmp.sc)%m,tmp.sc};
    }
  }
  if(res.fr==-1) puts("-1");
  else printf("%d %d\n",res.fr,res.sc);
  return 0;
}