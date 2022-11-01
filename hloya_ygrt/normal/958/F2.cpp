#include <bits/stdc++.h>

using namespace std;

const int N = 323456;

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
  int good = 0, tot = 0; 
  for (int i = 0; i < m; i++) {
    scanf("%d", b + i);
    good += (b[i] == 0);
    tot += b[i];
  }
  int low = 0;
  int ans = (int) 1e9;
  for (int i = 0; i < n; i++) {
    cnt[a[i]]++;
    if (cnt[a[i]] == b[a[i]]) {
      good++;
    }
    while (cnt[a[low]] > b[a[low]]) {
      cnt[a[low]]--;
      low++;
    }
    if (good == m) {
      ans = min(ans, i - low + 1 - tot);
    }
  }
  if (ans == (int) 1e9) {
    ans = -1;
  }
  printf("%d\n", ans);
  return 0;  
}