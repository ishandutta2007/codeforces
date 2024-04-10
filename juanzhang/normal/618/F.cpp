#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; ++i)
#define per(i, a, b) for (int i = (a), i##end = (b); i >= i##end; --i)

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

typedef long long ll;
const int maxn = 1e6 + 10;
ll s1[maxn], s2[maxn];
int n, a[maxn], b[maxn], mp[maxn], pos[maxn];

int main() {
  bool SWP = 0;
  scanf("%d", &n);
  rep(i, 1, n) scanf("%d", a + i), s1[i] = s1[i - 1] + a[i];
  rep(i, 1, n) scanf("%d", b + i), s2[i] = s2[i - 1] + b[i];
  if (s1[n] < s2[n]) {
    SWP = 1, swap(a, b), swap(s1, s2);
  }
  vector <int> ans1, ans2;
  for (int i = 1, j = 0; i <= n; i++) {
    while (j < n && s1[i] >= s2[j + 1]) j++;
    pos[i] = j;
    int val = s1[i] - s2[j];
    if (!val || mp[val]) {
      rep(k, mp[val] + 1, i) ans1.push_back(k);
      rep(k, pos[mp[val]] + 1, j) ans2.push_back(k);
      break;
    }
    mp[val] = i;
  }
  if (SWP) {
    swap(ans1, ans2);
  }
  printf("%d\n", (int) ans1.size());
  for (int x : ans1) printf("%d ", x); putchar(10);
  printf("%d\n", (int) ans2.size());
  for (int x : ans2) printf("%d ", x); putchar(10);
  return 0;
}