#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; ++i)
#define per(i, a, b) for (int i = (a), i##end = (b); i >= i##end; --i)

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

const int maxn = 2e5 + 10;
int n;

vector <int> vec[maxn];
priority_queue <int, vector <int>, greater <int> > Q;

void solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    vec[i].clear();
  }
  for (int i = 1; i <= n; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    vec[x].push_back(y);
  }
  while (!Q.empty()) Q.pop();
  int cnt = 0, now = n;
  long long ans = 0;
  for (int i = n - 1; i; i--) {
    for (int x : vec[i]) Q.push(x);
    now -= vec[i].size();
    while (cnt < i - now && !Q.empty()) {
      cnt++, ans += Q.top(), Q.pop();
    }
  }
  printf("%I64d\n", ans);
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) solve();
  return 0;
}