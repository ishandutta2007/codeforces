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
const int mxN = 2e5+10, oo = 1e9;
set<int> adj[mxN];
int cnt[mxN],hashigher=0;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m; cin >> n >> m;
    for(int i=0;i<m;++i) {
        int a,b; cin >> a >> b;
        if(a>b) swap(a,b);
        if(!cnt[a]) hashigher++;
        cnt[a]++;
    }
    int q; cin >> q;
    while(q--) {
        int t,u,v; cin >> t;
        if(t!=3) cin >> u >> v;
        if(u>v) swap(u,v);
        if(t==1) {
            if(!cnt[u]) hashigher++;
            cnt[u]++;
        } else if(t==2) {
            if(--cnt[u] == 0) {
                hashigher--;
            }
        } else cout << n-hashigher << '\n';
    }
}