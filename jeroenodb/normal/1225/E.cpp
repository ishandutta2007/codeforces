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
const long long MOD = 1e9+7;
class mint {
public:
    int d;
    mint () {d=0;}
    mint (int _d) : d(_d){};
    mint operator+(const mint& o) const {
        long long tmp = d+o.d;
        if(tmp>=MOD) tmp-=MOD;
        return tmp;
    }
    mint operator-(const mint& o) const {
        long long tmp = d-o.d;
        if(tmp<0) tmp+=MOD;
        return tmp;
    }
};
mint& operator+=(mint& a, const mint& o) {
    a.d+=o.d;
    if(a.d>=MOD) a.d-=MOD;
    return a;
}
const int mxN = 2e3+2, oo = 1e9;
int rowpref[mxN][mxN],colpref[mxN][mxN];
mint dp1[mxN][mxN], dp2[mxN][mxN];
int main() {
    int n,m; cin >> n >> m;
    vector<string> grid(n);
    for(auto& s : grid) cin >> s;
    for(int i=n-1;i>=0;--i) {
        for(int j=m-1;j>=0;--j) {
            if(i!=n-1) {
                rowpref[i][j]+=rowpref[i+1][j];
                if(grid[i+1][j] == 'R') rowpref[i][j]++;
            }
            if(j!=m-1) {
                colpref[i][j]+=colpref[i][j+1];
                if(grid[i][j+1] == 'R') colpref[i][j]++;
            }
        }
    }
    if(n==1 and m==1) {
        cout << "1\n";
        exit(0);
    }
    dp1[0][0] = 0;
    dp2[0][0] = 0;
    for(int i=0;i<n;++i) {
        for(int j=0;j<m;++j) {
            if(i!=n-1) {
                int d = n-i-rowpref[i][j];
                mint cur = dp2[i][j] + (i==0 and j==0);
                dp1[i+1][j]+=cur+dp1[i][j];
                dp1[i+d][j]=dp1[i+d][j]-cur;
            }
            // go right
            if(j!=m-1) {
                int d = m-j-colpref[i][j];
                mint cur = dp1[i][j] + (i==0 and j==0);
                dp2[i][j+1]+=cur+dp2[i][j];
                dp2[i][j+d]=dp2[i][j+d]-cur;
            }
        }
    }
    cout << (dp1[n-1][m-1]+dp2[n-1][m-1]).d << '\n';

}