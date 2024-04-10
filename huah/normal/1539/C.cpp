#include <bits/stdc++.h>

#include <algorithm>
#include <cstdio>
#include <map>
#include <memory>
#include <queue>

using namespace std;
typedef long long ll;
#define mp(x, y) make_pair(x, y)
const int N = 2e5 + 5;
int n;
ll k, x, a[N];
int main() {
  scanf("%d%lld%lld", &n, &k, &x);
  priority_queue<ll, vector<ll>, greater<ll> > q;
  for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
  sort(a + 1, a + 1 + n);
  for (int i = 1; i < n; i++)
    if (a[i + 1] - a[i] > x) q.push(a[i + 1] - a[i] - 1);
  while (!q.empty() && q.top() / x <= k) {
    k -= q.top() / x;
    q.pop();
  }
  printf("%d\n", int(q.size()) + 1);
}