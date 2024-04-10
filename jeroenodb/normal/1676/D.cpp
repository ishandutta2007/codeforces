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
const pt dir8[] = {{1,1},{-1,1},{-1,-1},{1,-1}};
const pt hdir[] = {{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}};
int n,m;
bool inside(pt p) {
    return 0<=p.X and p.X<n and 0<=p.Y and p.Y<m;
}
void read(pt& p) {
    int a,b; cin >> a >> b;
    p = {a,b};
}
int main() {
    int t; cin >> t;
    while(t--) {
         cin >> n;
         cin >> m;
        vvi a(n,vi(m));
        for(auto& v : a) for(auto& j : v) cin >> j;
        ll best = 0;
        for(int i=0;i<n;++i) {

            for(int j=0;j<m;++j) {
                ll ans = a[i][j];
                for(auto dv : dir8) {
                    auto at = dv+pt({i,j});
                    while(inside(at)) {
                        ans+=a[at.X][at.Y];
                        at+=dv;
                    }
                }
                best = max(best,ans);
            }
        }
        cout << best << '\n';
    }
}