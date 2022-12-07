#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
  int n;
  scanf("%d", &n);
  vector<pair<int, int>> a(n), b(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i].first);
    a[i].second = i;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &b[i].first);
    b[i].second = i;
  }
  sort(begin(a), end(a));
  sort(begin(b), end(b));

  vector<int> pos(n);
  for (int i = 0; i < n; ++i) {
    pos[b[i].second] = i;
  }
  for (int i = 0; i < n; ++i) {
    printf("%d ", a[n - 1 - pos[i]].first);
  }
  puts("");

  return 0;
}