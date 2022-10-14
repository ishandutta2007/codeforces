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
int h,w;
bool inside(pt p) {
    return 0<=p.X and p.X<h and 0<=p.Y and p.Y<w;
}
int main() {
    int t; cin >> t;
    while(t--) {
         cin >> h >> w;
        // always put in corners
        vvi g(h, vi(w));
        g[0][0]=g.back()[0] = g[0].back() = g.back().back() = 1;
        for(int i=2;i<w-2;i+=2) {
            g[0][i]=g.back()[i] = 1;
        }
        for(int i=2;i<h-2;i+=2) {
            g[i][0]=g[i].back() = 1;
        }
        for(auto& v : g) { 
            for(int i : v) cout << i;
            cout << '\n';
        }
        cout << '\n';
    }
}