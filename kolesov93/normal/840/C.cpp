#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1000000007;
const int N = 333;

ll f[N][N];
ll fact[N];
int matrix[N][N];
int who[N];
ll C[N][N];

bool is_square(ll x) {
  ll l = 1;
  ll r = min(x, ll(1000000009));
  while (l < r) {
    ll m = (l + r + 1) >> 1;
    if (m * m > x) {
      r = m - 1;
    } else {
      l = m;
    }
  }
  return l * l == x;
}

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    who[i] = i;
  }
  for (int i = 0; i < n; ++i) {
    if (who[i] != i) continue;

    for (int j = i + 1; j < n; ++j) {
      if (who[i] != who[j] && is_square(a[i] * a[j])) {
        who[j] = who[i];
      }
    }
  }

  C[0][0] = 1;
  for (int i = 1; i <= n + 1; ++i) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; ++j) {
      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
    }
  }
  fact[0] = 1;
  for (int i = 1; i <= n + 1; ++i) {
    fact[i] = (fact[i - 1] * i) % MOD;
  }

  f[0][0] = 1;
  int all_cnt = 0;
  ll multiplier = 1;
  for (int color = 0; color < n; ++color) {
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      if (who[i] == color) {
        cnt++;
      }
    }
    //cerr << "color " << color << " has size " << cnt << endl;
    multiplier = (multiplier * fact[cnt]) % MOD;
    //cerr << "multiplier " << multiplier << endl;

    int all_places = all_cnt + 1;

    if (cnt == 0) {
      for (int bad_places = 0; bad_places <= all_places; ++bad_places) {
        f[color + 1][bad_places] = f[color][bad_places];
      }
      continue;
    }

    for (int bad_places = 0; bad_places <= all_places; ++bad_places) {

      if (f[color][bad_places] == 0) continue;
      int good_places = all_places - bad_places;

      for (int groups = 1; groups <= cnt; ++groups) {
        ll preways = (f[color][bad_places] * C[cnt - 1][groups - 1]) % MOD;
        int limit_bad_groups = min(groups, bad_places);
        for (int bad_groups = 0; bad_groups <= limit_bad_groups; ++bad_groups) {
          int good_groups = groups - bad_groups;
          if (good_groups > good_places) continue;
          //ll ways = (preways * C[groups][bad_groups]) % MOD;
          ll ways = preways;
          ways = (ways * C[bad_places][bad_groups]) % MOD;
          ways = (ways * C[good_places][good_groups]) % MOD;

          int new_bad_places = bad_places - bad_groups + cnt - groups;
          f[color + 1][new_bad_places] = (f[color + 1][new_bad_places] + ways) % MOD;
        }
      }
    }

    all_cnt += cnt;
  }

  for (int color = 0; color <= n; ++color) {
    for (int bad_places = 0; bad_places <= all_cnt + 1; ++bad_places) {
      //if (f[color][bad_places])
        //cerr << "f[" << color << "][" << bad_places << "] = " << f[color][bad_places] << endl;
    }
    //cerr << endl;
  }

  cout << (f[n][0] * multiplier) % MOD << endl;

  return 0;
}