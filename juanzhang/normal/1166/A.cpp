#include <bits/stdc++.h>
using namespace std;

int n, cnt[26];
string str;

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    cin >> str;
    cnt[str[0] - 'a']++;
  }
  int ans = 0;
  for (int i = 0; i < 26; i++) {
    int x = cnt[i];
    ans += (x / 2) * (x / 2 - 1) / 2 + (x - x / 2) * (x - x / 2 - 1) / 2;
  }
  printf("%d", ans);
  return 0;
}