#include <bits/stdc++.h>

//#define int long long

#define mp(a, b) make_pair(a, b)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

#define endl '\n'

using namespace std;
typedef long long ll;
typedef long double ld;

mt19937 mrand(random_device{}());

const double PI = acos((double) -1);
const ld eps = 1e-8;
const int inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * 1ll * inf0;
const ll mod = 1e9 + 7;
// const ll mod = 998244353;

void solve();

void scan();

signed main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);
  cout << fixed;
  cout.precision(15);
  solve();
  return 0;
}

void solve() {
  int n, m, p;
  cin >> n >> m >> p;
  vector<ll> mask(n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char c;
      cin >> c;
      mask[i] += (c - '0') * (1LL << j);
    }
  }
  ll ans = 0;
  int start = clock();
  while (clock() - start <= 2.4 * CLOCKS_PER_SEC) {
    int x = mrand() % n;
    vector<int> msk;
    for (int i = 0; i < m; i++) {
      if ((1ll << i) & mask[x])
        msk.push_back(i);
    }
    vector<int> cnt(1 << msk.size());
    for (int i = 0; i < n; i++) {
      int cur = 0;
      for (int j = 0; j < msk.size(); j++)
        if ((1ll << msk[j]) & mask[i])
          cur += (1ll << j);
      cnt[cur]++;
    }
    ll mm = 0;
    for (int i = 0; i < (1 << msk.size()); i++) {
      for (int j = (i + 1) | i; j < (1 << msk.size()); j = (j + 1) | i)
        cnt[i] += cnt[j];
      if(2 * cnt[i] >= n && __builtin_popcountll(mm) < __builtin_popcountll(i))
        mm = i;
    }
    if(__builtin_popcountll(ans) < __builtin_popcountll(mm)) {
      ans = 0;
      for(int i = 0; i < msk.size(); i++)
        if((1ll << i) & mm) {
          ans += (1ll << msk[i]);
        }
    }
  }
  for(int i = 0; i < m; i++)
    if((1ll << i) & ans)
      cout << 1;
    else
      cout << 0;
  cout << endl;
}