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

const int MAXN = 15;

int n;
int e[MAXN][MAXN];
int n1, n2;

int kolko1[1 << 7][14];
int kolko2[1 << 7][14];
int kolko3[1 << 7][14];

ll sol[1 << 14];

void solve(int msk) {
  vector<int> v;
  vector<int> w;
  memset(kolko1, 0, sizeof kolko1);
  memset(kolko2, 0, sizeof kolko2);
  memset(kolko3, 0, sizeof kolko3);

  REP(i, n) {
    if((1 << i) & msk) v.pb(i);
    else w.pb(i);
  }
  do {
    int zad = v[n1 - 1];
    int what = 0;
    REP(i, n1 - 1) {
      if(e[v[i]][v[i+1]]) {
        what += (1 << i);
      }
    }
    kolko1[what][zad] ++;
  } while(next_permutation(all(v)));

  do {
    int zad = w[0];
    int what = 0;
    REP(i, n2 - 1) {
      if(e[w[i]][w[i+1]]) {
        what += (1 << i);
      }
    }
    REP(i, n) {
      if(e[i][zad]) kolko2[what][i] ++;
      else kolko3[what][i] ++;
    }

  } while(next_permutation(all(w)));

  REP(m1, (1 << (n1 - 1))) REP(i, n) {
    if(kolko1[m1][i] == 0) continue;
    if(((1 << i) & msk) == 0) continue;
    REP(m2, (1 << (n2 - 1))) {
      sol[m1 + (1 << (n1 - 1)) + (m2 << n1)] += (ll) kolko1[m1][i] * kolko2[m2][i];
      sol[m1 + (m2 << n1)] += (ll) kolko1[m1][i] * kolko3[m2][i];
    }
  }

}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  cin >> n;
  REP(i, n) REP(j, n) {
    char c; cin >> c;
    if(c == '1') e[i][j] = 1;
  }
  n1 = n / 2;
  n2 = n - n1;

  REP(msk, (1 << n)) {
    if(__builtin_popcount(msk) == n1) solve(msk);
  }

  REP(i, (1 << (n - 1))) {
    cout << sol[i] << " ";
  }
  cout << endl;

}