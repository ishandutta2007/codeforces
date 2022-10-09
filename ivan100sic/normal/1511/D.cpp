// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n, k;
int v[26][26], w[26][26];

list<int> euler(int x) {
  list<int> a;
  while (1) {
    int y = find(v[x], v[x]+k, 1) - v[x];
    if (y == k) {
      break;
    }
    v[x][y] = 0;
    a.push_back(x);
    x = y;
  }

  if (a.empty()) {
    return a;
  }

  auto it = a.begin();
  while (it != a.end()) {
    auto l = euler(*it);
    a.splice(it, l);
    ++it;
  }
  return a;
}

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  cin >> n >> k;
  for (int i=0; i<k; i++) {
    fill(v[i], v[i]+k, 1);
  }
  auto e = euler(0);
  vector<int> v(begin(e), end(e));

  for (int i=0; i<n; i++) {
    cout << char(v[i % (k*k)] + 'a');
  }
  cout << '\n';
}