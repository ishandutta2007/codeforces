#include <bits/stdc++.h>
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
int n;
vector<int> lis[1005];
bitset<1000> adj[1005];
pi es[1000005];
int m;
typedef vector<int> vi;
typedef bitset<1000> bs;

bool leaf[1005],used[1005];

int app_cnt[1005];
int deg_in[1005];
int main(){
  cin>>n;
  REP(i,n){
    int k;cin>>k;
    lis[i].resize(k);
    REP(j,k){
      int a;scanf("%d",&a);--a;
      adj[i].set(a);
      ++app_cnt[a];
      lis[i][j]=a;
    }
    sort(ALL(lis[i]));
  }
  {
    bool fail=false;
    REP(i,n) if(adj[0]!=adj[i]) fail=true;
    if(!fail){
      REP(i,n-1) printf("%d %d\n",1,i+2);
      return 0;
    }
  }
  {
    vector<int> cent;
    REP(i,n) if(app_cnt[i]==n) cent.pb(i);
    if(cent.size()==2){
      bool mark[1005]={0};
      REP(i,n) if(adj[i].count()<n){
        REP(j,n) if(adj[i].test(j)) mark[j]=1;
        break;
      }
      REP(i,n) if(find(ALL(cent),i)==cent.end() && mark[i]){
        printf("%d %d\n",cent[0]+1,i+1);
      }
      REP(i,n) if(find(ALL(cent),i)==cent.end() && !mark[i]){
        printf("%d %d\n",cent[1]+1,i+1);
      }
      printf("%d %d\n",cent[0]+1,cent[1]+1);
      return 0;
    }
  }
  REP(i,n) leaf[i]=true;
  REP(i,n) REP(j,i) if((adj[i]&adj[j]).count()==2){
    vector<int> p;
    REP(k,n) if(adj[i].test(k) && adj[j].test(k)) p.pb(k);
    es[m++]=mp(p[0],p[1]);
    leaf[p[1]]=leaf[p[0]]=false;
  }
  sort(es,es+m);
  m=unique(es,es+m)-es;
  REP(i,m){
    ++deg_in[es[i].fr];
    ++deg_in[es[i].sc];
  }
  int m2=m;
  REP(i,n) if(leaf[i]){
    int mini=-1;
    REP(j,n) if(!used[j] && adj[j].test(i)){
      if(mini==-1 || adj[mini].count()>adj[j].count()) mini=j;
    }
    assert(~mini);
    used[mini]=1;
    vector<int> cands;
    REP(j,n) if(adj[mini].test(j) && !leaf[j]){
      cands.pb(j);
    }
    
    if(cands.size()>2){
      bool suc=false;
      for(auto v:cands){
        bool fail=false;
        int cc=0;
        for(auto u:cands){
          if(u!=v && !binary_search(es,es+m2,mp(u,v)) && !binary_search(es,es+m2,mp(v,u))){
            fail=true;
            break;
          }else{
            ++cc;
            if(cc>=3) break;
          }
        }
        if(!fail){
          es[m++]=mp(i,v);
          suc=true;
          break;
        }
      }
    }else{
      int mdel=-m;
      if(deg_in[cands[0]]==1) es[m++]=mp(i,cands[0]);
      if(deg_in[cands[1]]==1) es[m++]=mp(i,cands[1]);
      mdel+=m;
    }
  }
  assert(m==n-1);
  REP(i,n-1) printf("%d %d\n",es[i].fr+1,es[i].sc+1);


  return 0;
}