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
struct edge {
    int x,y,w,p,oriw;
    int to(int at) {
        return at^x^y;
    }
    void read() {
        cin >> x >> y >> w >> p;
        oriw=w;
    }
    void print() {
        cout << x << ' ' << y << ' ' << w << ' ' << p << '\n';
    }
};
vector<edge> es;
vvi adj;
void impos() {
    cout << "-1\n";
    exit(0);
}
vector<ll> dp, slack;
void dfs(int at, int from) {
    for(auto ei : adj[at]) {
        auto& e = es[ei];
        auto to = e.to(at);
        if(to==from) continue;
        
        dfs(to,at);
        if(dp[to]>e.p) {
            impos();
        }
        int dif = min(e.w-1LL,e.p-dp[to]);
        e.p-=dif;
        e.w-=dif;
        dp[at]+=e.w+dp[to];
    }
}
void dfs2(int at, int from) {
    for(auto ei : adj[at]) {
        auto& e = es[ei];
        auto to = e.to(at);
        if(to==from) continue;
        auto dif = max(0LL,min(slack[at],(ll)e.oriw-e.w));
        e.w+=dif;
        e.p+=dif;
        slack[at]-=dif;
        slack[to] = min(slack[at],e.p-dp[to]);
        auto tmp = slack[to];
        dfs2(to,at);
        // update slack[at]
        slack[at]-=tmp-slack[to];
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    es.resize(n-1);
    adj.resize(n+1);
    dp.resize(n+1),slack.resize(n+1,1e18+1);
    for(int i=0;i<n-1;++i) {
        es[i].read();
        adj[es[i].x].push_back(i);
        adj[es[i].y].push_back(i);
    }
    dfs(1,0);
    dfs2(1,0);
    cout << n << '\n';
    for(auto& i : es) {
        i.print();
    }
}