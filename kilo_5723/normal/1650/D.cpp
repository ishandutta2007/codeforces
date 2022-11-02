#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int maxn = 1e3 + 5;
int a[maxn], b[maxn];
vector<int> ans;
void solve(int n) {
  for (int i = 0; i < n; i++)
    if (a[i] == n) {
      ans.push_back((i + 1) % n);
      for (int j = 0; j < n; j++) b[j] = a[(j + i + 1) % n];
      memcpy(a, b, sizeof(a[0]) * n);
      solve(n - 1);
      return;
    }
}
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    ans.clear();
    solve(n);
    reverse(ans.begin(), ans.end());
    for (auto v:ans) printf("%d ",v);
    puts("");
  }
  return 0;
}