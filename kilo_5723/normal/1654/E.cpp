#include <cstdio>
#include <iostream>
#include <unordered_map>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5, lef = 50, rig = 2000;
int a[maxn];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  int ans = 1;
  for (int i = 0; i < n; i++) {
    unordered_map<int, int> mp;
    for (int j = i + 1; j < n && j - i < rig; j++)
      if ((a[j] - a[i]) % (j - i) == 0) mp[(a[j] - a[i]) / (j - i)]++;
    for (auto pr : mp) ans = max(ans, pr.second + 1);
  }
  for (ll g = -lef; g < lef; g++) {
    unordered_map<ll, int> mp;
    for (int i = 0; i < n; i++) mp[a[i] + g * i]++;
    for (auto pr : mp) ans = max(ans, pr.second);
  }
  printf("%d\n", n - ans);
  return 0;
}