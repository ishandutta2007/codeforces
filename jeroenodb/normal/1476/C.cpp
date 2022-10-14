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
const int mxN = 1e5+1;
const ll oo = 1e18;
int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vi c(n); for(int& i: c) cin >> i;
        vi a(n); for(int& i: a) cin >> i;
        vi b(n); for(int& i: b) cin >> i;
        ll ans = 0;
        ll best = -oo;
        for(int i=1;i<n;++i) {
            if(b[i] < a[i]) {
                swap(a[i],b[i]);
            }
            if(a[i]==b[i]) {
                best = -oo;
            }
            auto tmp = 2 + best+ a[i]-1 + c[i-1]-b[i];
            ans = max(ans,c[i]-1 + tmp);
            ans = max(ans, 2LL+ b[i]-a[i] +c[i]-1);
            if(i<n-1) {
                best = max(tmp, abs(a[i]-b[i])+2LL);
            }
        }
        cout << ans << endl;
    }
 }