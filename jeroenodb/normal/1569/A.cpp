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
    for(int i=0;i<n;++i) {
        for(int j=2;j<=n-i;j+=2) {
            auto t = s.substr(i,j);
            
            if(count(all(t),'a') == j/2) {
                cout << i+1 << ' ' << i+j << '\n';
                return;
            }
        }
    }
    cout << "-1 -1\n";
}
int main() {
    int t; cin >> t;
    while(t--) {
        solve();
    }
}