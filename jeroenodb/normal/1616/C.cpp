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
    int ans = oo;
    if(n<=2) ans=0;
    for(int i=0;i<n;++i) {
        for(int j=i+1;j<n;++j) {
            // must be a arithmetic progression
            ll dif = a[j]-a[i];
            ll per = j-i;
            int need=n;
            for(int k=0;k<n;++k) {
                if(a[i]*per + dif*(k-i) == per*a[k]) {
                    need--;
                }
            }
            ans = min(ans,need);
        }
    }
    cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
}