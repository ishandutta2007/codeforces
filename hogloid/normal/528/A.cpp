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
int w,h,n;
set<int> split[2];
multiset<int> length[2];
void solve(int i,int d){
  auto it=split[i].lower_bound(d),it2=it;
  --it2;
  int len=(*it)-(*it2);
  length[i].erase(length[i].lower_bound(len));
  int L1=(*it)-d,L2=d-(*it2);
  length[i].insert(L1);length[i].insert(L2);
  split[i].insert(d);
}

int main(){
  cin>>w>>h>>n;
  split[0].insert(0);
  split[1].insert(0);
  split[0].insert(h);
  split[1].insert(w);
  length[0].insert(h);
  length[1].insert(w);

  REP(i,n){
    char tmp[3];int d;
    scanf("%s%d",tmp,&d);
    if(tmp[0]=='H'){
      solve(0,d);
    }else solve(1,d);

    int L1=*(--length[0].end()),L2=*(--length[1].end());
    printL(L1*(lint)L2);
    putchar('\n');
  }
  return 0;
}