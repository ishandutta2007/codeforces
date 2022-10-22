#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  int n, k;
  cin >> n >> k;
  int pop = 0, m = n;
  while (m) m -= m&-m, pop++;
  if (k > n || k < pop) {
    cout << "NO" << endl;
    return 0;
  }
  map<int, int> c;
  for (int j = 0; n>>j; j++)
    if (n>>j&1) c[j]++;
  int sum = c.size();
  while (sum < k) {
    auto&p = *c.rbegin();
    c[p.first-1] += 2;
    if (!--p.second)
      c.erase(p.first);
    sum++;
  }
  cout << "YES" << endl;
  for (auto p : c)
    for (int j = 0; j < p.second; j++)
      cout << (1<<p.first) << ' ';
  cout << endl;
}