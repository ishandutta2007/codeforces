#include <cstdio>
#include <cstring>
#include <iostream>
#include <set>
using namespace std;
const int maxn = 10;
int cnt[maxn];
multiset<int> st;
int f(int n) { return n ? f(n / 10) + 1 : 0; }
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    st.clear();
    for (int i = 0; i < n; i++) {
      int t;
      scanf("%d", &t);
      st.insert(t);
    }
    memset(cnt, 0, sizeof(cnt));
    int ans = 0;
    for (int i = 0; i < n; i++) {
      int t;
      scanf("%d", &t);
      if (st.count(t)) {
        st.erase(st.find(t));
      } else if (t < maxn) {
        cnt[t]--;
      } else {
        cnt[f(t)]--;
        ans++;
      }
    }
    for (auto v : st)
      if (v < maxn) {
        cnt[v]++;
      } else {
        cnt[f(v)]++;
        ans++;
      }
    for (int i = 2; i < maxn; i++) ans += abs(cnt[i]);
    printf("%d\n", ans);
  }
  return 0;
}