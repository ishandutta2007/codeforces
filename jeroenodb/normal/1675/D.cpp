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
vvi ps;
vvi adj;
void dfs(int at, bool nw=true) {
    if(nw) ps.push_back({});
    ps.back().push_back(at+1);
    bool f=false;
    for(auto to : adj[at]) {
        dfs(to,f);
        f=true;
    }
}
void solve() {
    int n; cin >> n;
    adj.assign(n,{});
    ps.clear();
    int rt=-1;
    for(int i=0;i<n;++i) {
        int p; cin >> p;
        p--;
        if(p==i) rt=p;
        else adj[p].push_back(i);
    }
    dfs(rt);
    cout << ps.size() << '\n';
    for(auto i : ps) {
        cout << i.size() << '\n' << i << '\n';
    }
    cout << '\n';

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
}