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
#define double long double
using datas=pair<ll,ll>;
using ddatas=pair<double,double>;
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
constexpr double eps=1e-9;
const double PI=acos(-1);
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
template<class T> inline bool chmax(T& a,T b){bool x=a<b;if(x)a=b;return x;}
template<class T> inline bool chmin(T& a,T b){bool x=a>b;if(x)a=b;return x;}
#ifdef DEBUG
void debugg(){cout<<endl;}
template<class T,class... Args>void debugg(const T& x,const Args&... args){cout<<" "<<x;debugg(args...);}
#define debug(...) cout<<__LINE__<<" ["<<#__VA_ARGS__<<"]:",debugg(__VA_ARGS__)
#else
#define debug(...) (void(0))
#endif

void startupcpp(){
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
    auto dfs=[&](auto self,int v,Cap up){
      if(v==s)return up;
      Cap res=0;
      int level_v=level[v];
      for(int&i=iter[v]; i<int(g[v].size()); i++){
        _edge&e=g[v][i];
        if(level_v<=level[e.to]||g[e.to][e.rev].cap==0)continue;
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

int ans,a[3001];
bool ch[101];
int main(){
  startupcpp();
  // int codeforces;cin>>codeforces;while(codeforces--){
  ll i,j,N;
  cin>>N;
  rep(i,N)cin>>a[i];
  mf_graph<int> g(N+2);
  //nokosu 0 tatakiwaru N+1
  rep(i,N){
    cin>>j;
    if(j>0){
      ans+=j;
      g.add_edge(N,i,0);
      g.add_edge(i,N+1,j);
    }else{
      g.add_edge(N,i,-j);
      g.add_edge(i,N+1,0);
    }
  }
  rep(i,N){
    rep(j,101)ch[j]=false;
    brep(j,i){
      if(a[i]%a[j]||ch[a[j]])continue;
      ch[a[j]]=true;
      debug(i,j);
      g.add_edge(j,i,1<<25);
    }
  }
  print(ans-g.flow(N,N+1));
// }
}