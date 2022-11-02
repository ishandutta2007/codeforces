#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
const int maxn = 2e5 + 5;
int a[maxn];
vector<pair<int, int>> ans;
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    ans.clear();
    int sum = 0;
    bool flg = false;
    for (int i = 0; i < n; i++) {
      int t;
      scanf("%d", &t);
      if (!flg) {
        ans.push_back({i, i});
        sum += t;
        if (t) flg = true;
      } else {
        if (!t) {
          ans.push_back({i, i});
        } else {
          if (sum + t == 0)
            ans.push_back({i, i});
          else
            ans.back().second = i;
          sum = 0;
          flg = false;
        }
      }
    }
    if (sum) {
      puts("-1");
      continue;
    }
    printf("%lu\n", ans.size());
    for (auto pr : ans) printf("%d %d\n", pr.first + 1, pr.second + 1);
    // puts("");
  }
  return 0;
}