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
    int t; cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vi a(n),b(n);
        for(auto& i : a) cin >> i;
        for(auto& i : b) cin >> i;
        ll ans=0;
        for(int i=1;i<n;++i) {
            ans+=min(abs(a[i]-a[i-1])+abs(b[i]-b[i-1]), abs(a[i]-b[i-1])+abs(b[i]-a[i-1]));
        }
        cout << ans << '\n';
    }
}