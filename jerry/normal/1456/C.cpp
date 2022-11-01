#include <stdio.h>
#include <algorithm>
#include <functional>
#include <queue>

long long n, k, c[500005];

int main() {
  scanf("%lld%lld", &n, &k);
  for (int i = 0; i < n; ++i) scanf("%lld", c+i);
  std::sort(c, c+n, std::greater<long long>());
  std::priority_queue<long long> pq;
  for (int i = 0; i <= k; ++i) pq.push(0);
  long long score = 0;
  for (int i = 0; i < n; ++i) {
    long long u = pq.top();
    pq.pop();
    score += u;
    pq.push(u+c[i]);
  }
  printf("%lld\n", score);
  return 0;
}