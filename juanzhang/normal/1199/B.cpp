#include <bits/stdc++.h>
using namespace std;

typedef double db;
typedef long long ll;

int main() {
  ll H, L;
  scanf("%I64d %I64d", &H, &L);
  printf("%.15f", (db) (L * L - H * H) / (2 * H));
  return 0;
}