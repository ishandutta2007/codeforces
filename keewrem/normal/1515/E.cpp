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
ll M =   1000000007;//   998244353;
const int MAXN = 500;
ll fact[MAXN], finv[MAXN];
ll fexp(ll base, ll exp){
    ll r = 1;
    while(exp){
        if(exp&(1LL))r = (r*base)%M;
        base = (base*base)%M;
        exp >>= 1;
    }
    return r;
}
ll inv(ll a){
    return fexp(a,M-2);
}
void f_init(){
    fact[0] = 1;
    for(int i = 1; i < MAXN; i++)fact[i] = (fact[i-1]*i)%M;
    finv[MAXN-1] = inv(fact[MAXN-1]);
    for(int i = MAXN-1; i > 0; i--)finv[i-1] = (finv[i]*i)%M;
}
ll bin(ll a, ll b){
    return (((fact[a]*finv[b])%M)*finv[a-b])%M;
}
ll f[MAXN];
void solve(){
    ll N; cin >> N >> M;
    f_init();
    for(int i = 1; i < MAXN; i++){
        for(int j = 1; j <= i; j++)f[i]+=bin(i-1,j-1);
        f[i]%=M;
    }
    //ll dp[N+1][N+1][N+1]; //quanto sei, quanti messi, quanti alla fine
    ll t[N+1][N+1]; //quanto sei, quanti messi
    FOR(i,N+1)FOR(j,N+1)t[i][j]=0;
    //FOR(j,N+2)FOR(i,N+2)FOR(k,N+2)dp[i][j][k] = 0;
    //dp[1][1][1] = 1;
    t[1][1] = 1;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= i; j++){
            for(int k = 1; k < j; k++){
                t[i][j] += ((t[i-k-1][j-k]*f[k])%M)*bin(j,k);
                t[i][j]%=M;
            }
        }
        t[i][i] = f[i];
    }
    ll ans = 0;
    FOR(i,N+1)ans+=t[N][i];
    cout << ans%M << endl;
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