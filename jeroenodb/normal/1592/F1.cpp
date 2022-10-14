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
const int mxN = 500+5, oo = 1e9;
bitset<mxN> g[mxN], f[mxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m; cin >> n >> m;
    for(int i=0;i<n;++i) for(int j=0;j<m;++j) {
        char c; cin >> c;
        g[i][j] = c=='B';
    }
    for(int i=n-1;i>=0;--i) {
        for(int j=m-1;j>=0;--j) {
            f[i][j] = f[i+1][j]^f[i][j+1]^f[i+1][j+1];
            if(g[i][j]^f[i][j]) {
                g[i][j]=true;
                f[i].flip(j);
            } else g[i][j]=false;
        }
    }
    int ans=0;
    for(int i=0;i<n;++i) 
        ans+=g[i].count();
    // check rectangles
    bool good=false;
    if(g[n-1][m-1]) for(int i=0;i<n-1;++i) for(int j=0;j<m-1;++j) {
        if(g[i][j] and g[n-1][j] and g[i][m-1]) {
            good=true;
        }
    }
    ans-=good;
    cout << ans << '\n';
}