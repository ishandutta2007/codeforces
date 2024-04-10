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
const ll oo = 1e10;
typedef __int128_t Int;
vi a;
int n;
ll f( ll tt) {
    auto cost = [&](int i, int j) {
        return ll(a[i])*a[j]+(a[i]+a[j])*tt;
    };
    ll ans=cost(0,n-1);
    for(int i=1;i<n-1;++i) ans+=min(cost(0,i),cost(n-1,i));
    return ans;
}
void solve() {
    cin >> n;
    a.resize(n);
    for(auto& i : a) cin >> i;
    sort(all(a));
    ll l=-oo,r=oo;
    while(l<r) {
        auto mid = l +(r-l)/2;
        if(f(mid) > f(mid+1)) {
            r = mid;
        } else l = mid+1;
    }
    if(f(l)<f(l-1) or f(l)<f(l+1)) {
        cout << "INF\n";
    } else cout << f(l) << '\n';
}
int main() {
    int t; cin >> t;
    while(t--) solve();
}