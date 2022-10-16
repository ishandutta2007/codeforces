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
//const ll mod = 1000000007;
template<class Z> Z rng(Z a, Z b) {
  static mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
  return uniform_int_distribution<Z>(a, b - 1)(mt);
}

struct RollingHash {
  static constexpr uint64_t P0 = 1e9 + 7;
  static constexpr uint64_t P1 = 1e9 + 9;
  static uint64_t B0;
  static uint64_t B1;
  static vector<uint64_t> powB0;
  static vector<uint64_t> powB1;
  const int n;
  vector<uint64_t> h0;
  vector<uint64_t> h1;
  template<class Itr> RollingHash(Itr first, Itr last) : n(distance(first, last)), h0(n + 1), h1(n + 1) {
    for (int i = 0; i < n; ++i, ++first) {
      h0[i + 1] = (h0[i] * B0 + *first) % P0;
      h1[i + 1] = (h1[i] * B1 + *first) % P1;
    }
    while (powB0.size() <= n) {
      powB0.push_back(powB0.back() * B0 % P0);
      powB1.push_back(powB1.back() * B1 % P1);
    }
  }
  uint64_t get0(int l, int r) { return (h0[r] + (P0 - h0[l]) * powB0[r - l]) % P0; }
  uint64_t get1(int l, int r) { return (h1[r] + (P1 - h1[l]) * powB1[r - l]) % P1; }
  bool eq(int l0, int r0, int l1, int r1) {
    return get0(l0, r0) == get0(l1, r1) and get1(l0, r0) == get1(l1, r1);
  }
  template<class Itr> static uint64_t get0(Itr first, Itr last) {
    uint64_t res = 0;
    while (first != last) {
      res = (res * B0 + *first++) % P0;
    }
    return res;
  }
  template<class Itr> static uint64_t get1(Itr first, Itr last) {
    uint64_t res = 0;
    while (first != last) {
      res = (res * B1 + *first++) % P1;
    }
    return res;
  }
};
uint64_t RollingHash::B0 = rng<unsigned>(1, RollingHash::P0);
uint64_t RollingHash::B1 = rng<unsigned>(1, RollingHash::P1);
vector<uint64_t> RollingHash::powB0{1};
vector<uint64_t> RollingHash::powB1{1};


ll beki(ll a, ll b, ll mod) {
    if(b == 0) return 1;
    ll ret = beki(a, b / 2, mod);
    ret = (ret * ret) % mod;
    if(b & 1) ret = (ret * a) % mod;
    return ret;
}
ll B0;
ll B1;
ll P0;
ll P1;
ll B0inv;
ll B1inv;
vector<ll> v;
l_l now;
map<l_l, ll> mp;
set<l_l> st;

void solve() {
    //cerr << B0 << " " << B1 << " " << P0 << " " << P1 << " " << B0inv << " " << B1inv << endl;
    ll N;
    cin >> N;
    v.clear();
    mp.clear();
    st.clear();
    mp[{0, 0}] = 1;
    now.first = 0;
    now.second = 0;
    for(int i = 1; i <= N; i++) {
        ll a;
        cin >> a;
        if(!v.empty() && v.back() == a) {
            v.pop_back();
            now.first -= a;
            now.second -= a;
            now.first = (now.first + P0) % P0;
            now.second = (now.second + P1) % P1;
            now.first = (now.first * B0inv) % P0;
            now.second = (now.second * B1inv) % P1;
            st.insert(now);
            mp[now]++;
        } else {
            v.push_back(a);
            now.first = (now.first * B0 + a) % P0;
            now.second = (now.second * B1 + a) % P1;
            st.insert(now);
            mp[now]++;
        }
    }
    ll ans = 0;
    for(auto itr = st.begin(); itr != st.end(); itr++) {
        ans += mp[*itr] * (mp[*itr] - 1) / 2;
        //cerr << (mp[*itr]) << endl;
    }
    cout << ans << endl;
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin >> Q;
    B0 = RollingHash::B0;
    B1 = RollingHash::B1;
    P0 = RollingHash::P0;
    P1 = RollingHash::P1;
    B0inv = beki(B0, P0 - 2, P0);
    B1inv = beki(B1, P1 - 2, P1);
    while(Q--) solve();
    return 0;
}