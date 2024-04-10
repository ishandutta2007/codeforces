#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#include "bits/stdc++.h"
using namespace std;
#define all(x) begin(x),end(x)
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { string sep; for (const T &x : v) os << sep << x, sep = " "; return os; }
#define debug(a) cerr << "(" << #a << ": " << a << ")\n";
#define rep(i,n) for(int i=0;i<n;++i)
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pi;
const int mxN = 400, oo = 1e9;
bitset<mxN> ans[mxN];
bitset<mxN> table[26][mxN];
int m;
bitset<mxN> shift(const bitset<mxN>& bs, int sh) {
    return bs<<(m-sh)|bs>>sh;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n >> m;
    rep(i,n) rep(j,m) {
        char c; cin >> c;
        table[c-'a'][i][j]=true;
    }
    int r,c; cin >> r >> c;
    vector<string> p(r);
    for(auto& i : p) cin >> i;
    for(int i=0;i<n;++i) ans[i].set();
    rep(i,r) rep(j,c) {
        if(p[i][j]=='?') continue;
        int id = p[i][j]-'a';
        rep(k,n) {
            ans[k] &= shift(table[id][(k+i)%n], j%m);
        }
    }
    rep(i,n) {
        rep(j,m) cout << ans[i][j];
        cout << '\n';
    }
}