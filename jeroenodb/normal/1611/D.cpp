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
    vi b(n),p(n),rnk(n);
    for(int i=0;i<n;++i) {
        cin >> b[i],--b[i];
    }
    for(auto& i : p) cin >> i,--i;
    for(int i=0;i<n;++i) rnk[p[i]] = i;
    vi w(n);
    for(int i=0;i<n;++i) {
        w[i] = rnk[i]-rnk[b[i]];
    }
    if(*min_element(all(w))<0) {
        cout << "-1\n";
    } else {
        cout << w << '\n';
    }
}
int main() {
    int t; cin >> t;
    while(t--) solve();

}