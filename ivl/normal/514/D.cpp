#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

class konst{
      public:
      int sz;
      int pot[100015];
      int pret[200015][20];
      konst(){memset(pret, 0, sizeof pret);}
      void build(int *row, int len){
           sz = len;
           pot[1] = 0;
           for (int i = 2; i <= 100010; ++i) pot[i] = 1 + pot[i / 2];
           // [x, x + 2^pot[] - 1]
           for (int i = 0; i < sz; ++i) pret[i][0] = row[i];
           for (int i = 1; i <= pot[sz]; ++i)
               for (int j = 0; j < sz; ++j)
                   pret[j][i] = max(pret[j][i - 1], pret[j + (1 << (i - 1))][i - 1]);
      }
      int query(int x, int y){
          int sz = y - x + 1;
          int p = pot[sz];
          return max(pret[x][p], pret[y - (1 << p) + 1][p]);
      }
} K[5];

int n, m, k;
int a[5][100005];
int rr[5];

bool check(int a, int b){
     int A = 0; for (int i = 0; i < m; ++i) A += K[i].query(a, b);
     return A <= k;
}

int main(){
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; ++i) for (int j = 0; j < m; ++j) scanf("%d", a[j] + i);
    for (int i = 0; i < m; ++i) K[i].build(a[i], n + 2);
    int R = 0;
    for (int i = 1; i <= n; ++i){
        if (!check(i, i)) continue;
        int lo = i, hi = n, mid = (lo + hi + 1) / 2;
        while (lo != hi){
              if (check(i, mid)) lo = mid; else hi = mid - 1;
              mid = (lo + hi + 1) / 2;
        }
        if (R >= mid - i + 1) continue;
        R = mid - i + 1;
        for (int ii = 0; ii < m; ++ii) rr[ii] = K[ii].query(i, mid);
    }
    for (int i = 0; i < m; ++i) printf("%d ", rr[i]); printf("\n");
    return 0;
}