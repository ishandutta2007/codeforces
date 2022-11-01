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

const int INF=5e8;
set<int> cand;

string itos(int a){
  string res="";
  REP(i,4) res+='0'+a%10,a/=10;
  return res;
}
pi retval(int a,int q){
  string A=itos(a),Q=itos(q);
  int hit=0,blow=0;
  REP(i,4) if(A[i]==Q[i]) ++hit;
  int cnt1[10]={0},cnt2[10]={0};
  REP(i,4){
    cnt1[A[i]-'0']++;
    cnt2[Q[i]-'0']++;
  }
  REP(i,10) blow+=min(cnt1[i],cnt2[i]);
  blow-=hit;
  return mp(hit,blow);
}
int askcount=0;
pi exe(int q){
  ++askcount;
  dump(askcount);
  printf("%04d\n",q);fflush(stdout);
  int a,b;scanf("%d%d",&a,&b);
  return mp(a,b);
}
bool distd(int a){
  string s=itos(a);
  sort(ALL(s));
  REP(i,3) if(s[i]==s[i+1]) return false;
  return true;
}

int getbest(){
  int cost=INF,ask=-1;
  REP(i,10000) if(distd(i)){
    map<pi,int> cnt;
    for(auto e:cand){
      cnt[retval(e,i)]++;
    }
    int mx=-1;
    for(auto e:cnt) chmax(mx,e.sc);
    if(cost>mx){
      cost=mx;
      ask=i;
      dump(mx);
    }
  }
  return ask;
}
int main(){
  REP(i,10000) if(distd(i)) cand.insert(i);
  vector<int> init={123,4567};
  while(1){
    if(cand.size()==1){
      exe(*cand.begin());
      return 0;
    }
    dump(cand.size());
    if(cand.size()<=100) debug(ALL(cand));
    int ask;
    if(init.empty()) ask=getbest();
    else{
      ask=init.back();
      init.pop_back();
    }
    dump(ask);
    pi ret=exe(ask);
    if(ret==mp(4,0)) return 0;
    set<int> nxt;
    for(auto e:cand){
      if(retval(e,ask)!=ret) ;
      else nxt.insert(e);
    }
    cand=nxt;
  }
  return 0;
}