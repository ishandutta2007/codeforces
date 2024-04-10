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
    int n,m; cin >> n >> m;
    vector<ll> a(n); for(auto& i : a) cin >> i;
    int g =0;
    for(int i=0;i<m;++i) {
        int b; cin >> b;
        g = gcd(b,g);
    }
    // flip and niet flip
    ll ans=1e18;
    for(int rep=0;rep<2;++rep) {
        ll cur=0;
        for(int i=0;i<g;++i) {
            // check hoeveel echte minnen en minimum
            int mns=0;
            ll fine = 1e18;
            for(int j=i;j<n;j+=g) {
                fine = min(fine,abs(a[j]));
                if(a[j]<=0) mns++;
            }
            if(mns%2!=0) cur+=fine;
        }
        for(int i=0;i<g;++i) a[i]=-a[i];
        ans = min(ans,cur);
    }
    ans*=-2;
    for(auto& i : a) ans+=abs(i);
    cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
}