#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200000;
int A[MAXN], B[MAXN];

int main() {
  int kase;
  scanf("%d", &kase);
  while (kase--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
      scanf("%d", &A[i]);
    for (int i = 0; i < n; i++)
      scanf("%d", &B[i]);

    bool flag = true;
    for (int i = 0; i < n; i++) {
      if (A[i] > B[i] || (A[i] != B[i] && B[(i + 1) % n] < B[i] - 1)) {
        flag = false;
        break;
      }
    }
    puts(flag ? "YES" : "NO");
  }
  return 0;
}