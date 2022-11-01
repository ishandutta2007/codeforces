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

int n,l,x,y;

int ar[100005];

void test(int p){
  if(p<0 || p>l) return;

  if((binary_search(ar,ar+n,p+x) || binary_search(ar,ar+n,p-x)) &&
      (binary_search(ar,ar+n,p+y) || binary_search(ar,ar+n,p-y))){
    printf("1\n");
    printf("%d\n",p);
    exit(0);
  }
}

int main(){
  cin>>n>>l>>x>>y;
  REP(i,n) scanf("%d",&ar[i]);
  bool xok=false,yok=false;
  REP(i,n){
    if(binary_search(ar,ar+n,ar[i]+x)) xok=true;
    if(binary_search(ar,ar+n,ar[i]+y)) yok=true;
  }
  if(xok && yok) return puts("0"),0;

  if(xok || yok){
    if(yok){
      swap(x,y);
    }
    printf("1\n");
    printf("%d\n",y);
    return 0;
  }


  REP(i,n){
    test(ar[i]-x);
    test(ar[i]-y);
    test(ar[i]+x);
    test(ar[i]+y);
  }

  printf("2\n");
  printf("%d %d\n",x,y);

  return 0;
}