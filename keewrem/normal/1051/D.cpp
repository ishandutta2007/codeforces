#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ft front()
#define bk back()
#define pb push_back
#define eb emplace_back
#define pf push_front
#define ps push
#define pc  __builtin_popcount
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define sz(x) int((x).size())
template<typename T>
using pq = priority_queue<T>;
#define FOR(i,k) for(int i = 0; i < (k); i++)
#define foll(i,k) for(long long i = 0; i < (k); i++)
#define FORr(i,k) for(int i = (k)-1; i >= 0; i--)
#define folr(i,k) for(long long i = (k)-1; i >= 0; i--)
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll MOD =     998244353;

int f[4][4] = {
    {0,1,1,1},
    {0,0,2,0},
    {0,2,0,0},
    {1,1,1,0}
};

void solve(){
    int N,K;
    cin >> N >> K;
    int dp[N][K+3][4];
    FOR(i,N)FOR(k,K+3)FOR(j,4)dp[i][k][j] = 0;
    dp[0][1][3] = dp[0][2][1] = dp[0][1][0] = dp[0][2][2] = 1;
    FOR(i,N-1)FOR(j,K+1)FOR(k,4)FOR(q,4){
        dp[i+1][j+f[k][q]][q] += dp[i][j][k];
        if(dp[i+1][j+f[k][q]][q] > MOD)dp[i+1][j+f[k][q]][q]-=MOD;
    }
    ll ans = 0;
    //FOR(i,N){FOR(j,K+1)FOR(k,4){cout << dp[i][j][k]<<" ";} cout << endl;}
    FOR(i,4)ans+=dp[N-1][K][i];
    cout << ans %MOD << "\n";
    return;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(NULL);
    int T = 1;
    //cin >> T;
    while(T--){
        solve();
    }
    return 0;
}