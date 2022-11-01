#include <bits/stdc++.h>

#include <algorithm>
#include <cstdio>
#include <map>
#include <memory>

using namespace std;
typedef long long ll;
#define mp(x, y) make_pair(x, y)
const int N = 2e5 + 5, mod = 1e9 + 7;
int n, h[N];
vector<int> ans;
int main() {
  // freopen("1.in", "r", stdin);
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &h[i]);
    sort(h + 1, h + 1 + n);
    int mn = 1e9;
    for (int i = 1; i < n; i++) mn = min(mn, h[i + 1] - h[i]);
    ans.clear();
    for (int i = 1; i < n; i++)
      if (h[i + 1] - h[i] == mn) {
        ans.push_back(h[i]);
        for (int j = i + 2; j <= n; j++) ans.push_back(h[j]);
        for (int j = 1; j < i; j++) ans.push_back(h[j]);
        ans.push_back(h[i + 1]);
        break;
      }
    for (int i = 0; i < ans.size(); i++)
      printf(i == ans.size() - 1 ? "%d\n" : "%d ", ans[i]);
  }
}