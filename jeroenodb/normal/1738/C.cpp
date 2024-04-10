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
bool dp[2][101][101][2] = {};
void solve() {
    int n; cin >> n;
    vi a(n);
    for(auto& i : a) cin >> i,i = ((i%2)+2)%2;
    int c[2] = {count(all(a),0),count(all(a),1)};
    // 0's are useless moves...
    // 1's are game changers.
    // dp
    cout << (dp[0][c[0]][c[1]][0]?"Alice\n":"Bob\n");
}
int main() {
    auto op = [&](bool& at, bool to) {
        if(!to) at=1;
    };
     for(int i=0;i<=100;++i) for(int j=0;j<=100;++j) for(int mv=0;mv<2;++mv) for(int par=0;par<2;++par) {
        auto& cur = dp[mv][i][j][par];
        if(i==0 and j==0) cur=(!par) ^ mv;
        else {
            if(i) op(cur, dp[!mv][i-1][j][par]);
            if(j) op(cur, dp[!mv][i][j-1][par^(!mv)]);
        }
    }
    int t; cin >> t;
    while(t--) solve();
}