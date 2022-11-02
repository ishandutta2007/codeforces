#include <cstdio>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
set<int> st;
vector<int> arr;
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    int cur = k, lim = n * m - 4;
    bool flg = true;
    arr.clear();
    while (k--) {
      int t;
      scanf("%d", &t);
      arr.push_back(t);
    }
    st.clear();
    for (auto t : arr) {
      st.insert(t);
      while (st.count(cur)) st.erase(cur--);
      if (st.size() > lim) {
        puts("TIDAK");
        flg = false;
        break;
      }
    }
    if (flg) puts("YA");
  }
  return 0;
}