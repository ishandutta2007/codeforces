#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int i, n, m, b[N], p[N], rs, st, dr, pivot, pz, mx[N];
long long currMoney;
pair<int, int> a[N];
vector<int> when[N];
multiset<int> S;

int main() {
  ios_base::sync_with_stdio(0);

  cin >> n >> m;
  for(i = 1; i <= n; ++i) cin >> a[i].first, a[i].second = i;

  sort(a + 1, a + n + 1);
  reverse(a + 1, a + n + 1);

  for(i = 1; i <= n; ++i) mx[i] = max(mx[i - 1], a[i].second);

  for(i = 1; i <= m; ++i) cin >> b[i];
  for(i = 1; i <= m; ++i) cin >> p[i];

  for(i = 1; i <= m; ++i) {
    st = 1; dr = n; pz = 0;
    while(st <= dr) {
      pivot = (st + dr) / 2;
      if(a[pivot].first >= b[i]) st = pivot + 1, pz = mx[pivot];
      else dr = pivot - 1;
    }
    when[pz].push_back(p[i]);
  }

  sort(a + 1, a + n + 1, [](pair<int, int> a, pair<int, int> b) { return a.second < b.second; });

  for(i = 1; i <= n; ++i) {
    sort(when[i].begin(), when[i].end());
    currMoney += a[i].first;
    for(auto it : when[i]) {
      if(currMoney >= it) {
        currMoney -= it;
        ++rs;
        S.insert(-it);
        continue;
      }

      if(S.size() && *S.begin() < -it) {
        currMoney -= *S.begin();
        currMoney -= it;
        S.erase(S.begin());
        S.insert(-it);
      }
    }
  }

  cout << rs << '\n';

  return 0;
}