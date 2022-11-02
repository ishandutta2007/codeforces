#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
vector<int> a;
int m;
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    a.resize(n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    m = 0;
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    while (a.size() > 1) {
      vector<int> b;
      for (int i = 1; i < a.size(); i++) b.push_back(a[i - 1] - a[i]);
      if (m) {
        m--;
        b.push_back(a.back());
      }
      sort(b.begin(), b.end());
      reverse(b.begin(), b.end());
      while (b.size() && b.back() == 0) {
        m++;
        b.pop_back();
      }
      a.swap(b);
      // for (auto v:a) printf("%d ",v);
      // puts("");
    }
    if (a.size())
      printf("%d\n", a.back());
    else
      puts("0");
  }
  return 0;
}