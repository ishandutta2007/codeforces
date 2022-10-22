#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<
#define pb push_back
#define fi first
#define se second

typedef double lf;
typedef long long ll;
typedef pair<int, int> pii;

const int mod = 998244353;
int add(int x, int y) {x += y; if(x >= mod) return x - mod; return x;}
int sub(int x, int y) {x -= y; if(x < 0) return x + mod; return x;}
int mul(int x, int y) {return (ll) x * y % mod;}

const int SQRT = 250, MAXN = 2e5 + 5, B = 450, ADD = 1e5 + 1;

int V[250][MAXN];
vector<int> pos[MAXN];

int n, k;

int sol[SQRT];
int delta[SQRT];
int dp[MAXN];
int org[MAXN];

int Add(int l, int r) {
  int L = l, R = r;
  r = (r / B) * B - 1;
  for(int i = r / B; i > l / B; --i) {
    sol[i] = sub(sol[i], V[i][k - delta[i] + ADD]);
    delta[i] ++;
    r = (r / B) * B - 1;
  }

  int block = l / B;
  for(int j = l; j <= r; ++j) {
    if(org[j] + delta[block] == k) {
      sol[block] = sub(sol[block], dp[j - 1]);
    }
    V[block][org[j] + ADD] = sub(V[block][org[j] + ADD], dp[j - 1]);
    org[j] ++;
    V[block][org[j] + ADD] = add(V[block][org[j] + ADD], dp[j - 1]);
  }

  block = R / B;
  for(int j = max(l, (R / B) * B); j <= R; ++j) {
    if(org[j] + delta[block] == k) {
      sol[block] = sub(sol[block], dp[j - 1]);
    }
    V[block][org[j] + ADD] = sub(V[block][org[j] + ADD], dp[j - 1]);
    org[j] ++;
    V[block][org[j] + ADD] = add(V[block][org[j] + ADD], dp[j - 1]);
  }
}
int Del(int l, int r) {

  int L = l, R = r;
  r = (r / B) * B - 1;
  for(int i = r / B; i > l / B; --i) {
    sol[i] = add(sol[i], V[i][k + 1 - delta[i] + ADD]);
    delta[i] --;
    r = (r / B) * B - 1;
  }

  int block = l / B;
  for(int j = l; j <= r; ++j) {

    if(org[j] + delta[block] == k + 1) {
      sol[block] = add(sol[block], dp[j - 1]);
    }
    V[block][org[j] + ADD] = sub(V[block][org[j] + ADD], dp[j - 1]);
    org[j] --;
    V[block][org[j] + ADD] = add(V[block][org[j] + ADD], dp[j - 1]);
  }

  block = R / B;
  for(int j = max(l, (R / B) * B); j <= R; ++j) {
    if(org[j] + delta[block] == k + 1) {
      sol[block] = add(sol[block], dp[j - 1]);
    }
    V[block][org[j] + ADD] = sub(V[block][org[j] + ADD], dp[j - 1]);
    org[j] --;
    V[block][org[j] + ADD] = add(V[block][org[j] + ADD], dp[j - 1]);
  }
}

int a[MAXN];

void solve(int i) {

  sol[i / B] = add(sol[i / B], dp[i - 1]);
  V[i / B][-delta[i / B] + ADD] = add(V[i / B][-delta[i / B] + ADD], dp[i - 1]);

  Add(pos[a[i]].back() + 1, i);
  if(pos[a[i]].size() > 1) {
    Del(pos[a[i]][pos[a[i]].size() - 2] + 1, pos[a[i]].back());
  }
  pos[a[i]].pb(i);

  for(int j = 0; j * B <= i + B; ++j) dp[i] = add(dp[i], sol[j]);
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  cin >> n >> k;

  REP(i, n + 3) {
    pos[i].pb(0);
  }

  dp[0] = 1;

  REP(i, n) {
    cin >> a[i + 1];
    solve(i + 1);
  }

  cout << dp[n];
}