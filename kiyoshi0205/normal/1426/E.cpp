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
#define endl "\n"
#define eb emplace_back
#define print(x) cout<<x<<endl
#define printyes print("Yes")
#define printno print("No")
#define printYES print("YES")
#define printNO print("NO")
#define output(v) do{bool f=0;for(auto outi:v){cout<<(f?" ":"")<<outi;f=1;}cout<<endl;}while(0)
#define matoutput(v) do{for(auto outimat:v)output(outimat);}while(0)
const ll mod=1000000007;
// const ll mod=998244353;
const ll inf=1LL<<60;
const double PI=acos(-1);
const double eps=1e-9;
template<class T,class E> ostream& operator<<(ostream& os,pair<T,E>& p){return os<<"{"<<p.first<<","<<p.second<<"}";}
template<class T> inline bool chmax(T& a,T b){bool x=a<b;if(x)a=b;return x;}
template<class T> inline bool chmin(T& a,T b){bool x=a>b;if(x)a=b;return x;}

void startupcpp(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(15);
}

double distance(ddatas x,ddatas y){
  double a=x.first-y.first,b=x.second-y.second;
  return sqrt(a*a+b*b);
}

ll modinv(ll a,ll m=mod) {
  ll b=m,u=1,v=0,t;
  while(b){
    t=a/b;
    a-=t*b; swap(a,b);
    u-=t*v; swap(u,v);
  }
  return (u+m)%m;
}

ll moddevide(ll a,ll b){return (a*modinv(b))%mod;}

vec modncrlistp,modncrlistm;

ll modncr(ll n,ll r){
  if(n<r)return 0;
  ll i,size=modncrlistp.size();
  if(size<=n){
    modncrlistp.resize(n+1);
    modncrlistm.resize(n+1);
    if(!size){
      modncrlistp[0]=modncrlistm[0]=1;
      size++;
    }
    For(i,size,n+1){
      modncrlistp[i]=modncrlistp[i-1]*i%mod;
      modncrlistm[i]=modinv(modncrlistp[i]);
    }
  }
  return modncrlistp[n]*modncrlistm[r]%mod*modncrlistm[n-r]%mod;
}

ll modpow(ll a,ll n,ll m=mod){
  ll res=1;
  while(n>0){
    if(n&1)res=res*a%m;
    a=a*a%m;
    n>>=1;
  }
  return res;
}

ll gcd(ll a,ll b){if(!b)return abs(a);return (a%b==0)?abs(b):gcd(b,a%b);}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

ll countdigits(ll n){
  ll ans=0;
  while(n){n/=10;ans++;}
  return ans;
}

ll sumdigits(ll n){
  ll ans=0;
  while(n){ans+=n%10;n/=10;}
  return ans;
}
template<class Cap,class Cost> struct mcf_graph{
public:
  mcf_graph(){}
  mcf_graph(int n):_n(n),g(n){}

  int add_edge(int from,int to,Cap cap,Cost cost){
    assert(0<=from&&from<_n);
    assert(0<=to&&to<_n);
    int m=int(pos.size());
    pos.push_back({from,int(g[from].size())});
    int from_id=int(g[from].size());
    int to_id=int(g[to].size())+int(from==to);
    g[from].push_back(_edge{to,to_id,cap,cost});
    g[to].push_back(_edge{from,from_id,0,-cost});
    return m;
  }

  struct edge{
    int from,to;
    Cap cap,flow;
    Cost cost;
  };

  edge get_edge(int i){
    assert(0<=i&&i<int(pos.size()));
    auto _e=g[pos[i].first][pos[i].second];
    auto _re=g[_e.to][_e.rev];
    return edge{
      pos[i].first,_e.to,_e.cap+_re.cap,_re.cap,_e.cost,
    };
  }
  vector<edge> edges(){
    int m=int(pos.size());
    vector<edge> result(m);
    for(int i=0;i<m;++i){
      result[i]=get_edge(i);
    }
    return result;
  }

  pair<Cap,Cost> flow(int s,int t){
    return flow(s,t,numeric_limits<Cap>::max());
  }
  pair<Cap,Cost> flow(int s,int t,Cap flow_limit){
    return slope(s,t,flow_limit).back();
  }
  vector<pair<Cap,Cost>> slope(int s,int t){
    return slope(s,t,numeric_limits<Cap>::max());
  }
  vector<pair<Cap,Cost>> slope(int s,int t,Cap flow_limit){
    assert(0<=s&&s<_n);
    assert(0<=t&&t<_n);
    assert(s!=t);
    // variants(C=maxcost):
    //-(n-1)C<=dual[s]<=dual[i]<=dual[t]=0
    // reduced cost(=e.cost+dual[e.from]-dual[e.to])>=0 for all edge
    vector<Cost> dual(_n,0),dist(_n);
    vector<int> pv(_n),pe(_n);
    vector<bool> vis(_n);
    auto dual_ref=[&](){
      fill(dist.begin(),dist.end(),numeric_limits<Cost>::max());
      fill(pv.begin(),pv.end(),-1);
      fill(pe.begin(),pe.end(),-1);
      fill(vis.begin(),vis.end(),false);
      struct Q{
        Cost key;
        int to;
        bool operator<(Q r)const{ return key>r.key;}
      };
      priority_queue<Q> que;
      dist[s]=0;
      que.push(Q{0,s});
      while(!que.empty()){
        int v=que.top().to;
        que.pop();
        if(vis[v])continue;
        vis[v]=true;
        if(v==t)break;
        // dist[v]=shortest(s,v)+dual[s]-dual[v]
        // dist[v]>=0(all reduced cost are positive)
        // dist[v]<=(n-1)C
        for(int i=0;i<int(g[v].size());++i){
          auto e=g[v][i];
          if(vis[e.to]||!e.cap)continue;
          // |-dual[e.to]+dual[v]|<=(n-1)C
          // cost<=C--(n-1)C+0=nC
          Cost cost=e.cost-dual[e.to]+dual[v];
          if(dist[e.to]-dist[v]>cost){
            dist[e.to]=dist[v]+cost;
            pv[e.to]=v;
            pe[e.to]=i;
            que.push(Q{dist[e.to],e.to});
          }
        }
      }
      if(!vis[t])return false;

      for(int v=0;v<_n;++v){
        if(!vis[v])continue;
        // dual[v]=dual[v]-dist[t]+dist[v]
        //    =dual[v]-(shortest(s,t)+dual[s]-dual[t])+(shortest(s,v)+dual[s]-dual[v])
        //    =-shortest(s,t)+dual[t]+shortest(s,v)
        //    =shortest(s,v)-shortest(s,t)>=0-(n-1)C
        dual[v]-=dist[t]-dist[v];
      }
      return true;
    };
    Cap flow=0;
    Cost cost=0,prev_cost_per_flow=-1;
    vector<pair<Cap,Cost>> result;
    result.push_back({flow,cost});
    while(flow<flow_limit){
      if(!dual_ref())break;
      Cap c=flow_limit-flow;
      for(int v=t;v!=s;v=pv[v]){
        c=min(c,g[pv[v]][pe[v]].cap);
      }
      for(int v=t;v!=s;v=pv[v]){
        auto&e=g[pv[v]][pe[v]];
        e.cap-=c;
        g[v][e.rev].cap+=c;
      }
      Cost d=-dual[s];
      flow+=c;
      cost+=c*d;
      if(prev_cost_per_flow==d){
        result.pop_back();
      }
      result.push_back({flow,cost});
      prev_cost_per_flow=d;
    }
    return result;
  }

private:
  int _n;

  struct _edge{
    int to,rev;
    Cap cap;
    Cost cost;
  };

  vector<pair<int,int>> pos;
  vector<vector<_edge>> g;
};
int main(){
  startupcpp();
  ll i,N;
  cin>>N;
  vec a(3),b(3);
  rep(i,3)cin>>a[i];
  rep(i,3)cin>>b[i];
  mcf_graph<ll,ll> minflow(8),maxflow(8);
  rep(i,3){
    minflow.add_edge(6,i,a[i],0);
    maxflow.add_edge(6,i,a[i],0);
  }
  rep(i,3){
    minflow.add_edge(i+3,7,b[i],0);
    maxflow.add_edge(i+3,7,b[i],0);
  }
  rep(i,3){
    minflow.add_edge(i,i+3,N,0);
    maxflow.add_edge(i,i+3,N,mod);
  }
  rep(i,3){
    minflow.add_edge(i,(i+1)%3+3,N,1);
    maxflow.add_edge(i,(i+1)%3+3,N,mod-1);
  }
  rep(i,3){
    minflow.add_edge(i,(i+2)%3+3,N,0);
    maxflow.add_edge(i,(i+2)%3+3,N,mod);
  }
  print(minflow.flow(6,7,N).second<<" "<<mod*N-maxflow.flow(6,7,N).second);
}