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
    int n,m; cin >> n >> m;
    vector<string> g(n);
    for(auto& i : g) cin >> i;
    vi pref(m+1);
    for(int i=0;i<n-1;++i) {
        for(int j=0;j<m-1;++j) {
            if(g[i+1][j]=='X' and g[i][j+1]=='X') {
                pref[j+1]++;
            }
        }
    }
    for(int i=1;i<=m;++i) pref[i]+=pref[i-1];
    int q; cin >> q;
    while(q--) {
        int a,b; cin >> a >> b;
        int res = pref[b-1]-pref[a-1];
        if(res>0) cout << "NO\n";
        else cout << "YES\n";
    }

}