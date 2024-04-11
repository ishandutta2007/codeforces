#include <bits/stdc++.h>
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

const long double EPS = 1e-10;
const long long INF = 1e18;
const long double PI = acos(-1.0L);
const ll mod = 1000000007;
ll inv[10000100];
ll FactorialInv[10000100];
ll Factorial[10000100];
ll beki(ll a, ll b){
    b += mod;
    b %= mod;
    a %= mod;
    if(b == 0){
        return 1;
    }
    ll ans = beki(a, b / 2);
    ans = ans * ans % mod;
    if(b % 2 == 1){
        ans = ans * a % mod;
    }
    return ans;
}
void init_combination(){
    const int MAX = 10000002;
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
    ll ans = Factorial[a] * FactorialInv[b] % mod;
    ans = ans * FactorialInv[a - b] % mod;
    return ans;
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    init_combination();
    ll N, M, dust;
    cin >> N >> M >> dust >> dust;
    ll ans = 0;
    for(ll k = 0; k <= N - 2; k++) {
        ll tmp = combination(M - 1, k);
        tmp *= combination(N - 2, k);
        tmp %= mod;
        tmp *= Factorial[k];
        tmp %= mod;
        tmp *= beki(M, N - k - 2);
        tmp %= mod;
        //cerr << tmp << endl;
        /*
        tmp *= Factorial[N-1];
        tmp %= mod;
        cerr << tmp << endl;
        tmp *= FactorialInv[k+1];
        tmp %= mod;
        cerr << tmp << endl;
        */
        /*
        tmp *= beki(N, N - k - 2);
        tmp %= mod;
        tmp *= Factorial[N-k-2];
        tmp %= mod;
        tmp *= FactorialInv[N-k-2];
        tmp %= mod;
        */
        //tmp *= inv[N];
        //tmp *= inv[k+2];
        //tmp %= mod;
        /*
        tmp *= Factorial[k+2];
        tmp %= mod;
        tmp *= Factorial[k+1];
        tmp %= mod;
        tmp *= beki(N, N - k - 2);
        tmp %= mod;
        tmp *= Factorial[N-k-2];
        tmp %= mod;
        tmp *= inv[N];
        tmp %= mod;
        tmp *= FactorialInv[k+1];
        tmp %= mod;
        tmp *= FactorialInv[N-k-2];
        tmp %= mod;
        */
        tmp *= k + 2;
        tmp %= mod;
        tmp *= beki(N, N-k-2);
        tmp %= mod;
        tmp *= Factorial[N-k-2];
        tmp %= mod;
        tmp *= FactorialInv[N-k-2];
        tmp %= mod;
        tmp *= inv[N];
        tmp %= mod;
        //cerr << tmp << endl;
        ans += tmp;
        //cerr << k << " " << tmp << endl;
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}