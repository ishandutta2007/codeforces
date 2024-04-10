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
void solve(vi& c) {
    int n = c.size();
    ll sm = accumulate(all(c),0LL);
    // number of 1's
    int extra=0;
    vi a(n),pref(n+1);
    while(n) {
        a[n-1] = sm/n;
        assert(a[n-1]<=n);
        extra+=pref[n];
        if(a[n-1]) {
            extra++;
            sm-=a[n-1];
            pref[n-a[n-1]]--;
        }
        sm-=c[n-1]-extra;

        n--;
    }
    n=c.size();
    for(int i=n-1;i>0;--i) {
        a[i]-=a[i-1];
    }
    cout << a << '\n';
    
    
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vi c(n); for(auto& i : c) cin >> i;
        solve(c);
    }
}