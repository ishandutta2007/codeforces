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

const int mod = 1e9 + 7;
int add(int x, int y) {x += y; if(x >= mod) return x - mod; return x;}
int sub(int x, int y) {x -= y; if(x < 0) return x + mod; return x;}
int mul(int x, int y) {return (ll) x * y % mod;}
/*
struct Hash {

  vector<int> h;
  Hash(string s) {

  }
};*/

bool ispalin(string s) {
  string r = s;
  reverse(all(r));
  return r == s;
}

void solve() {
  string s; cin >> s;
  int n = s.size();
  int poc = 0, kraj = n - 1;

  int sol = 0;
  while(poc < kraj && s[poc] == s[kraj]) {
    poc ++;
    kraj --;
    sol += 2;
  }

  if(ispalin(s)) {
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
      if(ispalin(s.substr(poc, j - poc + 1))) {
        best1 = j - poc + 1;
        p = j;
      }
    }
    for(int j = kraj - 1; j >= poc; --j) {
      if(ispalin(s.substr(j, kraj - j + 1))) {
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