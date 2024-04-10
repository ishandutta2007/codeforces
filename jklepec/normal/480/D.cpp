#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define pb push_back
#define _ << " " <<
#define sz(x) ((int) x.size())

typedef long long ll;
typedef pair<int, int> point;

//map<char, int> decode = {{'O', 0}, {'F', 1}, {'A', 2}, {'D', 3}, {'C', 4}};

const int MAXN = 505, MAXS = 1005;

int dp[MAXN][MAXS];
int pref[MAXN * 2];

int lo[MAXN], hi[MAXN], v[MAXN], w[MAXN], s[MAXN];
bool cmp(int A, int B) {
  if(hi[A] == hi[B]) return lo[A] > lo[B];
  return hi[A] < hi[B];
}

vector<int> e[MAXN * 2];
bool ok[MAXN][MAXN];

int ans[MAXN][2 * MAXN];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int n, S; cin >> n >> S;

  REP(i, n) {
    cin >> lo[i] >> hi[i] >> w[i] >> s[i] >> v[i];
  }

  lo[n] = 0; hi[n] = 2 * n;
  s[n] = S;

  n ++;

  REP(i, n) REP(j, n) {
    if(i != j && lo[i] <= lo[j] && hi[j] <= hi[i]) {
      ok[i][j] = true;
    }
  }

  vector<int> ind;
  REP(i, n) {
    ind.pb(i);
    e[hi[i]].pb(i);
  }
  sort(ind.begin(), ind.end(), cmp);



  REP(ii, n) {
    int i = ind[ii];

    FOR(j, 0, MAXS) {
      if(j) dp[i][j] = dp[i][j - 1];
      if(j - w[i] > s[i]) continue;

      if(j >= w[i]) {
        FOR(k, lo[i] + 1, hi[i] + 1) {
          if(k) ans[i][k] = ans[i][k - 1];

          for(int l: e[k]) {
            if(!ok[i][l]) continue;
            if(j >= w[i] && j - w[i] <= s[i]) ans[i][k] = max(ans[i][k], dp[l][j - w[i]] + ans[i][lo[l]]);
          }
        }

        dp[i][j] = max(dp[i][j], ans[i][hi[i]] + v[i]);
      }
    }
  }

  cout << dp[n - 1][S] << endl;
}