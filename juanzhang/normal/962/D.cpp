#include <bits/stdc++.h>
using namespace std;

#define nc getchar()
typedef long long ll;
typedef pair <ll, int> pii;
const int maxn = 1.5e5 + 10;
int n; ll a[maxn];
priority_queue <pii, vector <pii>, greater <pii> > q;

inline ll read() {
  ll x = 0; char c = nc;
  while (c < 48) c = nc;
  while (c > 47) x = x * 10 + c - 48, c = nc;
  return x;
}

int main() {
  n = read();
  for (int i = 1; i <= n; i++) {
    a[i] = read(), q.push(pii(a[i], i));
  }
  int ans = n;
  while (!q.empty()) {
    pii p1 = q.top(); q.pop();
    if (q.empty()) break;
    pii p2 = q.top(); q.pop();
    if (p1.first == p2.first) ans--, a[p1.second] = 0, a[p2.second] <<= 1;
    q.push(pii(a[p2.second], p2.second));
  }
  printf("%d\n", ans);
  for (int i = 1; i <= n; i++) {
    if (a[i]) printf("%I64d ", a[i]);
  }
  return 0;
}