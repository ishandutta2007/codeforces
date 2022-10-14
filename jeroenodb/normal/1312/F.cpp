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
const int MX = 300;
int dp[3][MX] = {};
int mex(vi v) {
    int res=0;
    while(count(all(v),res)) ++res;
    return res;
}
void solve() {
    int n,x,y,z; cin >> n >> x >> y >> z;
    for(int i=1;i<MX;++i) {
        dp[0][i] = mex({dp[0][max(0,i-x)], dp[1][max(0,i-y)],dp[2][max(0,i-z)]});
        dp[1][i] = mex({dp[0][max(0,i-x)],dp[2][max(0,i-z)]});
        dp[2][i] = mex({dp[0][max(0,i-x)], dp[1][max(0,i-y)]});
    }
    int period;
    for(period = 50;period<=100;++period) {
        // how to check if it is a period?
        // look at last period block and check with block before that
        bool good=true;
        for(int i : {0,1,2}) for(int j=0;j<period;++j) {
            if(dp[i][MX-j-1]!=dp[i][MX-j-period-1]) {
                good=false;
                break;
            }
        }
        if(good) break;
    }
    assert(period<100);
    auto get = [&](ll x, int i=0) {
        x = max(x,0LL);
        if(x<MX) return dp[i][x];
        x%=period;
        return dp[i][period+x];
    };
    vi a(n);
    map<int,int> cnt;
    int total=0;
    for(auto& i: a) {
        ll v; cin >> v;
        i = get(v);
        for(auto j : {get(v-x,0),get(v-y,1),get(v-z,2)}) cnt[i^j]++;
        total^=i;
    }
    if(total==0) {
        cout << "0\n";
    } else {
        cout << cnt[total] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
}