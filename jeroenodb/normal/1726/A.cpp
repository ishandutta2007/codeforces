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
    vi a(n);
    for(auto& i : a) cin >> i;
    int ans = 0;
    for(int i=0;i<n;++i) {
        ans = max(ans,a[(i+n-1)%n]-a[i]);
    }
    if(n>1) {
        ans = max(ans,*max_element(1+all(a)) - a[0]);
        ans = max(ans,a[n-1] - *min_element(all(a)-1));
    }
    cout << ans << '\n';
}
int main() {
        ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
}