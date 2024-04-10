#pragma GCC optimize("Ofast")
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
bitset<mxN> used;
int sz[mxN], fib[40];
    vi adj[mxN];
void dfsz(int at) {
    used[at] = true;
    sz[at] =1;
    for(int to: adj[at]) {
        if(!used[to]) {
            dfsz(to);
            sz[at]+=sz[to];
        }
    }
    used[at] = false;

}
vector<pi> cand;
void dfscand(int at, int fibl) {
    used[at] = true;
    for(int to: adj[at]) {
        if(used[to]) continue;

        if(sz[to]==fib[fibl-1]) {
            cand.push_back({at,to});
        } else if(sz[to] == fib[fibl-2]) {
            cand.push_back({to,at});
        }
        dfscand(to,fibl);

    }
    used[at] = false;
}
bool solve(int at, int fibl) {
    // find candidate new edges
    if(fibl <4) {
        return true;
    }
    dfsz(at);
    cand.clear();
    dfscand(at,fibl);
    int iters=0;
    for(auto p: cand) {
        if(iters==2) break;
        used[p.second]=true;
        iters++;
        bool good = solve(p.first,fibl-2);
        used[p.second]=false;
        if(!good) continue;
        used[p.first]=true;
        iters++;
        good = solve(p.second,fibl-1);
        used[p.first]=false;
        if(good) return true;
    }
    return false;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    fib[0]=fib[1] = 1;
    for(int i=2;i<40;++i) {
        fib[i] =fib[i-1]+fib[i-2];
    }
    for(int i=0;i<n-1;++i) {
        int a,b; cin >> a >> b; --a,--b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int i=0;
    while(fib[i]<n) {
        ++i;
    }
    if(fib[i]!=n) {
        cout << "NO" << endl;
    } else {
        cout << (solve(0,i)? "YES\n":"NO\n");
    }

}