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
int n,m;
vector<int> g[200005];
stack<pi> cur;
int low[200005],order[200005],cnt;

vector<set<int> >bicon;
int dfs(int v,int p){
	order[v]=cnt++;
	low[v]=order[v];
  for(auto e:g[v]){
    int to=e;
    if(order[to]<order[v]) cur.push(mp(v,to));
    if(order[to]==-1){
      low[v]=min(dfs(to,v),low[v]);
      if(low[to]>=order[v]){
        set<int> tmp;
        while(1){
          pi t=cur.top();cur.pop();
          tmp.insert(t.fr);tmp.insert(t.sc);
          if(t.fr==v && t.sc==to) break;
        }
        bicon.pb(tmp);
      }
    }else low[v]=min(low[v],order[to]);
  }
  return low[v];
}

bool mark[200005],incycle[200005];

bool vis[200005];

vector<int> ever,cycle,branch;
bool dfs1(int v,int p){
  dump(v);
  vis[v]=1;
  ever.pb(v);
  for(auto to:g[v]){
    if(!mark[to]) continue;

    if(to==p) continue;
    if(vis[to]){
      while(ever.back()!=to){
        cycle.pb(ever.back());
        ever.pop_back();
      }
      cycle.pb(to);
      return true;
    }
    if(dfs1(to,v)) return true;
  }
  ever.pop_back();
  return false;
}

bool dfs2(int v,int p){
  vis[v]=1;
  ever.pb(v);
  dump(v);
  for(auto to:g[v]){
    if(!mark[to]) continue;
    if(to==p) continue;
    if(incycle[to]){
      if(ever[0]==to) continue;
      ever.pb(to);
      branch=ever;
      return true;
    }
    if(!vis[to] && dfs2(to,v)) return true;
  }
  ever.pop_back();
  return false;
}

void print(vector<int> R){
  cout<<R.size()<<endl;
  REP(i,R.size()) printf("%d\n",R[i]+1);
}
vector<int> part(int s,int t){
  vector<int> res;
  if(s<t){
    for(int i=s;i<=t;++i) res.pb(cycle[i]);
  }else{
    for(int i=s;i<=t+cycle.size();++i) res.pb(cycle[i%cycle.size()]);
  }
  return res;
}

bool solve(const set<int>& S){
  if(S.size()<=3) return false;
  for(auto v:S){
    mark[v]=1;
    incycle[v]=vis[v]=0;
  }

  int v1=*S.begin();
  ever.clear();
  cycle.clear();
  branch.clear();
  assert(dfs1(v1,-1));

  debug(ALL(cycle));

  for(auto v:S){
    vis[v]=0;
  }
  for(auto v:cycle) incycle[v]=1;

  int m=cycle.size();

  bool exi=false;
  REP(i,m){
    for(auto to:g[cycle[i]]) if(mark[to] && to!=cycle[(i+1)%m] && to!=cycle[(i+m-1)%m]){

      ever.clear();
      ever.pb(cycle[i]);
      if(incycle[to]){
        ever.pb(to);
        branch=ever;
      }else{
        assert(dfs2(to,cycle[i]));
        debug(ALL(branch));
      }
      exi=true;
      goto exi;
    }
  }
exi:;
  for(auto v:S) mark[v]=0;
  if(!exi) return false;

  int s,t,sind,tind;
  REP(i,m){
    if(cycle[i]==branch[0]) s=cycle[i],sind=i;
    if(cycle[i]==branch.back()) t=cycle[i],tind=i;
  }
  assert(sind!=tind);

  puts("YES");
  vector<int> R1,R2,R3;
  R1=branch;
  R2=part(sind,tind);
  R3=part(tind,sind);
  reverse(ALL(R3));

  print(R1);print(R2);print(R3);
  return true;
}
int main(){
  cin>>n>>m;
  REP(i,m){
    int a,b;scanf("%d%d",&a,&b);--a;--b;
    g[a].pb(b);
    g[b].pb(a);
  }
  memset(low,-1,sizeof(low));
  memset(order,-1,sizeof(order));
  REP(i,n) if(low[i]==-1){
    dfs(i,-1);
  }
  dump(bicon.size());
  for(auto S:bicon){
    debug(ALL(S));
    if(solve(S)) return 0;
  }
  puts("NO");
  return 0;
}