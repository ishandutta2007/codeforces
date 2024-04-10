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

const lint INF=2e18;

int n;

const int B=300;
const int L=100000/B+5;

int ar[100005];
typedef pair<lint,lint> pl;
struct sqdecom{
  struct point{
    lint a,b;
    int id;
  };
  lint suf[L];

  vector<point> line[L];
  vector<int> order[L];
  bool valid[100005];

  int invsum2[L];

  void getorder(int b){
    REPN(i,min(n,(b+1)*B),b*B) order[b].pb(i);
    sort(ALL(order[b]),[&](int a,int b){
      return ar[a]<ar[b];
    });
    dump(b);
    debug(ALL(order[b]));
  }

  void push(vector<point>& line,lint a,lint b,int id){
    dump(a);dump(b);dump(id);
    while(!line.empty()){
      point l1=line.back();
      if(l1.a==a && l1.b>=b) return;
      else if(l1.b<b){
        line.pop_back();
        continue;
      }
      if(line.size()==1) break;
      point l2=line[line.size()-2];
      if((l1.b-b)*(l1.a-l2.a)<(l2.b-l1.b)*(a-l1.a)){
        line.pop_back();
        continue;
      }else{
        break;
      }
    }
    line.pb((point){a,b,id});
  }
  int seek[L];
  void construct(int b){
    seek[b]=0;
    lint latsum[B+5]={0};
    int invsum[B+5]={0};
    for(int i=min(n,(b+1)*B)-b*B-1;i>=0;--i){
      latsum[i]=latsum[i+1]+(!valid[i+b*B]?ar[i+b*B]:0);
    }
    REPN(i,min(n,(b+1)*B),b*B){
      invsum[i+1-b*B]=invsum[i-b*B]+(!valid[i]);
    }
    debug(valid,valid+n);
    line[b].clear();
    for(auto i:order[b]){
      if(valid[i]){
        push(line[b],ar[i],latsum[i-b*B]+invsum[i-b*B]*(lint)ar[i],i);
      }
    }
    for(auto p:line[b]){
      dump(p.a);dump(p.b);dump(p.id);
    }
  }
  int mx;
  void init(){
    mx=(n-1)/B+1;
    REP(i,n) valid[i]=1;
    REP(i,n) if(i%B==0){
      getorder(i/B);
      construct(i/B);
    }
  }
  lint eval(point p,lint bef){
    return p.a*(bef+1)+p.b;
  }
  lint findmax(){
    pair<lint,int> res=mp(-INF,-1);
    for(int i=0;i<n;i+=B) {
      int b=i/B;
      if(line[b].empty()){
        continue;
      }
      while(seek[b]+1<line[b].size() && eval(line[b][seek[b]],invsum2[b])<eval(line[b][seek[b]+1],invsum2[b])){
        ++seek[b];
      }
      chmax(res,mp(eval(line[b][seek[b]],invsum2[b])+suf[b],b));
    }
    int id=line[res.sc][seek[res.sc]].id;
    valid[id]=false;
    dumpR(id);
    dumpG(ar[id]);
    dumpR(res.sc);
    REP(i,res.sc) suf[i]+=ar[id];
    REPN(i,mx,res.sc+1) invsum2[i]++;
    debug(invsum2,invsum2+mx);
    construct(res.sc);
    return res.fr;
  }
};


sqdecom data;
int main(){
  cin>>n;
  REP(i,n) cin>>ar[i];
  data.init();

  lint res=0;
  lint sum=0;
  REP(i,n){
    sum+=data.findmax();
    dumpY(sum);
    chmax(res,sum);
  }
  cout<<res<<endl;
  return 0;
}