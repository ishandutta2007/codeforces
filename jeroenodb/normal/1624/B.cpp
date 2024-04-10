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
    ll a,b,c; cin >> a >> b >> c;
    auto cc = 2*b-a;
    if(cc>0 and cc%c==0) return true;
    auto aa = b-c+b;
    if(aa>0 and aa%a==0) return true;
    auto res = a+c;
    if(res%(b*2)==0) return true;
    return false;
}
int main() {
    int t; cin >> t;
    while(t--) {
        auto tmp = solve();
        if(tmp) cout << "YES\n";
        else cout << "NO\n";
    }
}