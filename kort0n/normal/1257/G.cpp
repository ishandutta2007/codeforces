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

NumberTheoreticTransform<998244353, 3> NTT;
typedef pair<ll, vector<ll>> l_v;
int N;

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    map<ll, ll> mp;
    for(int i = 0; i < N; i++) {
        ll p;
        cin >> p;
        mp[p]++;
    }
    vector<ll> v;
    for(auto now : mp) {
        v.push_back(now.second);
    }
    sort(v.begin(), v.end());
    priority_queue<l_v, vector<l_v>, greater<l_v>> que;
    for(auto now : mp) {
        vector<ll> v(now.second + 1, 1);
        que.push({now.second + 1, v});
    }
    while(true) {
        vector<ll> Poly = que.top().second;
        que.pop();
        if(que.empty()) {
            cout << Poly[N/2] << endl;
            return 0;
        }
        vector<ll> Poly2 = que.top().second;
        que.pop();
        Poly = NTT.Multiply(Poly, Poly2);
        que.push({Poly.size(), Poly});
    }
    return 0;
}