#include <bits/stdc++.h>

using namespace std;

const int N = 123;
int a[N];
int b[N];
int cnt[N];

int main() {
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
    a[i]--;
  }
  for (int i = 0; i < m; i++) {
    scanf("%d", b + i);
  }
  for (int i = 0; i < n; i++) {
    memset(cnt, 0, sizeof(cnt));
    for (int j = i; j < n; j++) {
      cnt[a[j]]++;
      bool ok = true;
      for (int q = 0; q < m; q++) {
        if (cnt[q] != b[q]) {
          ok = false;
          break;
        }
      }
      if (ok) {
        puts("YES");
        return 0;
      }
    }
  }
  puts("NO");
  return 0;  
}