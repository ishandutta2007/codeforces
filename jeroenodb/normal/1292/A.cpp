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
const int mxN = 1e5+3, oo = 1e9;
bitset<mxN> g[4];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q; cin >> n >> q;
    int bad=0;
    for(int i=0;i<q;++i) {
        int r,c; cin >> r >> c,r--;
        if(g[r][c]) {
            bad-=g[r^1][c-1]+g[r^1][c]+g[r^1][c+1];
        } else {
            bad+=g[r^1][c-1]+g[r^1][c]+g[r^1][c+1];
        }
        g[r].flip(c);
        cout << (bad==0?"Yes\n":"No\n");
    }
}