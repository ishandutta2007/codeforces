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
typedef complex<short> pt;
#define X real()
#define Y imag()
const pt dir4[] = {{1,0},{0,1},{-1,0},{0,-1}};
const string names = "DRUL";

#define rep(i,n) for(int i=0;i<n;++i)

void solve() {
    int n,m; cin >> n >> m;
    vi p(n*m);
    vector<bool> black(n*m);
    rep(i,n) rep(j,m) {
        char c; cin >> c;
        black[i*m+j] = c=='0';
    }
    rep(i,n) rep(j,m) {
        char c; cin >> c;
        auto d = dir4[names.find(c)];
        int at = i*m+j;
        int to = at + d.X*m + d.Y;
        p[at]=to;
    }
    n=n*m;
    for(int i=1;1<<i < 2*n;++i) {
        vi nw(n);
        rep(j,n) nw[j] = p[p[j]];
        swap(p,nw);
    }
    vector<bool> res(n), res2(n);
    rep(i,n) {
        res[p[i]] = true;
        res2[p[i]] = black[i] or res2[p[i]];
    }
    cout << count(all(res),1) << ' ' << count(all(res2),1) << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
        solve();
    }
}