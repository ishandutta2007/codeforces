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
bool isPW(ll n) {
    ll pw=1;
    while(pw<n) pw*=2;
    return pw==n;
}
typedef __int128_t Int;


using ull = uint64_t;
using uInt = __uint128_t;

void solve() {
    ll n; cin >> n;
    ll o = n;
    if(o%2==1) {
        cout << "2\n";
        return;
    }
    while(o%2==0) o/=2;
    ll tryk = 2*n/o;
    if(uInt(tryk)*(tryk+1)/2 <=n) {
        cout << tryk << '\n';
        return;
    }
    if(o!=1 and uInt(o)*(o+1)/2 <=n) {
        cout << o << '\n';
        return;
    }
    cout << "-1\n";
    
}
int main() {
    int t; cin >> t;
    while(t--) {
        solve();

    }
}