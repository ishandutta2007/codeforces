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
    string s; cin >> s;
    int r = n/2;
    for(int i=r;i<n;++i) {
        if(s[i]=='0') {
            cout << "1 " << i+1 << " 1 " << i << '\n';
            return;
        }
    }
    if(s[n/2 - 1]=='0') {
        cout << n/2 << ' ' << n << ' ' << n/2+1 << ' ' << n << '\n';
    } else cout << n/2 << ' ' << n-1 << ' ' << n/2+1 <<  ' ' << n << '\n';
}
int main() {
    int t; cin >> t;
    while(t--) {
        solve();
    }
}