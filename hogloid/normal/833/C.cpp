#define DEB
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


#ifdef DEB
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

//const int INF=5e8;
lint L,R;

string Ls,Rs;

bool ok(const vector<int>& P){
  int cnt[15]={0};
  int cur=1;
  int dig=0;
  for(auto e:P){
    if(e==0) ++cnt[cur],++dig;
    else ++cur;
  }
  if(dig>Rs.size()) return false;

  auto doLower=[&](int from){
    bool fail=false;
    for (int i = from; i < Ls.size(); ++i) {
      int v=Ls[i]-'0';
      for(int d=v+1;d<10;++d){
        if(cnt[d]>0) return true;
      }
      --cnt[v];
      if(cnt[v]<0){
        fail=true;
        break;
      }
    }
    if(!fail) return true;
    return false;
  };
  auto doUpper=[&](int from) {
    bool fail=false;
    for (int i = from ; i < Rs.size(); ++i) {
      int v=Rs[i]-'0';
      for(int d=0;d<v;++d){
        if(cnt[d]>0) return true;
      }
      --cnt[v];
      if(cnt[v]<0){
        fail=true;
        break;
      }
    }
    if(!fail) return true;
    return false;
  };
  if(Ls.size()==Rs.size()){
    int from=-1;
    int lack=Rs.size()-dig;
    cnt[0]=lack;
    for(int i=0;i<Ls.size();++i){
      if(Ls[i]!=Rs[i]){
        from=i;
        break;
      }else{
        int v=Ls[i]-'0';
        --cnt[v];
        if(cnt[v]<0) return false;

      }
    }
    if(from==-1) return true;
    if(Rs[from]-Ls[from]>1){
      for(int d=Ls[from]-'0'+1;d<Rs[from]-'0';++d){
        if(cnt[d]>0) return true;
      }
    }
    if(cnt[Ls[from]-'0']) {
      int prev[15];
      memcpy(prev,cnt,sizeof(cnt));
      --cnt[Ls[from]-'0'];
      if (doLower(from+1)) return true;
      memcpy(cnt,prev,sizeof(cnt));
    }
    if(cnt[Rs[from]-'0']){
      --cnt[Rs[from]-'0'];
      if(doUpper(from+1)) return true;
    }
  }else{
    if(Rs.size()-Ls.size()>1) {
      int mid = Rs.size() - 1;
      if (dig <= mid) return true;
    }
    int prev[15];
    memcpy(prev,cnt,sizeof(cnt));
    if(dig<=Ls.size()){
      cnt[0]=Ls.size()-dig;
      if(doLower(0)) return true;
    }
    memcpy(cnt,prev,sizeof(cnt));
    cnt[0]=Rs.size()-dig;
    if(doUpper(0)) return true;
  }
  return false;
}
int main(){
#ifdef LOCAL_REDIR
  freopen("/home/hog/Dropbox/pg/working/in.txt","r",stdin);
#endif
  cin>>Ls>>Rs;
  L=atoll(Ls.c_str());
  R=atoll(Rs.c_str());


  int res=0;
  for(int dig=1;dig<=min(18,(int)Rs.size());++dig){
    vector<int> perm;
    REP(i,dig) perm.pb(0);
    REP(i,8) perm.pb(1);
    do{
      bool tmp=ok(perm);
      if(tmp){
        ++res;
      }
    }while(next_permutation(ALL(perm)));
  }
  cout<<res<<endl;

  return 0;
}