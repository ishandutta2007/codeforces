#include "bits/stdc++.h"
using namespace std;
#define all(x) begin(x),end(x)
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { string sep; for (const T &x : v) os << sep << x, sep = " "; return os; }
#define debug(a) cerr << "(" << #a << ": " << a << ")\n";
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pi;
const int mxN = 2e5+1, oo = 1e9;
vector<pi> adj[mxN];
vector<pi> res;
bitset<mxN*2> mark,vis, ingo;
void addAns(int a, int b) {
    
    ingo[b].flip();
    res.push_back({a,b});
}
void dfs(int at, int pid=-1) {
    vis[at]=true;
    for(auto [to,e] : adj[at]) if(pid!=e) {
        
        if(vis[to]) {
            if(!mark[e]) {
                addAns(at,to);
                mark[e]=true;
            }
        } else {
            dfs(to,e);
            if(ingo[to]) addAns(at,to);
            else addAns(to,at);
            mark[e]=true;
        }
    }
}
int e=0;
void addE(int a, int b) {
    adj[a].push_back({b,e});
    adj[b].push_back({a,e});
    ++e;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m; cin >> n >> m;
    while(m--) {
        int a,b; cin >> a >> b;
        addE(a,b);
    }
    vi odd;
    for(int i=1;i<=n;++i) {
        if(adj[i].size()%2==1) odd.push_back(i);
    }
    for(int i=0;i<(int)odd.size();i+=2) {
        addE(odd[i],odd[i+1]);
    }
    if(e%2==1) {
        addE(1,1);
    }
    dfs(1);
    cout << res.size() << '\n';
    for(auto& [a,b] : res) {
        cout << a << ' ' << b << '\n';
    }
}