#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;
const int N = 3e5 + 5;

int n, s1, s2;
pair <int, int> a[N];
LL Max[N];
int id[N];
int sta[N], top, st[N], lp = 1;

inline LL calc(int l, int r) {
  return 1LL * (r - l + 1) * a[l].first;
}

int main() {
  scanf("%d%d%d", &n, &s1, &s2);
  for (int i = 1; i <= n; i ++) {
    scanf("%d", &a[i].first);
    a[i].second = i;
  }
  sort(a + 1, a + n + 1);
  for (int i = n; i >= 1; i --) {
    Max[i] = 1LL * (n - i + 1) * a[i].first;
    if (Max[i] > Max[i + 1]) id[i] = i;
    else {
      Max[i] = Max[i + 1];
      id[i] = id[i + 1];
    }
  }
  LL v1, v2;
  top = 1;
  for (int i = 1; i < n; i ++) {
    while (top && calc(sta[top], max(i, st[top])) <= calc(i, max(i, st[top]))) top --;
    if (!top) {
      sta[++ top] = i;
      st[top] = i;
    }
    else if (calc(sta[top], n - 1) < calc(i, n - 1)) {
      int L = i, R = n - 1, mid = 0;
      while (L <= R) {
        mid = (L + R) >> 1;
        if (calc(sta[top], mid) < calc(i, mid)) R = mid - 1, st[top + 1] = mid;
        else L = mid + 1;
      }
      sta[++ top] = i;
    }
    while (lp < top && st[lp + 1] <= i) lp ++;
    v1 = calc(sta[lp], i);
    v2 = Max[i + 1];
    // cerr << sta[lp] << " " << st[lp] << " " << v1 << endl;
    if (v1 >= s1 && v2 >= s2) {
      puts("Yes");
      printf("%d %d\n", i - sta[lp] + 1, n - id[i + 1] + 1);
      for (int j = sta[lp]; j <= i; j ++) printf("%d ", a[j].second);
      puts("");
      for (int j = id[i + 1]; j <= n; j ++) printf("%d ", a[j].second);
      puts("");
      return 0;
    }
    if (v1 >= s2 && v2 >= s1) {
      puts("Yes");
      printf("%d %d\n", n - id[i + 1] + 1, i - sta[lp] + 1);
      for (int j = id[i + 1]; j <= n; j ++) printf("%d ", a[j].second);
      puts("");
      for (int j = sta[lp]; j <= i; j ++) printf("%d ", a[j].second);
      puts("");
      return 0;
    }
  }
  puts("No");
  return 0;
}