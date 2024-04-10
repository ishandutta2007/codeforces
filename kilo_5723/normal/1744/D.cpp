#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
vector<int> arr;
int cntz(int n) { return n & 1 ? 0 : 1 + cntz(n >> 1); }
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n, m;
    scanf("%d", &n);
    m = n;
    arr.clear();
    for (int i = 0; i < n; i++) {
      int t;
      scanf("%d", &t);
      m -= cntz(t);
      arr.push_back(cntz(i + 1));
    }
    sort(arr.begin(), arr.end());
    int ans = 0;
    while (m > 0 && arr.size()) {
      m -= arr.back();
      arr.pop_back();
      ans++;
    }
    printf("%d\n", m > 0 ? -1 : ans);
  }
  return 0;
}