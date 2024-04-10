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
const int mxN = 1e3+1, oo = 1e9;
int n,m; 
int pref[mxN][mxN], ipref[mxN][mxN];
ll big[20];
ll smsmflipped(int i, int j) {
    if(i==0 or j==0) return 0;
    if(i==1 and j==1) return 1;
    if(i<j) swap(i,j);
    int a = __lg(i);
    return (ll)j*(i-(1<<(a-1)))-smsmflipped(i-(1<<a),j);
}
int sumflipped(int i) {
    return smsmflipped(i,1);
}
bool flipped(int i, int j=0) {
    return __builtin_popcount(i^j)%2==0;
}
ll get(int x, int y) {
    int bx = x/m, by = y/n;
    // bottom part
    ll bxnor = sumflipped(bx),bynor = sumflipped(by);
    y-=by*n, x-=bx*m;
    if(!flipped(by)) bxnor=bx-bxnor;
    if(!flipped(bx)) bynor=by-bynor;
    ll res = bxnor*pref[m][y] + (bx-bxnor)*ipref[m][y];
    res+= bynor*pref[x][n] + (by-bynor)*ipref[x][n];
    if(flipped(bx,by)) {
        res+=pref[x][y];
    } else res+=ipref[x][y];
    // big part
    ll bnor = smsmflipped(bx,by);
    res+=bnor*pref[m][n] + ((ll)bx*by-bnor)*ipref[m][n];
    return res;
}
ll get(array<int,2> x, array<int,2> y) {
    x[0]-=1,y[0]-=1;
    return get(x[1],y[1])-get(x[0],y[1])-get(x[1],y[0])+get(x[0],y[0]);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q; cin >> n >> m >> q;
    for(int j=1;j<=n;++j) {
        for(int i=1;i<=m;++i) {
            char c; cin >> c;
            pref[i][j]=c-'0';
            ipref[i][j]=!pref[i][j];
        }
    }
    for(int i=1;i<=m;++i) for(int j=1;j<=n;++j) pref[i][j]+=pref[i-1][j]+pref[i][j-1]-pref[i-1][j-1];
    for(int i=1;i<=m;++i) for(int j=1;j<=n;++j) ipref[i][j]+=ipref[i-1][j]+ipref[i][j-1]-ipref[i-1][j-1];
    while(q--) {
        array<int,2> x, y;
        cin >> x[0] >> y[0] >> x[1] >> y[1];
        cout << get(y,x) << '\n';
    }
}
/*
After the second iteration, the field will be like this:

*/