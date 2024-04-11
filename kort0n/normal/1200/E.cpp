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
  static constexpr uint64_t P0 = 4e9 + 7;
  static constexpr uint64_t P1 = 4e9 + 9;
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
  void add(char in) {
      h0.push_back((h0.back() * B0 + in) % P0);
      h1.push_back((h1.back() * B1 + in) % P1);
      powB0.push_back(powB0.back() * B0 % P0);
      powB1.push_back(powB1.back() * B1 % P1);
  }
  uint64_t get0(int l, int r) { return (h0[r] + (P0 - h0[l]) * powB0[r - l]) % P0; }
  uint64_t get1(int l, int r) { return (h1[r] + (P1 - h1[l]) * powB1[r - l]) % P1; }
  pair<uint64_t, uint64_t> get2(int l, int r) {
      pair<uint64_t, uint64_t> a;
      a.first = get0(l, r);
      a.second = get1(l, r);
      return a;
  }
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


int T;
int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> T;
    string ans = "";
    RollingHash rhs(ans.begin(), ans.end());
    while(T--) {
        string S;
        cin >> S;
        RollingHash now(S.begin(), S.end());
        int ok = S.size();
        int nowsize = S.size();
        int anssize = ans.size();
        chmin(ok, anssize);
        while(ok >= 1) {
            if(rhs.get2(anssize - ok, anssize) == now.get2(0, ok)) {
                break;
            } 
            ok--;
        }
        //cerr << T << " " << ok << endl;
        //ans += now.substr(nowsize() - ok, ok);
        for(int i = ok; i < nowsize; i++) {
            ans.push_back(S[i]);
            rhs.add(ans.back());
        }
    }
    cout << ans << endl;
    return 0;
}