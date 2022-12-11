#include <bits/stdc++.h>
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
using ll = long long;
const int N = 5e5 + 10;
int n, a[N];
ll ans;
priority_queue<int> q;
int main() {
  scanf("%d", &n);
  rep(i, 1, n) {
    scanf("%d", a + i);
    // a[i] -= i;
    if(q.size() && a[i] <= q.top()) {
      ans += q.top() - a[i]; q.pop();
      q.push(a[i]); q.push(a[i]);
    } else {
      q.push(a[i]);
    }
  }
  printf("%lld\n", ans);
  return 0;
}