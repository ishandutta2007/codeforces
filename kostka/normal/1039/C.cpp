//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

#define x first
#define y second
#define SZ(x) int(x.size())
#define ll long long
#define pii pair <int, int>
#define vi vector <int>
#define ALL(x) x.begin(), x.end()

#ifdef ONLINE_JUDGE
#define FREOPEN(name) \
  freopen(name".in", "r", stdin); \
  freopen(name".out", "w", stdout);
#else
#define FREOPEN(name)
#endif

const int MAXN = 500007;
const int MOD = 1e9+7;
vi G[MAXN];
bool odw[MAXN];

int dfs(int v) {
  int ret = 1;
  odw[v] = true;
  for(auto w : G[v]) if(!odw[w]) ret += dfs(w);
  return ret;
}

int main() {
  ios_base::sync_with_stdio(0);
  int n, m, k;
  cin >> n >> m >> k;
  vector <ll> dwa(max(k+1, n+1));
  dwa[0] = 1;
  for(int i=1; i<=max(n, k); i++) {
    dwa[i] = (dwa[i-1] << 1);
    dwa[i] %= MOD;
  }
  vector <ll> X(n);
  for(int i=0; i<n; i++) cin >> X[i];
  vector <tuple <ll, int, int> > A;
  for(int i=0; i<m; i++) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    A.emplace_back(X[a] ^ X[b], a, b);
  }
  sort(ALL(A));
  ll ret = 0;
  for(int i=0; i<SZ(A); i++) {
    set <int> T;
    int a = get<1>(A[i]), b = get<2>(A[i]);
    T.insert(a);
    T.insert(b);
    G[a].push_back(b);
    G[b].push_back(a);
    while(i+1 < SZ(A) and get<0>(A[i]) == get<0>(A[i+1])) {
      i++;
      a = get<1>(A[i]);
      b = get<2>(A[i]);
      T.insert(a);
      T.insert(b);
      G[a].push_back(b);
      G[b].push_back(a);
    }
    int ile = 0;
    ll ttt = 1;
    for(auto t : T) {
      if(!odw[t]) {
        ile += dfs(t);
        ttt <<= 1;
        ttt %= MOD;
      }
    }
    for(auto t : T) {
      G[t].clear();
      odw[t] = false;
    }
    ttt = ttt * dwa[n - ile];
    ttt %= MOD;

    ret += dwa[n];
    ret %= MOD;
    ret -= ttt;
    ret %= MOD;
  }

  cout << ((dwa[k] * dwa[n] % MOD) - ret % MOD + MOD) % MOD << "\n";

  return 0;
}