#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
const int maxn = 1e5 + 5;
int a[maxn];
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    vector<int> arr;
    vector<pair<int, int>> ans;
    for (int i = n - 1; i >= 0; i--)
      if (!(a[i] - a[0] & 1)) arr.push_back(i);
    for (int i = 1; i < arr.size(); i++)
      ans.push_back({arr[i] + 1, arr[i - 1] + 1});
    for (int i = 1; i < n; i++)
      if (a[i] - a[0] & 1) ans.push_back({1, i + 1});
    printf("%lu\n", ans.size());
    for (auto pr : ans) printf("%d %d\n", pr.first, pr.second);
  }
  return 0;
}