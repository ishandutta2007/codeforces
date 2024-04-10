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
    vi a(n),b(n); 
    for(auto& i : a) cin >> i;
    for(auto& i : b) cin >> i;
    int cand=0;
    ll left=0;
    for(int i=0;i<n;++i) {
        left-=a[i];
        left+=b[i];
        left = min(left,(ll)b[i]);
        if(left<0) {
            left = 0;
            cand=i+1;
        }
    }
    cand%=n;
    left=0;
    for(int i=cand;i<n+cand;++i) {
        int j = i;
        if(j>=n) j-=n;
        left-=a[j];
        left+=b[j];
        left = min(left,(ll)b[j]);
        if(left<0) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
}