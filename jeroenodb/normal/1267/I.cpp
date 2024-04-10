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
const int mxN = 1e3+1, oo = 1e9;
set<int> adj[mxN];
int deg[mxN],n;
bool comp(int i,int j) {
    cout << "? " << i << ' ' << j << endl;
    char c; cin >> c;
    return c=='<';
}
vi mysort(int i, int j) {
    vi v(j-i+1); iota(all(v),i);
    stable_sort(all(v), comp);
    return v;
}
void solve() {
    cin >> n;
    for(int i=1;i<=2*n;++i) adj[i].clear(),deg[i]=-1;
    // query pairs
    auto g1 = mysort(1,2), g2 = mysort(3,n+1);
    for(int i=n+2;i<=2*n;++i) {
        if(comp(g2[0],g1[0])) swap(g1,g2);
        g1.erase(g1.begin());
        g1.insert(lower_bound(all(g1),i,comp),i);
    }
    comp(g1[0],g2[0]);
    cout << "!" << endl;
    
}
int main() {
    int t; cin >> t;
    while(t--) solve();    
}