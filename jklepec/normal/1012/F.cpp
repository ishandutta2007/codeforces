
#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<
#define pb push_back
#define sz(x) ((int) x.size())

typedef long long ll;
typedef pair<int, int> point;

const int inf = 1e9 + 5;
const int MAXN = 23;

const int off = 1 << 23;

int n, p, dp[off], piv[off];
int s[MAXN], l[MAXN], t[MAXN];

vector<int> ind;

bool cmp(const int &A, const int &B) {
  return s[A] < s[B];
}

int type[MAXN], sol[MAXN];

void rebuild(int i, int c) {
  if(!i) return;

  type[piv[i]] = c;
  sol[piv[i]] = dp[i] - t[piv[i]];

  rebuild(i ^ (1 << piv[i]), c);
}

int main() {
  cin >> n >> p;
  REP(i, n) {
    ind.pb(i);
    cin >> s[i] >> l[i] >> t[i];
  }

  s[n] = inf;
  ind.pb(n);

  sort(ind.begin(), ind.end(), cmp);

  dp[0] = 1;

  FOR(m, 1, (1 << n)) {
    dp[m] = inf;
    REP(i, n) {
      if(!((1 << i) & m) || dp[m ^ (1 << i)] == inf) continue;

      int v = dp[m ^ (1 << i)];

      int j1 = 0, j2 = 0;

      while(v + t[i] < s[i]) {

        while(s[ind[j1]] + l[ind[j1]] - 1 < v) {
          j1 ++;
        }

        while(!((1 << ind[j2]) & m) || s[ind[j2]] + l[ind[j2]] - 1 < v) {
          if(j2 == n) break;
          j2 ++;
        }

        if(v + t[i] < s[ind[j2]] && v < s[ind[j1]]) {
          dp[m] = min(dp[m], v + t[i]);
          assert(m > 0);
          if(dp[m] == v + t[i]) {
            piv[m] = i;
          }
          break;
        }
        v = s[ind[j1]] + l[ind[j1]];
      }
    }
  }

  REP(i, (p - 1) * ((1 << n) - 1) + 1) {
    int j = ((1 << n) - 1) ^ i;

    if(max(dp[i], dp[j]) != inf) {
      cout << "YES\n";
      rebuild(i, 2);
      rebuild(j, 1);

      REP(k, n) {
        cout << type[k] _ sol[k] << endl;
      }
      return 0;
    }
  }

  cout << "NO\n";
}