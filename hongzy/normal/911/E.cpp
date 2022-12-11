#include <bits/stdc++.h>
#define pb push_back
#define debug(...) fprintf(stderr, __VA_ARGS__);
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;

const int N = 2e5 + 10;
int n, k, p[N];
stack< pair<int, int> > s;
int main() {
  scanf("%d%d", &n, &k);
  rep(i, 1, k) scanf("%d", p + i);
  s.push({1, n});
  rep(i, 1, k) {
    auto t = s.top(); s.pop();
    if(t.first <= p[i] && p[i] <= t.second) {
      if(p[i] < t.second) s.push({p[i] + 1, t.second});
      if(t.first < p[i]) s.push({t.first, p[i] - 1});
    } else {
      puts("-1");
      return 0;
    }
  }
  rep(i, 1, k) printf("%d ", p[i]);
  while(s.size()) {
    auto t = s.top(); s.pop();
    per(i, t.second, t.first) printf("%d ", i);
  }
  putchar('\n');
  return 0;
}