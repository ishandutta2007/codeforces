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
    int n; cin >> n;
    ll hi=oo, lo=-oo;
    for(int i=0;i<n;++i) {
        int c,d; cin >> c >> d;
        if(d==1) {
            lo=max(lo,1900LL);
        } else {
            hi = min(hi,1899LL);
        }
        lo+=c;
        hi+=c;
    }
    if(lo<=hi) {
        if(hi>oo/2) cout << "Infinity\n";
        else cout << hi << '\n';
    } else {
        cout << "Impossible\n";
    }
}