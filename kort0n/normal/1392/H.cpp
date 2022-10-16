#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

const long long INF = 1e18;
const ll mod = 998244353;
vector<ll> inv, FactorialInv, Factorial;
ll beki(ll a, ll b){
    ll ret = 1 % mod;
    a %= mod;
    while(b) {
        if(b & 1LL) ret = ret * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ret;
}
void init_combination(ll MAX){
    Factorial.resize(MAX + 1);
    FactorialInv.resize(MAX + 1);
    inv.resize(MAX + 1);
    Factorial[0] = 1;
    inv[0] = 1;
    for(int i = 1; i <= MAX; i++){
        Factorial[i] = Factorial[i - 1] * i % mod;
    }
    FactorialInv[MAX] = beki(Factorial[MAX], mod - 2);
    for(ll i = MAX - 1; i >= 0; i--) {
        FactorialInv[i] = FactorialInv[i+1] * (i+1) % mod;
    }
    for(int i = 1; i <= MAX; i++) {
        inv[i] = FactorialInv[i] * Factorial[i-1] % mod;
    }
}
ll combination(ll a, ll b){
    if((a == b) || (b == 0)){
        return 1;
    }
    if(a < b) return 0;
    if(b < 0) return 0;
    ll ans = Factorial[a] * FactorialInv[b] % mod;
    ans = ans * FactorialInv[a - b] % mod;
    return ans;
}

ll dp[2050000];
ll asum = 0;
ll factsum = 0;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    init_combination(4005000);
    for(ll i = 1; i <= N; i++) {
        ll sum = 1;
        sum += (N - i) * inv[M + 1];
        /*
        for(ll j = 1; j <= i; j++) {
            ll prob = beki(combination(i + M, M), mod - 2) * combination(i+M-(j+1), M-1) % mod;
            //cerr << i << " " << j << " " << prob << endl;
            ll tmp = dp[i-j] + j;
            sum += tmp * prob % mod;
            sum %= mod;
        }
        */
        ll tmp;
        tmp = Factorial[M+i-2] * FactorialInv[i-1] % mod;
        tmp = tmp * dp[i-1] % mod;
        asum = (asum + tmp) % mod;
        factsum += Factorial[i+M-2] * FactorialInv[i-1] % mod;
        factsum %= mod;
        asum = (asum + factsum) % mod;
        //cerr << i << " " << asum << " " << factsum << endl;
        tmp = asum * FactorialInv[M-1] % mod;
        tmp = tmp * beki(combination(i + M, M), mod - 2) % mod;
        sum = (sum + tmp) % mod;
        sum %= mod;
        ll prob = beki(combination(i + M, M), mod - 2) * combination(i+M-1, M-1) % mod;
        ll loop = 1 + mod - prob;
        ll factor2 = beki(loop, mod - 2);
        dp[i] = sum;
        dp[i] *= factor2;
        dp[i] %= mod;
        //cerr << i << " " << factor2 << " " << sum << " " << dp[i] << endl;
    }
    cout << dp[N] << endl;
    return 0;
}