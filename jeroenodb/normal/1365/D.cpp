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
int n,m;
bool inside(pt p) {
    return 0<=p.X and p.X<n and 0<=p.Y and p.Y<m;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
        cin >> n >> m;
        vector<string> g(n);
        for(auto& i : g) cin >> i;
        int goods=0;
        for(int i=0;i<n;++i) {
            for(int j=0;j<m;++j) {
                if(g[i][j]=='.') {
                    pt at = {i,j};
                    for(auto d : dir4) {
                        auto to = at+d;
                        if(inside(to)) {
                            if(g[to.X][to.Y]=='B') {
                                g[i][j]='#';
                            }
                        }
                    }
                } else if(g[i][j]=='G') goods++;
            }
        }
        queue<pt> q;
        bool bad=false;
        auto check = [&](pt p) {
            if(!inside(p)) return;
            auto& c = g[p.X][p.Y];
            if(c!='#') {
                if(c=='B') bad=true;
                else if(c=='G') goods--;
                q.push(p);
                c='#';
            }
        };
        check({n-1,m-1});
        while(!q.empty()) {
            auto at = q.front(); q.pop();
            for(auto d : dir4) {
                check(at+d);
            }
        }
        if(goods==0 and !bad) cout << "Yes\n";
        else cout << "No\n";
    }
}