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

const int MAXN = 505;

int a[MAXN];
int dp[MAXN][MAXN];
int bio[MAXN][MAXN];
int koji[MAXN][MAXN];

int calc(int l, int r) {
  if(l == r) {
    koji[l][r] = a[l];
    return 1;
  }
  if(bio[l][r]) return dp[l][r];
  bio[l][r] = 1;
  int ret = r - l + 1;
  FOR(i, l, r) {
    ret = min(ret, calc(l, i) + calc(i+1, r));
    if(calc(l, i) == 1 && calc(i+1, r) == 1) {
      if(koji[l][i] == koji[i+1][r]) {
        koji[l][r] = koji[l][i] + 1;
        ret = 1;
      }
    }
  }
  return dp[l][r] = ret;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int n; cin >> n;
  REP(i, n) {
    cin >> a[i];
  }

  cout << calc(0, n - 1) << endl;
}