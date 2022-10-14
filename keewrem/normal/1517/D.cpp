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
const int MAXN = 510;
vector<array<int,3>> adj[MAXN][MAXN];
int dp[510][510][30];
void solve(){
    int N,M,K; cin >> N >> M >> K;
    int a;
    FOR(i,N){
        FOR(j,M-1){
            cin >> a;
            adj[i][j].pb({i,j+1,a});
            adj[i][j+1].pb({i,j,a});
        }
    }
    FOR(i,N-1){
        FOR(j,M){
            cin >> a;
            adj[i][j].pb({i+1,j,a});
            adj[i+1][j].pb({i,j,a});
        }
    }
    FOR(i,N)FOR(j,M)for(int q = 1; q < 30; q++)dp[i][j][q] = 1000000007;
    for(int k = 1; k < 20; k++)FOR(i,N)FOR(j,M){
        for(auto x: adj[i][j])dp[i][j][k] = min(dp[i][j][k],dp[x[0]][x[1]][k-1]+x[2]);
    }

    FOR(i,N)FOR(j,M){
        if(K%2)cout << -1;
        else cout << 2*dp[i][j][K/2];
        cout << " \n"[j == M-1];
    }
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