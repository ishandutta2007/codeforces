#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

int h[100];

int solve(int n, int k) {
  std::vector<int> v;
  // Only h[v[i]] are correct, h[v[i]] strictly decreasing
  v.push_back(0);
  for (int i = 1; i < n; i++) {
    while (!v.empty() && h[v.back()] <= h[i]) {
      int l, h2;
      if (v.size() == 1) {
        // Increase h[0:i] from h[v[0]] to h[i].
        l = 0;
        h2 = h[i];
      } else {
        // Increase h[v[-2]+1:i] from h[v[-1]] to MIN(h[i], h[v[-2]]).
        l = v[v.size() - 2] + 1;
        h2 = std::min(h[i], h[l - 1]);
      }

      int prod = (i - l) * (h2 - h[v.back()]);
      if (k <= prod)
        return i - (k - 1) % (i - l);
      k -= prod;

      v.pop_back();
    }

    v.push_back(i);
  }

  return -1;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k;
    scanf("%d%d", &n, &k);
    
    for (int i = 0; i < n; i++)
      scanf("%d", h + i);

    printf("%d\n", solve(n, k));
  }
}