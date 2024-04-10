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
const int mxN = 1e5+1;
const ll oo = 1e18;
void solve() {
    int n,m; cin >> n >> m;
    vector<vector<ll>> c(n,vector<ll>(m));
    for(int i=0;i<n;++i) {
        for(auto& j : c[i] ) cin >> j;
    }
    // ok, vind degene met dezelfde gemiddelde?
    auto get = [&](vector<ll>& v) {
        __int128_t ans=0;
        for(int i=0;i<m;++i) {
            ans+=i*v[i];
        }
        return ans;
    };
    map<__int128_t ,vi> cnt;
    for(int i=0;i<n;++i) cnt[get(c[i])].push_back(i);
    int res=0;
    for(auto& [c,pos] : cnt) {
        if(pos.size()==1) {
            res = pos[0];
        }
    }
    cout << res+1 << ' ' << ll(get(c[res])-get(c[res==0])) << '\n';

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
        solve();
    }
}