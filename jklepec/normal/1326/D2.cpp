#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<
#define pb push_back
#define fi first
#define se second
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define TRACE(x) cerr << #x << "  " << x << endl
template<typename T1, typename T2>inline void minaj(T1 &x, T2 y) { x = (x > y ? y: x);}
template<typename T1, typename T2>inline void maxaj(T1 &x, T2 y) { x = (x < y ? y: x);}

typedef double lf;
typedef long long ll;
typedef pair<int, int> pii;

struct Hash {

  vector<int> h;
  vector<int> rh;

  int b, n;

  vector<int> B;

  int mod;
  int add(int x, int y) {x += y; if(x >= mod) return x - mod; return x;}
  int sub(int x, int y) {x -= y; if(x < 0) return x + mod; return x;}
  int mul(int x, int y) {return (ll) x * y % mod;}

  void init(string s, int _mod, int _b) {
    h.clear();
    rh.clear();

    n = s.size();

    mod = _mod;
    b = _b;
    B.clear();
    B.pb(1);

    REP(i, n + 2) {
      B.pb(mul(B.back(), b));
    }

    h.pb(0);
    REP(i, n) {
      h.pb(add(mul(h.back(), b), s[i] - '0' + 5));
    }

    rh.pb(0);
    REP(i, n) {
      rh.pb(add(mul(rh.back(), b), s[n - i - 1] - '0' + 5));
    }
  }

  int has(int i, int l) {
    return sub(h[i + l], mul(B[l], h[i]));
  }
  int rhas(int i, int l) {
    return sub(rh[n - i], mul(B[l], rh[n - i - l]));
  }
  bool check(int i, int l) {
    return has(i, l) == rhas(i, l);
  }
};

void solve() {
  string s; cin >> s;

  Hash A;
  Hash B;
  Hash C;
  A.init(s, 1e9 + 7, 97);
  B.init(s, 1e9 + 9, 89);
  C.init(s, 998244353, 4556);

  int n = s.size();
  int poc = 0, kraj = n - 1;

  int sol = 0;
  while(poc < kraj && s[poc] == s[kraj]) {
    poc ++;
    kraj --;
    sol += 2;
  }

  if(A.check(0, n) && B.check(0, n) && C.check(0, n)) {
    cout << s << endl;
    return;
  }

  if(poc == kraj) {
    assert(false);
    sol ++;
    cout << s.substr(0, poc) << s.substr(kraj, n - kraj);
  } else {
    int best1 = 1;
    int best2 = 1;
    int p = poc, k = kraj;

    FOR(j, poc + 1, kraj + 1) {
      if(A.check(poc, j - poc + 1) && B.check(poc, j - poc + 1) && C.check(poc, j - poc + 1)) {
        best1 = j - poc + 1;
        p = j;
      }
    }
    for(int j = kraj - 1; j >= poc; --j) {
      if(A.check(j, kraj - j + 1) && B.check(j, kraj - j + 1) && C.check(j, kraj - j + 1)) {
        best2 = kraj - j + 1;
        k = j;
      }
    }

    if(best1 > best2) {
      cout << s.substr(0, p + 1);
      cout << s.substr(kraj + 1, n - kraj - 1);
    } else {
      cout << s.substr(0, poc);
      cout << s.substr(k, n - k);
    }
    cout << endl;
  }

}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int t; cin >> t;
  while(t --) solve();
}