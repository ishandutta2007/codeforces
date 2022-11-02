#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 5;
struct ele {
  ll req, gain;
};
int a[maxn];
vector<ele> solve(int a[], int n) {
  // for (int i=0;i<n;i++) printf("%d ",a[i]);
  // puts("");
  vector<ele> res;
  ll sum = 0, mnm = 0;
  for (int i = 0; i < n; i++) {
    sum += a[i];
    mnm = min(sum, mnm);
    if (sum > 0) {
      res.push_back({-mnm, sum});
      sum = mnm = 0;
      continue;
    }
  }
  res.push_back({-mnm, 0});
  return res;
}
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    auto p = solve(a + k, n - k);
    // for (auto pr:p) printf("%lld,%lld ; ",pr.req,pr.gain);
    // puts("");
    reverse(a, a + k - 1);
    auto q = solve(a, k - 1);
    // for (auto pr:q) printf("%lld,%lld ; ",pr.req,pr.gain);
    // puts("");
    reverse(p.begin(), p.end());
    reverse(q.begin(), q.end());
    ll cur = a[k - 1];
    while (true) {
      if (!p.size() || !q.size()) {
        puts("YES");
        break;
      }
      if (p.back().req <= cur) {
        cur += p.back().gain;
        p.pop_back();
        continue;
      }
      if (q.back().req <= cur) {
        cur += q.back().gain;
        q.pop_back();
        continue;
      }
      puts("NO");
      break;
    }
  }
  return 0;
}