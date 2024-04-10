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
typedef pair<lint,lint> pi;

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

int n,m;
pi ar[200005];


int getR(int s,lint l){
  int lb=s,ub=n;
  while(ub-lb>1){
    int md=(lb+ub)>>1;
    if(ar[md].fr-ar[s].fr>l) ub=md;
    else lb=md;
  }
  return lb;
}

int getL(int s,lint l){
  int lb=-1,ub=s;
  while(ub-lb>1){
    int md=(lb+ub)>>1;
    if(ar[s].fr-ar[md].fr>l) lb=md;
    else ub=md;
  }
  return ub;
}

int conv[200005];
int main(){
  cin>>n>>m;
  REP(i,n){
    int a;scanf("%d",&a);
    ar[i].fr=a;
    ar[i].sc=i;
  }
  sort(ar,ar+n);

  REP(i,n) conv[ar[i].sc]=i;

  REP(hoge,m){
    int s,l_;
    scanf("%d%d",&s,&l_);--s;
    s=conv[s];

    lint l=l_;

    int t1=getR(s,l);
    l-=ar[t1].fr-ar[s].fr;
    int t2=getL(t1,l);
    l-=ar[t1].fr-ar[t2].fr;
    s=t2;




    while(1){
      int pivR=getR(s,l);
      lint l2=l-(ar[pivR].fr-ar[s].fr);
      int pivL=getL(pivR,l2);

      if(pivR==s) break;
      if(pivL==pivR){
        s=pivR;
        break;
      }

      if(pivL==s){
        lint length=(ar[pivR].fr-ar[s].fr)*2;
        l%=length;
      }else{
        s=pivL;
        l=l2-(ar[pivR].fr-ar[pivL].fr);
      }
    }

    printf("%d\n",(int)(ar[s].sc+1));
  }


  return 0;
}