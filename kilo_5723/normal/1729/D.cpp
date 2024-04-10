#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;
const int maxn = 1e5 + 5;
vector<int> a, b;
int aa[maxn], bb[maxn];
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &aa[i]);
    for (int i = 0; i < n; i++) scanf("%d", &bb[i]);
    a.clear();
    b.clear();
    for (int i = 0; i < n; i++)
      if (aa[i] > bb[i])
        a.push_back(aa[i] - bb[i]);
      else
        b.push_back(bb[i] - aa[i]);
    int cnt1 = 0, cnt2 = 0;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    while (b.size()) {
      while (a.size() && a.back() > b.back()) a.pop_back();
      if (a.size()) {
        b.pop_back();
        a.pop_back();
        cnt1++;
      } else {
        cnt2++;
        b.pop_back();
      }
    }
    printf("%d\n", cnt1 + cnt2 / 2);
  }
  return 0;
}