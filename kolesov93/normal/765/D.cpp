#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ld PI = acosl(-1.);

const int N = 1000111;
int f[N], g[N], h[N];

int main() {
  int n, m;
  scanf("%d", &n);
  set<int> q;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", f+i);
    q.insert(f[i]);
  }
  m = q.size();

  int classes = 0;
  map<int, int> element2class;
  for (int i = 1; i <= n; ++i) {
    if (f[i] == i) {
      element2class[i] = ++classes;
      h[classes] = i;
    }
  }

  if (classes != m) {
    puts("-1");
    return 0;
  }

  for (int i = 1; i <= n; ++i) {
    g[i] = element2class[f[i]];
  }

  bool cool = true;
  for (int i = 1; i <= m; ++i) {
    if (g[h[i]] != i) {
      cool = false;
      break;
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (h[g[i]] != f[i]) {
      cool = false;
      break;
    }
  }

  if (!cool) {
    puts("-1");
  }
  printf("%d\n", m);
  for (int i = 1; i <= n; ++i) {
    printf("%d ", g[i]);
  }
  puts("");
  for (int i = 1; i <= m; ++i) {
    printf("%d ", h[i]);
  }
  puts("");

  return 0;
}