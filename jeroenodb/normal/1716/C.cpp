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
const int mxN = 1e5+1, oo = 1.4e9;
void solve() {
    int n; cin >> n;
    vi v(n),w(n);
    for(auto& i : v) cin >> i,++i;
    for(auto& i : w) cin >> i,++i;
    v[0]=0;
    vi u[2] = {}; // cost of how much a u turn on the last n-i squares costs, for both parities
    for(int rep=0;rep<2;++rep) {
        auto& myv = u[rep];
        myv.resize(n+1,-oo);
        int wait=-oo, len=1;
        for(int i=n-1;i>=0;--i) {
            wait = max({wait-1,v[i],w[i]-len});
            myv[i]=wait;
            len+=2;
        }
        swap(v,w); // swap rows
    }
    int wait=0, t=0, ans = u[0][0];
    for(int i=0;i<n;++i) {
        wait = max(wait,v[i]-t++);
        wait = max(wait,w[i]-t++);
        ans = min(ans,max(wait,u[(i+1)%2][i+1]-t));
        swap(v,w);
    }
    cout << ans+n*2-1 << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
        solve();
    }
}