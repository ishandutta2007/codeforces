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
ll ans = oo;
auto query(int m) {
    if(m==0) return -1;
    cout << "? " <<m << endl;
    int h;cin >> h;
    if(h!=0) ans = min(ans, ll(h)*m);

    return h;
}
int main() {
    int n; cin >> n;
    int lo=1,hi=n*3000;
    while(lo<hi) {
        int mid = (hi+lo)/2;
        if(query(mid)==1) {
            hi = mid;
        } else lo = mid+1;
    }
    int sm = hi-n+1;
    debug(sm);
    for(int i=1;i<=n;++i) {
        // want h to become 2
        
        query((sm+n-i+i-1)/i);
    }
    cout << "! " << ans << endl;
}