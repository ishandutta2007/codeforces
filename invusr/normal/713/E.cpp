#include <bits/stdc++.h>
using namespace std;

using s64 = long long;

template <class T>
bool relax(T &a, T b) {
  return b > a ? a = b, true : false;
}
template <class T>
bool tense(T &a, T b) {
  return b < a ? a = b, true : false;
}

const int N = 100000;
const s64 INF = 0x3f3f3f3f3f3f3f3fll;

int n;
s64 m;
s64 id[N];

void rebuild() {
  sort(id, id + n);
  s64 k = 0, d = -1;
  for (int i = 0; i < n; ++i) {
    int j = (i + 1) % n;
    s64 l = (id[j] - id[i] + m) % m;
    if (relax(d, l)) {
      k = id[j];
    }
  }
  for (int i = 0; i < n; ++i) {
    id[i] = (id[i] - k + m) % m;
  }
  sort(id, id + n);
}

s64 dist[N];

bool check(s64 d, int s) {
  fill(dist, dist + n, -INF);
  dist[s] = id[s];
  for (int i = 0; i < s; ++i) {
    relax(dist[s], id[i] + d);
  }
  for (int i = s + 1; i < n; ++i) {
    s64 l = dist[i - 1];
    if (l >= id[i] - 1) {
      relax(dist[i], max(l, id[i] + d));
    }
    if (l >= id[i] - 1 - d) {
      relax(dist[i], id[i]);
    }
    if (i < n - 1 && l >= id[i + 1] - 1 - d) {
      relax(dist[i + 1], id[i] + d);
    }
  }
  return dist[n - 1] + d - id[s] + 1 >= m;
}

int main() {
  scanf("%lld%d", &m, &n);
  for (int i = 0; i < n; ++i) {
    scanf("%lld", &id[i]);
  }
  rebuild();

  if (n == 1) {
    printf("%lld\n", m - 1);
    return 0;
  }
  if (n == m) {
    printf("0\n");
    return 0;
  }

  s64 l = 0, r = m - 1;
  while (l <= r) {
    s64 mid = l + r >> 1;
    if (check(mid, 0) || check(mid, 1)) {
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  printf("%lld\n", l);

  return 0;
}