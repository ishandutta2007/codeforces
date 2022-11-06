#include <bits/stdc++.h>
 
using namespace std;
 
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define fileio freopen("in.in", "r", stdin),freopen("out.out", "w", stdout);
#define ll long long
#define int long long
#define FF first
#define SS second
#define mp make_pair
#define pb push_back
#define pii pair<ll,ll>
#define pll pair<long long,long long>
#define sd(x) scanf("%d",&x)
#define slld(x) scanf("%lld",&x)
#define pd(x) prllf("%d\n",x)
#define plld(x) prllf("%lld\n",x)
#define pss prllf
#define MOD 1000000007
#define eps 0.00001
#define endl '\n'
#define debug(n1) cout<<n1<<endl
ll n,k,s[1005],e[1005],c[1005];
bool y[1005];
const ll INF = 1e17+5;
int mm[100005];
vector<int>temp[100005];

struct MinimumCostMaximumFlow {
  typedef ll Index; typedef ll Flow; typedef ll Cost;
  static const Flow InfCapacity = INF;
  struct Edge {
    Index to; Index rev;
    Flow capacity; Cost cost;
  };
  vector<vector<Edge> > g;
  void init(Index n) { g.assign(n, vector<Edge>()); }
  void addEdge(bool inv,Index i, Index j, Flow capacity = InfCapacity, Cost cost = Cost() ) {
    Edge e, f; e.to = j, f.to = i; e.capacity = capacity, f.capacity = 0; e.cost = cost, f.cost = -cost;
    if(inv)
    {
        temp[i].push_back(mm[i]);
    }
    mm[i]++;
    mm[j]++;

    g[i].push_back(e); g[j].push_back(f);
    g[i].back().rev = (Index)g[j].size() - 1; g[j].back().rev = (Index)g[i].size() - 1;
  }
  void addB(Index i, Index j, Flow capacity = InfCapacity, Cost cost = Cost()) {
    addEdge(0,i, j, capacity, cost);
    addEdge(0,j, i, capacity, cost);
  }

  pair<Cost, Flow> minimumCostMaximumFlow(Index s, Index t, Flow f = InfCapacity, bool useSPFA = false) {
    ll n = g.size();
    vector<Cost> dist(n); vector<Index> prev(n); vector<Index> prevEdge(n);
    pair<Cost, Flow> total = make_pair(0, 0);
    vector<Cost> potential(n);
    while(f > 0) {
      fill(dist.begin(), dist.end(), INF);
      if(useSPFA || total.second == 0) {
        deque<Index> q;
        q.push_back(s); dist[s] = 0; vector<bool> inqueue(n);
        while(!q.empty()) {
          Index i = q.front(); q.pop_front(); inqueue[i] = false;
          for(Index ei = 0; ei < (Index)g[i].size(); ei ++) {
            const Edge &e = g[i][ei]; Index j = e.to; Cost d = dist[i] + e.cost;
            if(e.capacity > 0 && d < dist[j]) {
              if(!inqueue[j]) {
                inqueue[j] = true;
                q.push_back(j);
              }
              dist[j] = d; prev[j] = i; prevEdge[j] = ei;
            }
          }
        }
      } else {
        vector<bool> vis(n);
        priority_queue<pair<Cost, Index> > q;
        q.push(make_pair(-0, s)); dist[s] = 0;
        while(!q.empty()) {
          Index i = q.top().second; q.pop();
          if(vis[i]) continue;
          vis[i] = true;
          for(Index ei = 0; ei < (Index)g[i].size(); ei ++) {
            const Edge &e = g[i][ei];
            if(e.capacity <= 0) continue;
            Index j = e.to; Cost d = dist[i] + e.cost + potential[i] - potential[j];
            if(dist[j] > d) {
              dist[j] = d; prev[j] = i; prevEdge[j] = ei;
              q.push(make_pair(-d, j));
            }
          }
        }
      }
      if(dist[t] == INF) break;
      if(!useSPFA) for(Index i = 0; i < n; i ++) potential[i] += dist[i];
 
      Flow d = f; Cost distt = 0;
      for(Index v = t; v != s; ) {
        Index u = prev[v]; const Edge &e = g[u][prevEdge[v]];
        d = min(d, e.capacity); distt += e.cost; v = u;
      }
      f -= d; total.first += d * distt; total.second += d;
      for(Index v = t; v != s; v = prev[v]) {
        Edge &e = g[prev[v]][prevEdge[v]];
        e.capacity -= d; g[e.to][e.rev].capacity += d;
      }
    }
    return total;
  }
};
 

int find_num(string ss)
{
    int ans=0;
    int tt=1;
    reverse(ss.begin(),ss.end());

    for(auto i:ss)
    {
        ans+=(i-'0')*tt;
        tt*=2;
    }
    return ans;
}



vector<vector<int> >adj;
int sz[1000005];
int vis[1000005];
int a[100005];
vector<string>fi;
int d;

void print(int yy)
{
    for(int i=0;i<10;i++)
    {
        if(((1<<i)&yy))
        {
            fi.push_back(to_string(d-i-1));
        }
    }
}

void dfs(int ver,int x)
{
    vis[ver]=1;
    print(a[ver]^x);
    int cnt=0;


    for(auto i:adj[ver])
    {
        if(vis[i]==0)
        {
            if(cnt)
            {
                fi.push_back("R");
                print(a[ver]);
                dfs(i,a[ver]);
            }
            else
            {
                dfs(i,a[ver]);
            }
            cnt++;
        }
    }
}

signed main()
{
 
ios_base::sync_with_stdio(false); 
cin.tie(NULL);  
cout.tie(0);   
 
#ifndef ONLINE_JUDGE
    if(fopen("INPUT.txt","r"))
    {
        freopen("INPUT.txt","r",stdin);
        freopen("OUTPUT.txt","w",stdout);
    }

#endif          

    int n;
    cin>>d>>n;
    string se[n];
    for(int i=0;i<n;i++)
    {
        cin>>se[i];
        a[i+1]=find_num(se[i]);
    }

    adj.resize(n+1);

    MinimumCostMaximumFlow kad;
    int source=0;
    int sink=2*n+5;

    kad.init(2*n+10);

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i!=j)
            {
                if((a[i]&a[j])==a[j])
                {
                    kad.addEdge(1,n+j,i,1,-(__builtin_popcount(a[j])+1));
                }
            }
        }

        kad.addEdge(0,i,n+i,1,0);
        kad.addEdge(0,source,i,1,0);
        kad.addEdge(0,n+i,sink,1,-(__builtin_popcount(a[i])+1));
    }

    kad.addEdge(0,source,sink,n,0);

    pair<int,int> ans=kad.minimumCostMaximumFlow(source,sink,n,0);

    for(int i=n+1;i<=2*n;i++)
    {
        for(auto j:temp[i])
        {
            if(kad.g[i][j].capacity==0)
            {
                adj[i-n].push_back(kad.g[i][j].to);
            }
        }
    }

    set<pair<int,int> >ss;
    int cc=0;
    for(int i=1;i<=n;i++)
    {
        ss.insert({a[i],i});
    }

    while(!ss.empty())
    {
        auto j=ss.begin();
        if(vis[j->second])
        {
            ss.erase(j);
            continue;
        }
        if(cc)
            fi.push_back("R");
        cc++;
        dfs(j->second,0);
    }

    cout<<fi.size()<<'\n';
    for(auto i:fi)
        cout<<i<<" ";



}