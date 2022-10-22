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

const int mod = 998244353;
int add(int x, int y) {x += y; if(x >= mod) return x - mod; return x;}
int sub(int x, int y) {x -= y; if(x < 0) return x + mod; return x;}
int mul(int x, int y) {return (ll) x * y % mod;}

const int MAXN = 2e6 + 5;

int dp[MAXN];
int divi[MAXN];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  FOR(i, 2, MAXN) {
    if (i % 2 == 0) for(int j = i + i; j < MAXN; j += i)
      divi[j] ++;
  }

  int n; cin >> n;
  int sum = 1;
  REP(i, n) {
    dp[i] = sum;
    if (i) dp[i] = add(dp[i], divi[2 * i + 2]);
    sum = add(sum, dp[i]);
  }

  cout << dp[n-1] << endl;
}