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
int n,k;
struct line{
  lint a,b,c;
};
line L[100005];

bool mark[100005];
vector<pi> res;

bool cross(const line &x,const line &y,const line &z){
  if(z.a*(-x.c*y.b+y.c*x.b)+z.b*(-x.a*y.c+x.c*y.a)==-z.c*(x.a*y.b-x.b*y.a)) return true;
  return false;
}
bool rec(int k){
  int n2=0;
  REP(i,n) if(!mark[i]) ++n2;
  if(n2<=k){
    REP(i,n) if(!mark[i]) res.pb(mp(i,-2));
    return true;
  }
  if(k==0) return false;

  vector<pair<line,int> > cand;
  for(int i=0;i<n && cand.size()<k+1;++i) if(!mark[i]){
    cand.pb(mp(L[i],i));
  }
  REP(i,cand.size()) REP(j,i){
    line A=cand[i].fr,B=cand[j].fr;
    if(A.a*B.b-A.b*B.a==0) continue;

    bool fail=false;
    REP(k,i) if(j!=k && cross(A,B,cand[k].fr)) fail=1;
    if(fail) continue;

    vector<bool> ever(n);
    REP(k,n) ever[k]=mark[k];
    REP(k,n) if(!mark[k] && cross(A,B,L[k])) mark[k]=1;
    res.pb(mp(cand[i].sc,cand[j].sc));
    if(rec(k-1)) return true;
    res.pop_back();
    
    REP(k,n) mark[k]=ever[k];
  }
  return false;
}

int main(){
  cin>>n>>k;
  REP(i,n){
    int a,b,c;scanf("%d%d%d",&a,&b,&c);
    L[i]=(line){a,b,c};
  }
  int n2=n;
  if(n2>=10000){
    bool suc=false;
    REP(hoge,100){
      int a=rand()%n,b=rand()%n;
      line A=L[a],B=L[b];
      if(A.a*B.b-A.b*B.a==0) continue;

      int cnt=0;
      REP(i,n) if(cross(A,B,L[i])) ++cnt;
      if(cnt>=k+1){
        suc=true;
        res.pb(mp(a,b));
        REP(i,n) if(cross(A,B,L[i])){
          mark[i]=1;
          --n2;
        }
        --k;
        goto exi;
      }
    }
    if(!suc){
      puts("NO");
      return 0;
    }
  }
  exi:;

  if(!rec(k)){
    puts("NO");
  }else{
    puts("YES");
    cout<<res.size()<<endl;
    for(auto e:res){
      printf("%d %d\n",e.fr+1,e.sc+1);
    }
  }

  return 0;
}