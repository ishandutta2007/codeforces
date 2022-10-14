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
    vi deg(n);
    for(auto& i : deg) cin >> i;
    vi ord(n), ans(n);
    iota(all(ord),0);
    sort(all(ord),[&](int i, int j) {return deg[i]>deg[j];});
    vector<bool> vis(n);
    for(auto i : ord) if(!vis[i]) {
        vis[i]=1;

        int sumd=deg[i];
        int k=1;
        vi cur = {i};
        int color = i+1;
        int iters=deg[i];
        while(iters--) {
            cout << "? " << i+1 << endl;
            int to; cin >> to; --to;
            assert(to!=-2);
            if(vis[to]) {
                color = ans[to];
                break;
            } else {
                vis[to]=1;
                cur.push_back(to);
            }
            ++k;
        }
        for(auto& j : cur) ans[j]=color;
    }
    cout << "! " << ans << endl;

}
int main() {
    int t; cin >> t;
    while(t--) solve();
}