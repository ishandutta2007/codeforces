#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int n;
char S[maxn], T[maxn];

int main() {
  scanf("%d %s %s", &n, S + 1, T + 1);
  int p, p1 = 1, p2 = n, ans = 0;
  while (p1 <= n && S[p1] == T[p1]) p1++;
  while (p2 >= 1 && S[p2] == T[p2]) p2--;
  if (p1 > n || p2 < 1) return puts("0"), 0;
  for (p = p1; p < p2 && S[p] == T[p + 1]; p++);
  ans += p == p2;
  for (p = p1; p < p2 && S[p + 1] == T[p]; p++);
  ans += p == p2;
  printf("%d", ans);
  return 0;
}