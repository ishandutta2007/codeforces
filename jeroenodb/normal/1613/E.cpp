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
typedef complex<int> pt;
#define X real()
#define Y imag()
const pt dir4[] = {{1,0},{0,1},{-1,0},{0,-1}};
const pt dir8[] = {{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};
const pt hdir[] = {{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}};
int n,m;
bool inside(pt p) {
    return 0<=p.X and p.X<n and 0<=p.Y and p.Y<m;
}
void read(pt& p) {
    int a,b; cin >> a >> b;
    p = {a,b};
}
void solve() {
    cin >> n >> m;
    vector<string> g(n);
    for(auto& i : g) cin >> i;
    vvi marks(n,vi(m,4));
    queue<pt> q;

    for(int i=0;i<n;++i) {
        for(int j=0;j<m;++j) {
            if(g[i][j]=='L') marks[i][j]=0,q.push({i,j});
            else if(g[i][j]=='.') {
                for(auto d : dir4) {
                    auto to = pt{i,j}+d;
                    if(!inside(to)) marks[i][j]--;
                    else if(g[to.X][to.Y]=='#') marks[i][j]--;
                }
                if(marks[i][j]<2) marks[i][j]=2;
            }
            
        }
    }
    while(!q.empty()) {
        auto at = q.front(); q.pop();
        if(g[at.X][at.Y]!='L') {
            g[at.X][at.Y]='+';
        }
        for(auto d : dir4) {
            auto to = at+d;
            if(inside(to) and g[to.X][to.Y]!='#') {
                if(--marks[to.X][to.Y] == 1) {
                    q.push(to);
                }
            }
        }
    }
    for(auto i : g) cout << i << '\n';

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
}