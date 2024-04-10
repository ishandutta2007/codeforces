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

int main() {
    int n; cin >> n;
    vi a(n); for(int& i : a) cin >> i;
    vvi ans(n,vi(n));
    for(int i=0;i<n;++i) {
        pt p = {i,i};
        ans[p.X][p.Y] = a[i];
        for(int j=0;j<a[i]-1;++j) {
            if(p.X!=0 and ans[p.X-1][p.Y]==0) {
                p-=1;
            } else {
                assert(p.Y!=n-1);
                assert(ans[p.X][p.Y+1]==0);
                p+=pt{0,1};
            }
            ans[p.X][p.Y] = a[i];
        }
    }
    for(int i=0;i<n;++i) {
        for(int j=0;j<=i;++j) {
            cout << ans[j][i] << ' ';
        } cout << '\n';
    }

}