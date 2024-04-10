// Hydro submission #62c563e48672efa577bec2d6@1657103332762
#include <bits/stdc++.h>
 
#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define si set<int>
#define vvi vector<vector<int>>
#define vvl vector<vector<long long>>
#define vl vector<long long>
#define pii pair<int, int>
#define pll pair<ll,ll>
#define add push_back
#define REP(i,a) for (int i = 0; i < (a); i++)
using namespace std;
 
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;
 
const int INF = 0x3f3f3f3f; 
const ll MOD = 1000000007LL;
//const ll MOD = 998244353LL;
 
int ni() {
    int x; cin >> x;
    return x;
}
 
ll nl() {
    ll x; cin >> x;
    return x;
}
 
double nd() {
    double x; cin >> x;
    return x;
}

string next() {
    string x; cin >> x;
    return x;
}

vvi tree;
vi dist;
int N;

pii query(vi& nodes) {
    cout << "? " << sz(nodes) << ' ';
    for (int n: nodes) {
        cout << n+1 << ' ';
    }
    cout << endl;
    int x = ni()-1;
    int d = ni();
    if (x==-1) exit(0);
    return {x,d};
}

void dfs(int u, int p) {
    for (int v: tree[u]) {
        if (v != p) {
            dist[v] = dist[u]+1;
            dfs(v,u);
        }
    }
}

void solve() {
    vi every;
    REP(i,N) every.add(i);
    pii firstQ = query(every);
    int root = firstQ.first; //"root" is on the optimal path
    int pathSize = firstQ.second;
    dist[root] = 0;
    dfs(root,-1);
    
    vvi nodes(N,vi{});
    REP(i,N) {
        nodes[dist[i]].add(i);
    }
    
    
    int lo = 1;
    int hi = N-1;
    int X = -1;
    int Y = -1;
    while (lo < hi) {
        int m = (lo+hi+1)/2;
        if (nodes[m].empty()) {
            hi = m-1;
        } else {
            pii res = query(nodes[m]);
            if (res.second > pathSize) {
                hi = m-1;
            } else {
                lo = m;
            }
        }
    }
    X = query(nodes[lo]).first;
    
    dist.assign(N,INF);
    dist[X] = 0;
    dfs(X,-1);
    vi others;
    REP(i,N) {
        if (dist[i]==pathSize) others.add(i);
    }
    Y = query(others).first;
    
    cout << "! " << X+1 << ' ' << Y+1 << endl;
    string result = next();
    if (result=="Incorrect") exit(0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int Q = ni();
    REP(q,Q) {
        N = ni();
        tree.assign(N,vi{});
        dist.assign(N,INF);
        REP(i,N-1) {
            int u = ni()-1;
            int v = ni()-1;
            tree[u].add(v);
            tree[v].add(u);
        }
        solve();
    }
}