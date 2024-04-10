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
    int n; ll h; cin >> n >> h;
    vi a(n); for(auto& i : a) cin >> i;
    ll lo = 0,hi = 2e18;
    auto good = [&](ll mid) {
        ll damage = 0;
        for(int i=0;i<n;++i) {
            if(i!=n-1) {
                damage+=min(mid,(ll)a[i+1]-a[i]);
            } else damage+=mid;
        }
        return damage>=h;
    };
    while(lo<hi) {
        ll mid = (lo+hi)/2;
        if(good(mid)) {
            hi = mid;
        } else lo = mid+1;
    }
    cout << lo << '\n';
}
int main() {
    int t; cin >> t;
    while(t--) solve();
}