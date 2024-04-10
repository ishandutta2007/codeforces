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
int hp1,atk1,def1;
int hp2,atk2,def2;

int h,a,d;

int cei(int a,int b){
  if(b==0) return INF;
  return (a+b-1)/b;
}

int main(){
  cin>>hp1>>atk1>>def1;
  cin>>hp2>>atk2>>def2;

  cin>>h>>a>>d;

  int res=INF;
  REP(i,205) REP(j,105){
    int cost=i*a+d*j;

    int killturn=cei(hp2,max(0,atk1+i-def2));
    if(killturn==INF) continue;

    int dam=max(0,atk2-def1-j);
    if(dam==0) ;
    else{
      int needHP=killturn*dam+1;
      cost+=max(0,needHP-hp1)*h;
    }
    chmin(res,cost);
  }
  cout<<res<<endl;

  return 0;
}