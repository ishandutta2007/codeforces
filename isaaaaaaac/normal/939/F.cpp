#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

typedef pair <int, int> pii;
typedef pair <pii, pii> ppi;
const int N = 2e5 + 5;

int n, k;
int a[N], L[300], R[300];
set <int> S[103];
priority_queue <ppi, vector <ppi>, greater <ppi> > Q;

inline void Push(int d, int s, int l, int r) {
  l = max(l, 0);
  r = min(r, n + n);
  if (l > r) return;
  set <int> :: iterator it = S[s].lower_bound(l), itt;
  if (it == S[s].end()) return;
  if ((*it) > r) return;
  for (; it != S[s].end() && (*it) <= r; it = itt) itt = it, itt ++, S[s].erase(it);
  Q.push(make_pair(make_pair(d, s), make_pair(l, r)));
}

int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= k; i ++)
    scanf("%d%d", &L[i], &R[i]);
  Q.push(make_pair(make_pair(0, 0), make_pair(0, 0)));
  for (int i = 1; i <= n + n; i ++)
    for (int j = 1; j <= k; j ++) S[j].insert(i);
  while (!Q.empty()) {
    pii x = Q.top().second;
    int d = Q.top().first.first;
    int s = Q.top().first.second;
    Q.pop();
    if (n + n == x.second) return printf("Full\n%d\n", d), 0;
    for (int i = s + 1; i <= k; i ++) {
      Push(d + 1, i, 2 * L[i] - x.second, 2 * R[i] - x.first);
      Push(d + 2, i, x.first, 2 * R[i] - (2 * L[i] - x.second));
    }
  }
  puts("Hungry");
  return 0;
}