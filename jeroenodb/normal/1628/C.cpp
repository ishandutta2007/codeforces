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
const pt dir8[] = {{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};
const pt hdir[] = {{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}};
void read(pt& p) {
    int a,b; cin >> a >> b;
    p = {a,b};
}
vvi g;
vector<vector<bool>> f;
int n;
bool inside(pt p) {
    return 0<=p.X and p.X<n and 0<=p.Y and p.Y<n;
}
int ans;
void flip(pt p) {
    for(auto d : dir4) {
        auto at = p+d;
        if(inside(at)) {
            f[at.X][at.Y]=!f[at.X][at.Y];
        }
    }
    ans^=g[p.X][p.Y];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
        cin >> n;
        g.assign(n,vi(n));
        for(auto& c : g) for(auto& i : c) cin >> i;
        f.assign(n,vector<bool>(n));
        ans=0;
        for(int i=1;i<n;++i) {
            for(int j=0;j<n;++j) {
                if(!f[i-1][j]) flip({i,j});
            }
        }
        cout << ans << '\n';
    }
}