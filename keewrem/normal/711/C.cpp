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
const ll MOD =   1000000007;//   998244353;

void solve(){
    int N,M,K;
    cin >> N >> M >> K;
    vi c(N); for(int &i: c)cin >> i;
    ll cs[N][M+1];
    FOR(i,N)FOR(j,M)cin >> cs[i][j+1];
    const ll inf = MOD*MOD;
    ll dp[N][M+1][K+1];
    FOR(i,N)FOR(j,M+1)FOR(k,K+1)dp[i][j][k] = inf;
    if(c[0])dp[0][c[0]][1] = 0;
    else FOR(i,M)dp[0][i+1][1] = cs[0][i+1];
    for(int i = 1; i < N; i++){
        if(c[i]){
            for(int j = 1; j <= K; j++){
                dp[i][c[i]][j] = min(dp[i][c[i]][j],dp[i-1][c[i]][j]);
                for(int q = 1; q <= M; q++){
                    if(q == c[i])continue;
                    dp[i][c[i]][j] = min(dp[i][c[i]][j],dp[i-1][q][j-1]);

                }
            }
        }else for(int f = 1; f <= M; f++){
            for(int j = 1; j <= K; j++){
                dp[i][f][j] = min(dp[i][f][j],dp[i-1][f][j]+cs[i][f]);
                for(int q = 1; q <= M; q++){
                    if(q == f)continue;
                    dp[i][f][j] = min(dp[i][f][j],dp[i-1][q][j-1]+cs[i][f]);

                }
            }
        }
    }
    /*FOR(i,N){
        for(int j = 0; j <= K; j++){
            cout << j << " ";
            FOR(k,M+1){
                cout << dp[i][k][j] << " ";
            }
            cout<< endl;
        }
    }*/
    ll m = inf;
    for(int i = 1; i <= M; i++)m = min(m,dp[N-1][i][K]);
    if(m == inf)cout << "-1\n";
    else cout << m << endl;
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