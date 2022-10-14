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
const int MAXN = 100010;
vi adj[MAXN];
int p[MAXN];
ll dp[MAXN][2];
ll fexp(ll b, ll e){
    ll res = 1;
    for(;e;e>>=1){
        if(e&1)res = (res*b)%MOD;
        b = (b*b)%MOD;
    }
    return res;
}

// INVERSO MOLTIPLICATIVO

ll inv(ll a){
    return fexp(a,MOD-2);
}

void dfs(int n){
    ll pp = 1;
    for(auto x: adj[n]){
        dfs(x);
        pp*=dp[x][0];
        pp%=MOD;
    }
    if(p[n]){
        dp[n][0] = pp;
        dp[n][1] = pp;
    }else{
        dp[n][0] = pp;
        for(auto x: adj[n]){
            dp[n][1] += ((pp*inv(dp[x][0]))%MOD)*dp[x][1];
            dp[n][1]%=MOD;
        }
        dp[n][0] += dp[n][1];
        dp[n][0] %= MOD;
    }
}
void solve(){
    int N; cin >> N;
    int a;
    FOR(i,N-1){
        cin >> a;
        adj[a].pb(i+1);
    }
    int s = 0;
    FOR(i,N){cin >> p[i]; s+= p[i];}
    if(s == 0)while(1)cout << "Piedi" << endl;
    dfs(0);
    cout << dp[0][1] << endl;
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