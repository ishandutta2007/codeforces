#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 610;

int mat[MAXN][MAXN];
int h, w;

ll sq(ll x) {
  return x * x;
}

ll slicno(int r1, int r2) {
  ll sol = 0;
  for (int i = 0; i < w; i++) {
    sol += sq(mat[r1][i] - mat[r2][i]);
  }
  return sol;
}

int main() {
  int q;
  scanf("%d", &q);
  while(q--) {
    scanf("%d%d", &h, &w);
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        scanf("%d", &mat[i][j]);
      }
    }
    ll tmp1 = slicno(0, h-1);
    ll tmp2 = slicno(h/2-1, h/2);
    if (tmp1 < tmp2) printf("YES\n"); else printf("NO\n");
  }



  return 0;
}