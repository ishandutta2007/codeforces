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
const int mxN = 1e5+1, oo = 2e9;
int main() {

    int t; cin >> t;
    while(t--) {
        int n,u,v; cin >> n >> u >> v;
        int prev; cin >> prev;
        int mn = oo;
        for(int i=1;i<n;++i) {
            int cur; cin >> cur;
            if(cur==prev) {
                mn = min({mn, 2*v, u+v});
            } else if(abs(cur-prev)>=2) {
                mn = 0;
            } else {
                mn = min({mn,v,u});
            }
            prev = cur;
        }
        cout << mn << '\n';
    }
}