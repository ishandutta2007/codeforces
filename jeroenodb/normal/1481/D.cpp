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
    int n,m; cin >> n >> m;
    vector<string> g(n);
    for(int i=0;i<n;++i) {
        cin >> g[i];
    }
    vi ans(m);
    auto twoedges = [&](int i,int j) {
        bool f = true;
        cout << "YES\n";
        for(int k=0;k<=m;++k) {
            cout << (f?i:j)+1 << ' ';;
            f = !f;
        }
        cout << '\n';
    };
    if(m%2==1) {
        twoedges(0,1);
        return;
    }
    // Check if pair u->v and v->u have same letters
    for(int i=0;i<n;++i) {
        for(int j=i+1;j<n;++j) {
            if(g[i][j] == g[j][i]) {
                twoedges(i,j);
                return;
            }
        }
    }
    // even length and all edges have an a-b pair
    // Try 0,1,2
    if(n==2) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    char a = g[0][1], b = g[1][2], c = g[2][0];
    vi k = {1,2,3};
    if(a==b) {
        k = {3,1,2};
    } else if(a==c) {
        k = {2,3,1};
    }
    int s = (2-m/2)%3;
    if(s<0) s+=3;
    for(int i=0;i<=m;++i) {
        cout << k[(i+s)%3] << ' ';
    }
    cout << "\n";
    
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
        solve();
    }
}