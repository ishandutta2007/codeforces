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
bitset<mxN> vis, forbidden;
vi st;
int want, d[mxN];
void dfs(int at, int from) {
    vis[at]=true;
    st.push_back(at);
    for(int to : adj[at]) if(to!=from) {
        if(vis[to]) {
            if(d[at]-d[to]>=want-1) {
                // output cycle
                cout << "2\n";
                cout << d[at]-d[to]+1 << '\n';
                while(st.back()!=to) {
                    cout << st.back() << ' ';
                    st.pop_back();
                }
                cout << to << '\n';
                exit(0);
            }
        } else {
            d[to]=d[at]+1;
            dfs(to,at);
            if(!forbidden[to]) forbidden[at]=true;
        }
    }
    if(!forbidden[at]) for(int to : adj[at]) if(to!=from and vis[to]) {
        forbidden[to]=true;
    }
    st.pop_back();
}
int main() {
    int n,m; cin >> n >> m;
    want = llround(ceil(sqrt(n)));
    for(int i=0;i<m;++i) {
        int a,b; cin >> a >> b;
        adj[a].push_back(b),adj[b].push_back(a);
    }
    dfs(1,0);
    cout << "1\n";
    for(int i=1;want>0;++i) {
        assert(i<=n);
        if(!forbidden[i]) cout << i << ' ',want--;
    }
}