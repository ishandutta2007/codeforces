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

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
const ll mod = 998244353;
vector<ll> dp[4000];
bool occH[4000], occW[4000];
ll N, H, W;
vector<ll> Hs, Ws;
vector<ll> validH, validW;
ll Hnum = 0;
ll Wnum = 0;
vector<ll> dpW;
vector<ll> dpH;
template< ll mod, ll primitiveroot >
struct NumberTheoreticTransform {
  vector< vector< ll > > rts, rrts;
  void ensure_base(ll N) {
    if(rts.size() >= N) return;
    rts.resize(N), rrts.resize(N);
    for(ll i = 1; i < N; i <<= 1) {
      if(rts[i].size()) continue;
      ll w = mod_pow(primitiveroot, (mod - 1) / (i * 2));
      ll rw = inverse(w);
      rts[i].resize(i), rrts[i].resize(i);
      rts[i][0] = 1, rrts[i][0] = 1;
      for(ll k = 1; k < i; k++) {
        rts[i][k] = mul(rts[i][k - 1], w);
        rrts[i][k] = mul(rrts[i][k - 1], rw);
      }
    }
  }

  inline ll mod_pow(ll x, ll n) {
    ll ret = 1;
    while(n > 0) {
      if(n & 1) ret = mul(ret, x);
      x = mul(x, x);
      n >>= 1;
    }
    return ret;
  }

  inline ll inverse(ll x) {
    return mod_pow(x, mod - 2);
  }

  inline ll add(ll x, ll y) {
    x += y;
    if(x >= mod) x -= mod;
    return x;
  }

  inline ll mul(ll a, ll b) {
    return ll(1LL * a * b % mod);
  }

  void DiscreteFourierTransform(vector< ll > &F, bool rev) {
    const ll N = (ll) F.size();
    ensure_base(N);
    for(ll i = 0, j = 1; j + 1 < N; j++) {
      for(ll k = N >> 1; k > (i ^= k); k >>= 1);
      if(i > j) swap(F[i], F[j]);
    }
    for(ll i = 1; i < N; i <<= 1) {
      for(ll j = 0; j < N; j += i * 2) {
        for(ll k = 0; k < i; k++) {
          ll s = F[j + k], t = mul(F[j + k + i], rev ? rrts[i][k] : rts[i][k]);
          F[j + k] = add(s, t), F[j + k + i] = add(s, mod - t);
        }
      }
    }
    if(rev) {
      ll temp = inverse(N);
      for(ll i = 0; i < N; i++) F[i] = mul(F[i], temp);
    }
  }

  vector< ll > Multiply(const vector< ll > &A, const vector< ll > &B) {
    ll sz = 1;
    while(sz < A.size() + B.size() - 1) sz <<= 1;
    vector< ll > F(sz), G(sz);
    for(ll i = 0; i < A.size(); i++) F[i] = A[i];
    for(ll i = 0; i < B.size(); i++) G[i] = B[i];
    DiscreteFourierTransform(F, false);
    DiscreteFourierTransform(G, false);
    for(ll i = 0; i < sz; i++) F[i] = mul(F[i], G[i]);
    DiscreteFourierTransform(F, true);
    F.resize(A.size() + B.size() - 1);
    return F;
  }
};

ll inv[10000100];
ll FactorialInv[10000100];
ll Factorial[10000100];
ll beki(ll a, ll b){
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
    dp[0].resize(1);
    dp[1].resize(1);
    dp[0][0] = 1;
    dp[1][0] = 1;
    for(ll i = 2; i <= 3700; i++) {
        dp[i].resize(i / 2 + 1);
        for(int j = 0; j < dp[i].size(); j++) {
            if(dp[i-1].size() >= j + 1) dp[i][j] += dp[i-1][j];
            if(j > 0) {
                if(dp[i-2].size() >= j) dp[i][j] += dp[i-2][j-1];
            }
            dp[i][j] %= mod;
            /*
            if(i < 30 && j < 30) {
                cerr << i << " " << j << " " << dp[i][j] << endl;
            }
            */
        }
    }
    cin >> H >> W >> N;
    for(int i = 1; i <= N; i++) {
        ll r, c;
        cin >> r >> c;
        occH[r] = true;
        occW[c] = true;
        cin >> r >> c;
        occH[r] = true;
        occW[c] = true;
    }
    validH.push_back(-1);
    validW.push_back(-1);
    for(int h = 1; h <= H; h++) {
        if(!occH[h]) validH.push_back(h);
    }
    for(int w = 1; w <= W; w++) {
        if(!occW[w]) validW.push_back(w);
    }
    for(int i = 1; i < validH.size(); i++) {
        if(validH[i] - validH[i-1] != 1) Hs.push_back(0);
        Hs.back()++;
        Hnum++;
    }
    for(int i = 1; i < validW.size(); i++) {
        if(validW[i] - validW[i-1] != 1) Ws.push_back(0);
        Ws.back()++;
        Wnum++;
    }
    dpH.push_back(1);
    dpW.push_back(1);
    NumberTheoreticTransform<mod, 3> FFT;
    for(auto val : Hs) {
        dpH = FFT.Multiply(dpH, dp[val]);
    }
    for(auto val : Ws) {
        dpW = FFT.Multiply(dpW, dp[val]);
    }
    ll ans = 0;
    for(ll oneH = 0; oneH <= 3600; oneH++) {
        for(ll twoH = 0; twoH <= 3600; twoH++) {
            ll oneW = twoH;
            ll twoW = oneH;
            if(dpH.size() <= twoH) continue;
            if(dpW.size() <= twoW) continue;
            ll restH = Hnum - twoH * 2;
            ll restW = Wnum - twoW * 2;
            if(restH < oneH) continue;
            if(restW < oneW) continue;
            ll tmp = dpH[twoH] * dpW[twoW] % mod;
            tmp *= combination(restH, oneH);
            tmp %= mod;
            tmp *= combination(restW, oneW);
            tmp %= mod;
            tmp *= Factorial[twoH];
            tmp %= mod;
            tmp *= Factorial[twoW];
            tmp %= mod;
            /*
            cerr << oneH << " " << twoH << " " << tmp << endl;
            cerr << restH << " " << restW << endl;
            cerr << dpH[twoH] << " " << dpW[twoW] << endl;
            */
            ans += tmp;
            ans %= mod;
        }
    }
    cout << ans<< endl;
    return 0;
}