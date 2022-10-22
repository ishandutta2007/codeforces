#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// #include<ext/pb_ds/tag_and_trait.hpp>
// using namespace __gnu_pbds;
// #include<boost/multiprecision/cpp_int.hpp>
// namespace multiprecisioninteger = boost::multiprecision;
// using cint=multiprecisioninteger::cpp_int;
using namespace std;
using ll=long long;
using datas=pair<ll,ll>;
using ddatas=pair<long double,long double>;
using tdata=pair<ll,datas>;
using vec=vector<ll>;
using mat=vector<vec>;
using pvec=vector<datas>;
using pmat=vector<pvec>;
// using llset=tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>;
#define For(i,a,b) for(i=a;i<(ll)b;++i)
#define bFor(i,b,a) for(i=b,--i;i>=(ll)a;--i)
#define rep(i,N) For(i,0,N)
#define rep1(i,N) For(i,1,N)
#define brep(i,N) bFor(i,N,0)
#define brep1(i,N) bFor(i,N,1)
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define vsort(v) sort(all(v))
#define vrsort(v) sort(allr(v))
#define uniq(v) vsort(v);(v).erase(unique(all(v)),(v).end())
#define endl "\n"
#define popcount __builtin_popcountll
#define eb emplace_back
#define print(x) cout<<x<<endl
#define printyes print("Yes")
#define printno print("No")
#define printYES print("YES")
#define printNO print("NO")
#define output(v) do{bool f=0;for(auto outi:v){cout<<(f?" ":"")<<outi;f=1;}cout<<endl;}while(0)
#define matoutput(v) do{for(auto outimat:v)output(outimat);}while(0)
constexpr ll mod=1000000007;
// constexpr ll mod=998244353;
constexpr ll inf=1LL<<60;
constexpr long double eps=1e-9;
const long double PI=acosl(-1);
template<class T,class E> ostream& operator<<(ostream& os,const pair<T,E>& p){return os<<"("<<p.first<<","<<p.second<<")";}
template<class T> ostream& operator<<(ostream& os,const vector<T>& v){
  os<<"{";bool f=false;
  for(auto& x:v){if(f)os<<",";os<<x;f=true;}
  os<<"}";
  return os;
}
template<class T> ostream& operator<<(ostream& os,const set<T>& v){
  os<<"{";bool f=false;
  for(auto& x:v){if(f)os<<",";os<<x;f=true;}
  os<<"}";
  return os;
}
template<class T> ostream& operator<<(ostream& os,const multiset<T>& v){
  os<<"{";bool f=false;
  for(auto& x:v){if(f)os<<",";os<<x;f=true;}
  os<<"}";
  return os;
}
template<class T,class E> ostream& operator<<(ostream& os,const map<T,E>& v){
  os<<"{";bool f=false;
  for(auto& x:v){if(f)os<<",";os<<x;f=true;}
  os<<"}";
  return os;
}
template<class T> inline bool chmax(T& a,const T b){bool x=a<b;if(x)a=b;return x;}
template<class T> inline bool chmin(T& a,const T b){bool x=a>b;if(x)a=b;return x;}
#ifdef DEBUG
void debugg(){cout<<endl;}
template<class T,class... Args>void debugg(const T& x,const Args&... args){cout<<" "<<x;debugg(args...);}
#define debug(...) cout<<__LINE__<<" ["<<#__VA_ARGS__<<"]:",debugg(__VA_ARGS__)
#else
#define debug(...) (void(0))
#endif

inline void startupcpp(void) noexcept{
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(15);
}

template<class Cap> struct mf_graph{
public:
  mf_graph():_n(0){}
  mf_graph(int n):_n(n),g(n){}

  int add_edge(int from,int to,Cap cap){
    assert(0<=from&&from<_n);
    assert(0<=to&&to<_n);
    assert(0<=cap);
    int m=int(pos.size());
    pos.push_back({from,int(g[from].size())});
    int from_id=int(g[from].size());
    int to_id=int(g[to].size())+int(from==to);
    g[from].push_back(_edge{to,to_id,cap});
    g[to].push_back(_edge{from,from_id,0});
    return m;
  }

  struct edge {
    int from,to;
    Cap cap,flow;
  };

  edge get_edge(int i){
    assert(0<=i&&i<int(pos.size()));
    auto _e=g[pos[i].first][pos[i].second];
    auto _re=g[_e.to][_e.rev];
    return edge{pos[i].first,_e.to,_e.cap+_re.cap,_re.cap};
  }
  vector<edge> edges(){
    vector<edge> result;
    for(int i=0;i<int(pos.size());i++){
      result.push_back(get_edge(i));
    }
    return result;
  }
  void change_edge(int i,Cap new_cap,Cap new_flow){
    assert(0<=i&&i<int(pos.size()));
    assert(0<=new_flow&&new_flow<=new_cap);
    auto&_e=g[pos[i].first][pos[i].second];
    auto&_re=g[_e.to][_e.rev];
    _e.cap=new_cap-new_flow;
    _re.cap=new_flow;
  }

  Cap flow(int s,int t){
    return flow(s,t,numeric_limits<Cap>::max());
  }
  Cap flow(int s,int t,Cap flow_limit){
    assert(0<=s&&s<_n);
    assert(0<=t&&t<_n);
    assert(s!=t);

    vector<int> level(_n),iter(_n);
    simple_queue<int> que;

    auto bfs=[&](){
      fill(level.begin(),level.end(),-1);
      level[s]=0;
      que.clear();
      que.push(s);
      while(!que.empty()){
        int v=que.front();
        que.pop();
        for(auto e:g[v]){
          if(e.cap==0||level[e.to]>=0)continue;
          level[e.to]=level[v]+1;
          if(e.to==t)return;
          que.push(e.to);
        }
      }
    };
    //C++11
    // function<Cap(int,Cap)> dfs=[&](int v,Cap up){
    auto dfs=[&](auto self,int v,Cap up){
      if(v==s)return up;
      Cap res=0;
      int level_v=level[v];
      for(int&i=iter[v]; i<int(g[v].size()); i++){
        _edge&e=g[v][i];
        if(level_v<=level[e.to]||g[e.to][e.rev].cap==0)continue;
        // Cap d=dfs(e.to,min(up-res,g[e.to][e.rev].cap));
        Cap d=self(self,e.to,min(up-res,g[e.to][e.rev].cap));
        if(d<=0)continue;
        g[v][i].cap+=d;
        g[e.to][e.rev].cap-=d;
        res+=d;
        if(res==up)break;
      }
      return res;
    };

    Cap flow=0;
    while(flow<flow_limit){
      bfs();
      if(level[t]==-1)break;
      fill(iter.begin(),iter.end(),0);
      while(flow<flow_limit){
        // Cap f=dfs(t,flow_limit-flow);
        Cap f=dfs(dfs,t,flow_limit-flow);
        if(!f)break;
        flow+=f;
      }
    }
    return flow;
  }

  vector<bool> min_cut(int s){
    vector<bool> visited(_n);
    simple_queue<int> que;
    que.push(s);
    while(!que.empty()){
      int p=que.front();
      que.pop();
      visited[p]=true;
      for(auto e:g[p]){
        if(e.cap&&!visited[e.to]){
          visited[e.to]=true;
          que.push(e.to);
        }
      }
    }
    return visited;
  }
private:
  int _n;
  struct _edge{
    int to,rev;
    Cap cap;
  };
  vector<pair<int,int>> pos;
  vector<vector<_edge>> g;
  template<class T>struct simple_queue{
    vector<T> payload;
    int pos=0;
    void reserve(int n){payload.reserve(n);}
    int size() const{return int(payload.size())-pos;}
    bool empty() const{return pos==int(payload.size());}
    void push(const T& t){payload.push_back(t);}
    T& front(){return payload[pos];}
    void clear(){
      payload.clear();
      pos=0;
    }
    void pop(){++pos;}
  };
};

struct unionfind{
  private:
  int maxN;
  vector<int> par,treesize;
  public:unionfind(int N) :maxN(N),par(N),treesize(N,1){
    for(int i=0;i<maxN;++i)par[i]=i;
  }
  int root(int x){
    while(par[x]!=x){
      x=par[x]=par[par[x]];
    }
    return x;
  }
  bool unite(int x,int y){
    x=root(x);
    y=root(y);
    if(x==y)return false;
    if(treesize[x]>treesize[y])swap(x,y);
    par[x]=y;
    treesize[y]+=treesize[x];
    return true;
  }
  bool unite(pair<int,int> v){
    return unite(v.first,v.second);
  }
  bool parcheck(int x,int y){
    return root(x)==root(y);
  }
  bool parcheck(pair<int,int> v){
    return parcheck(v.first,v.second);
  }
  int size(int x){
    return treesize[root(x)];
  }
  void clear(){
    treesize.assign(maxN,1);
    for(int i=0;i<maxN;++i)par[i]=i;
  }
  vector<vector<int>> groups(){
    vector<vector<int>> res(maxN);
    for(int i=0;i<maxN;++i)res[root(i)].eb(i);
    // return res;
    vector<vector<int>> res2;
    for(vector<int> x:res){
      if(x.size())res2.eb(x);
    }
    return res2;
  }
};

int main(){
int codeforces;cin>>codeforces;while(codeforces--){
  ll i,j,N;
  cin>>N;
  mat tree(N);
  unionfind dsu(N*2);
  rep1(i,N){
    ll a,b;
    cin>>a>>b;
    --a;--b;
    dsu.unite(a,b+N);
    dsu.unite(a+N,b);
    tree[a].emplace_back(b);
    tree[b].emplace_back(a);
  }
  mf_graph<int> fl(N+2);
  mat g(N);
  rep(i,N){
    if(tree[i].size()<=2)continue;
    bool f=dsu.parcheck(0,i);
    if(f){
      fl.add_edge(N,i,tree[i].size()-2);
      for(auto x:tree[i]){
        if(tree[x].size()>2)fl.add_edge(i,x,1);
        else g[i].emplace_back(x);
      }
    }else{
      fl.add_edge(i,N+1,tree[i].size()-2);
      for(auto x:tree[i]){
        if(tree[x].size()<=2)g[i].emplace_back(x);
      }
    }
  }
  fl.flow(N,N+1);
  set<datas> eraselist;
  vec h(N);
  rep(i,N)h[i]=tree[i].size();
  mat sg(N);
  for(auto edge:fl.edges()){
    if(max(edge.from,edge.to)>=N){
      i=min(edge.from,edge.to);
      int T=min(edge.cap-edge.flow,int(g[i].size()));
      rep(j,T){
        h[g[i][j]]--;
        eraselist.emplace(minmax(i,g[i][j]));
      }
      h[i]-=T;
    }else if(edge.flow){
      h[edge.from]--;
      h[edge.to]--;
      eraselist.emplace(minmax(ll(edge.from),ll(edge.to)));
    }else{
      sg[edge.from].emplace_back(edge.to);
      sg[edge.to].emplace_back(edge.from);
    }
  }
  rep(i,N){
    while(h[i]>2){
      h[sg[i].back()]--;
      h[i]--;
      eraselist.emplace(minmax(sg[i].back(),i));
      sg[i].pop_back();
    }
  }
  dsu.clear();
  rep(i,N){
    for(auto x:tree[i]){
      if(i>x)continue;
      if(!eraselist.count(datas(i,x)))dsu.unite(i,x);
    }
  }
  print(eraselist.size());
  queue<ll> que;
  rep(i,N)if(h[i]<2)que.emplace(i);
  i=0;
  for(auto[a,b]:eraselist){
    auto x=que.front();que.pop();
    auto y=que.front();que.pop();
    if(dsu.parcheck(x,y)){
      que.emplace(x);
      x=que.front();que.pop();
    }
    assert(dsu.unite(x,y));
    h[x]++;h[y]++;
    if(h[x]<2)que.push(x);
    if(h[y]<2)que.push(y);
    print(a+1<<" "<<b+1<<" "<<x+1<<" "<<y+1);
    ++i;
  }
  assert(que.size()==2);
}
}