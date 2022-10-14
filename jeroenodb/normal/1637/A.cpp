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
bool solve() {
    int n; cin >> n;
    vi a(n); for(auto& i : a) cin >> i;
    vi suf(n);
    suf[n-1] = a[n-1];
    for(int i=n-2;i>=0;--i) suf[i] = min(a[i],suf[i+1]);
    int mx=-oo;
    for(int i=0;i+1<n;++i) {
        mx = max(mx,a[i]);
        if(mx>suf[i+1]) {
            return true;
        }
    }
    return false;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
        cout << (solve()?"YES\n":"NO\n");
    }
}