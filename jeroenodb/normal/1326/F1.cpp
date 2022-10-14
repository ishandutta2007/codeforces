// #pragma GCC optimize("Ofast")
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
const int N = 14, oo = 1e9, M = 1<<N;
bool g[N+1][N];
vector<ll> dp[M][N];
vi f[N+1];
ll ans[M];
int path=0,n;
int d;
void solve(int msk, int last) {
    if(!dp[msk][last].empty()) 
        return;
    dp[msk][last].resize(1<<(d - (d==n)));
    if(d==0) {
        dp[msk][last][0]++;
        return;
    }
    for(int to=0;to<n;++to) if(!(msk&(1<<to))) {
        int mto = msk^1<<to;
        --d;
        solve(mto,to);
        if(g[last][to] and d!=n-1) {
            for(int i=0;i<1<<d;++i) 
                dp[msk][last][i | (1<<d)]+=dp[mto][to][i];
        } else {
            for(int i=0;i<1<<d;++i) 
                dp[msk][last][i]+=dp[mto][to][i];
        }
        ++d;
    }
}
int main() {
    cin >> n;
    for(int i=0;i<n;++i) {
        string s; cin >> s;
        for(int j=0;j<n;++j) g[i][j]=s[j]=='1';
    }
    d=n;
    solve(0,0);
    for(int i=0;i<1<<(n-1);++i) cout << dp[0][0][i] << ' ';
}