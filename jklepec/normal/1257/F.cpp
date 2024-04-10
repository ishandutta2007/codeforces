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

const int MAXN = 101;

int x1[MAXN], x2[MAXN];

map<string, int> who;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int n; cin >> n;
  REP(i, n) {
    int x; cin >> x;
    x1[i] = x & ((1 << 15) - 1);
    x2[i] = x >> 15;
  }

  REP(msk, (1 << 15)) {
    int prvi = x1[0] ^ msk;
    prvi = __builtin_popcount(prvi);
    string tmp = "";
    FOR(i, 1, n) {
      int treba = x1[i] ^ msk;
      treba = __builtin_popcount(treba);
      treba = prvi - treba;
      tmp += 'A' + treba;
    }
    who[tmp] = msk + 1;
  }

  REP(msk, (1 << 15)) {
    int prvi = x2[0] ^ msk;
    prvi = __builtin_popcount(prvi);
    string tmp = "";
    FOR(i, 1, n) {
      int treba = x2[i] ^ msk;
      treba = __builtin_popcount(treba);
      treba = treba - prvi;
      tmp += 'A' + treba;
    }
    if(who[tmp]) {
      cout << who[tmp] - 1 + (msk << 15) << endl;
      return 0;
    }
  }

  cout << -1 << endl;
  return 0;

}