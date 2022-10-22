#include <bits/stdc++.h>
using namespace std;

const int maxn = 505;
bool flg[maxn];
int n, a[maxn];

vector <int> v1, v2;

int find() {
  for (int i = 1; i <= n; i++) {
    if (flg[i] && a[i] > 0) return i;
  }
  return -1;
}

void print(int u, int v) {
  printf("%d %d\n", u, v), a[u]--, a[v]--;
}

int main() {
  int s = 0;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i), s += a[i];
    if (a[i] == 1) {
      v1.push_back(i);
    } else {
      v2.push_back(i), flg[i] = 1;
    }
  }
  if (s < 2 * n - 2) {
    return puts("NO"), 0;
  }
  int sz1 = v1.size(), sz2 = v2.size();
  int ans = sz2 + (sz1 > 0) + (sz1 > 1);
  printf("YES %d\n%d\n", ans - 1, n - 1);
  for (int i = 1; i < sz2; i++) {
    print(v2[i - 1], v2[i]);
  }
  if (sz1 > 0) print(v1[0], v2[0]);
  if (sz1 > 1) print(v1[1], v2[sz2 - 1]);
  for (int i = 2; i < sz1; i++) {
    print(v1[i], find());
  }
  return 0;
}