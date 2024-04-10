#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
#define endl '\n'
#define all(vec) vec.begin(),vec.end()
#define mp make_pair
const int N = 4e5+7;
vector<int> G[N];
int tin[N],tout[N],par[N],timer;
bool dfs(int v){
    if (tin[v]) return 0;
    tin[v] = ++timer;
    for(int to:G[v])
        if (dfs(to)) par[to] = v;
    tout[v] = timer;
    return 1;
}
bool is_par(int a,int b){
    return tin[a]<=tin[b] && tout[b]<=tout[a];
}
vector<pair<int,pair<int,int> > > V[N];
int P[N],col[N],tagged[N];
int F(int x){
    if (x==P[x])
        return x;
    int root = F(P[x]);
    col[x] = col[P[x]]^col[x];
    P[x] = root;
    return root;
}
void NO(){
    cout << "NO\n";
    exit(0);
}
void unite(int a,int b,bool chg){
    int root_a = F(a),root_b = F(b);
    if (root_a==root_b){
        if (col[a]^col[b]^chg) NO();
        return;
    }
    col[root_b] = col[a]^col[b]^chg;
    P[root_b] = root_a;
}
int ans[N];
void solve(int v){
    if (!V[v].empty()) {
        int symb = ans[v];
        pair<int,int> can = V[v][0].second;
        if (can.first==can.second)
            can.second = -1;
        for (auto[pos, cl]:V[v]) {
            if (can.first!=cl.first && can.first!=cl.second)
                can.first = -1;
            if (can.second!=cl.first && can.second!=cl.second)
                can.second = -1;
            if (tagged[F(pos)] != -1) {
                int put = tagged[F(pos)] ^ col[pos] ? cl.second : cl.first;
                if (symb == -1)
                    symb = put;
                if (put != symb)  NO();
            }
        }
        if (symb==-1 && (can.first==-1 || can.second==-1)){
            symb = can.first==-1?can.second:can.first;
            if (symb==-1) NO();
        }
        if (symb!=-1 && can.first!=symb && can.second!=symb) NO();
        if (symb!=-1){
            for(auto [pos,cl]:V[v]){
                if (tagged[F(pos)]==-1 && (cl.first!=symb || cl.second!=symb)){
                    tagged[F(pos)] = col[pos]^(cl.second==symb);
                }
            }
            ans[v] = symb;
        }
        else{
            for(auto [pos,cl]:V[v]){
                unite(V[v][0].first,pos,V[v][0].second.first!=cl.first);
            }
        }
    }
    for(int to:G[v])
        if (!is_par(to,v))
            solve(to);
}
void solve() {
    int n,q;
    cin>>n>>q;
    for(int i = 1;i<n;++i){
        int u,v; cin>>u>>v;
        G[u].push_back(v); G[v].push_back(u);
    }
    for(int i = 1;i<=n;++i)
        ans[i] = -1;
    timer = 0;
    dfs(1);
    for(int i = 1;i<=q;++i){
        int x,y; string s;
        cin>>x>>y>>s;
        tagged[i] = -1;
        P[i] = i;
        col[i] = 0;
        int ptr = 0;
        vector<int> h1,h2;
        while(1){
            h1.push_back(x);
            if (is_par(x,y))
                break;
            x = par[x];
        }
        while(y!=x){
            h2.push_back(y);
            y = par[y];
        }
        reverse(all(h2));
        for(int to:h2)
            h1.push_back(to);
        for(int x:h1){
            V[x].push_back({i,{s[ptr]-'a',s[int(s.size())-1-ptr]-'a'}});
            assert(ptr<s.size());
            ++ptr;
        }
        assert(ptr==s.size());
    }
    solve(1);
    cout<<"YES\n";
    for(int i = 1;i<=q;++i){
        int par = F(i);
        if (tagged[par]==-1)
            tagged[par] = 0;
    }
    solve(1);
  //  cout<<"YES\n";
    for(int i = 1;i<=n;++i) {
        if (ans[i]==-1)
            ans[i] = 0;
        cout << char('a' + ans[i]);
    }
    cout<<endl;
}
signed main(){

    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    //cin>>t;
    while(t--)
        solve();
}