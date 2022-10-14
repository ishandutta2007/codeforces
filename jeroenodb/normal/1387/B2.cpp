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
const int mxN = 1e5+1, oo = 1e9;
vi adj[mxN];
int sz[mxN],in[mxN];
vi order;
void dfs(int at,int from=-1) {
    in[at] = order.size();
    order.push_back(at);
    for(int to: adj[at]) if(to!=from) dfs(to,at);
}
void dfsz(int at=0, int from=-1) {
    sz[at] = 1;
    for(int to: adj[at]) if(to!=from) {
        dfsz(to,at);
        sz[at]+=sz[to];
    }
}
int main() {
    int n; cin >> n;
    for(int i=0;i<n-1;++i) {
        int a,b; cin >> a >> b,--a,--b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfsz();
    ll ans = 0;
    for(int i=1;i<n;++i) {
        ans+= 2*min(sz[i], n-sz[i]);
    }
    int c=0,from=-1;
    bool done = false;
    while(!done) {
        done = true;
        for(int to: adj[c]) {
            if(to!=from and sz[to]*2>n) {
                done = false;
                from = c;
                c = to;
                break;
            }
        }
    }
    // inorder traversal
    order.reserve(n);
    dfs(c);
    cout << ans << '\n';
    for(int i=0;i<n;++i) {
        cout << order[(in[i]+n/2)%n]+1 << ' ';
    }
}