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
    int n; cin >> n;
    vi a(n); for(auto& i : a) cin >> i;
    // n^2 steps?
    // loop over point which is zero
    ll ans=1e18;
    for(int i=0;i<n;++i) {
        ll last=0,cur=0;
        for(int j=i-1;j>=0;--j) {
            ll num = (last+a[j])/a[j];
            cur+=num;
            last = num*a[j];
        }
        last=0;
        for(int j=i+1;j<n;++j) {
            ll num = (last+a[j])/a[j];
            cur+=num;
            last = num*a[j];
        }
        ans = min(cur,ans);
    }
    cout << ans << '\n';

}