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
    sort(all(a));
    if(a[0]==0) {
        if(binary_search(all(a),1)) {
            cout << "NO\n";
        } else cout << "YES\n";
        return;
    }
    if(a[0]!=1) {
        cout << "YES\n";
        return;
    }
    for(int i=0;i<n-1;++i) {
        if(a[i]==a[i+1]-1) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}
int main() {
    int t; cin >> t;
    while(t--) {
        solve();
    }
}