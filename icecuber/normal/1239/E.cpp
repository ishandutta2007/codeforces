#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> v;
  int sum = 0;
  for (int i = 0; i < n*2; i++) {
    int a;
    cin >> a;
    v.push_back(a);
    sum += a;
  }
  sort(v.rbegin(), v.rend());
  ll ans = v.end()[-1]+v.end()[-2];
  sum -= ans;

  int na = n-1;
  int*a = new int[1<<na]();
  vector<int> b(1<<na);
  vector<short> pop(1<<na);
  for (int j = 0; j < na; j++)
    a[1<<j] = v[j], b[1<<j] = v[j+na], pop[1<<j] = 1;
  for (int i = 1; i < 1<<na; i++) {
    if (i&(i-1)) {
      int l = i&-i;
      a[i] = a[i^l]+a[l];
      b[i] = b[i^l]+b[l];
      pop[i] = pop[i^l]+1;
    }
  }

  int m = sum/2;
  vector<pair<int,int>> x[26], y[26];
  int sz[26] = {};
  for (int i = 0; i < 1<<na; i++) sz[pop[i]]++;
  for (int i = 0; i <= na; i++) {
    x[i].reserve(sz[i]);
    y[i].reserve(sz[i]);
  }
  for (int i = 0; i < 1<<na; i++) {
    x[pop[i]].emplace_back(a[i], i);
  }
  delete[]a;
  for (int i = 0; i < 1<<na; i++) {
    y[pop[i]].emplace_back(b[i], i);
  }
  for (int k = 0; k <= na; k++) {
    sort(x[k].begin(), x[k].end());
    sort(y[k].rbegin(), y[k].rend());
  }
  int best = -1;
  ll mask = -1;
  for (int k = 0; k <= na; k++) {
    int j = 0;
    for (auto p : x[na-k]) {
      while (j < y[k].size() && p.first+y[k][j].first > m) j++;
      if (j == y[k].size()) break;
      int v = p.first+y[k][j].first;
      if (v > best) {
	best = v;
	mask = (ll)y[k][j].second<<na | p.second;
	//assert(__builtin_popcountll(mask) == na);
      }
    }
  }
  assert(mask != -1);

  vector<int> take(n*2);
  take[n*2-1] = 1;
  for (int i = 0; i < n*2-2; i++)
    if (mask>>i&1) take[i] = 1;

  vector<int> top, bot;
  for (int i = 0; i < n*2; i++) {
    (take[i] ? top : bot).push_back(v[i]);
  }
  assert(top.size() == n);
  sort(top.begin(), top.end());
  sort(bot.rbegin(), bot.rend());
  for (int i = 0; i < n; i++) cout << top[i] << ' ';
  cout << endl;
  for (int i = 0; i < n; i++) cout << bot[i] << ' ';
  cout << endl;
}