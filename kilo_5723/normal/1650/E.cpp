#include <cstdio>
#include <iostream>
#include <set>
using namespace std;
const int maxn = 2e5 + 5;
int a[maxn];
multiset<int> st;
int first() { return *st.begin(); }
int last() {
  auto it = st.end();
  it--;
  return *it;
}
void add(int n) { st.insert(n); }
void del(int n) { st.erase(st.find(n)); }
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n, d;
    scanf("%d%d", &n, &d);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    st.clear();
    for (int i = 1; i <= n; i++) add(a[i] - a[i - 1] - 1);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      int tail = a[n];
      if (i == n) {
        tail = a[n - 1];
        del(a[n] - a[n - 1] - 1);
      } else {
        del(a[i] - a[i - 1] - 1);
        del(a[i + 1] - a[i] - 1);
        add(a[i + 1] - a[i - 1] - 1);
      }
      ans = max(ans, min(first(), (last() - 1) / 2));
      ans = max(ans, min(first(), d-1 - tail));
      if (i == n) {
        add(a[n] - a[n - 1] - 1);
      } else {
        add(a[i] - a[i - 1] - 1);
        add(a[i + 1] - a[i] - 1);
        del(a[i + 1] - a[i - 1] - 1);
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}