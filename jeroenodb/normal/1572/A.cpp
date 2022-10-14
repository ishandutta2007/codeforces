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
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
    int n; cin >> n;
    vvi adj(n);
    vi deg(n);
    for(int i=0;i<n;++i) {
        int k; cin >> k;
        deg[i]=k;
        while(k--) {
            int a; cin >> a,--a;
            adj[a].push_back(i);
        }
    }
    set<int> s;
    for(int i=0;i<n;++i) if(deg[i]==0) s.insert(i);
    int times=0,got=s.size();
    while(!s.empty()) {
        for(auto it = s.begin();it!=s.end();) {
            auto at = *it;
            for(int to : adj[at]) {
                if(--deg[to]==0) {
                    s.insert(to);
                    got++;
                }
            }
            it = s.erase(it);
        }
        times++;
    }
    if(got!=n) cout << "-1\n";
    else cout << times << '\n';
    }
}