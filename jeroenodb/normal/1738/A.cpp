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
void solve() {
    int n; cin >> n;
    vi a(n); for(auto& i : a) cin >> i;
    vi b(n); for(auto& i : b) cin >> i;
    array<vi,2> c = {};
    for(int i=0;i<n;++i) {
        c[a[i]].push_back(b[i]);
    }
    sort(all(c[0]));
    sort(all(c[1]));
    ll ans=0, total = accumulate(all(b),0LL);
    for(int rep=0;rep<2;++rep) {
        if(!c[0].empty()) {
            int len = min(c[0].size(),c[1].size());
            ll extra=accumulate(c[1].end()-len,c[1].end(),0LL);
            len = min(c[1].size(),c[0].size()-1);
            extra+=accumulate(c[0].end()-len,c[0].end(),0LL);
            ans = max(ans,total+extra);
        }
        swap(c[0],c[1]);
    }
    cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
}