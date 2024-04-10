#include <cstdio>

using namespace std;

const int MOD = 1000000007;
class mint{
      public:
      long long x;
      mint(long long a = 0){a %= MOD; if (a < 0) a += MOD; x = a;}
};
mint operator+(mint a, mint b){return mint(a.x + b.x);}
mint operator-(mint a, mint b){return mint(a.x - b.x);}
mint operator*(mint a, mint b){return mint(a.x * b.x);}
mint operator+=(mint &a, mint b){a = a + b;}
mint operator-=(mint &a, mint b){a = a - b;}
mint operator*=(mint &a, mint b){a = a * b;}

class matrix{
      public:
      mint M[105][105];
      matrix(){for (int i = 0; i <= 100; ++i) for (int j = 0; j <= 100; ++j) M[i][j] = 0;}
      matrix operator*(matrix X){
             matrix R;
             for (int i = 0; i <= 100; ++i)
             for (int j = 0; j <= 100; ++j)
             for (int k = 0; k <= 100; ++k)
                 R.M[i][j] += M[i][k] * X.M[k][j];
             return R;
      }
      matrix operator*=(matrix X){*this = *this * X;}
};

int n, x;
matrix M;
matrix M2;

int main(){
    for (int i = 1; i <= 100; ++i) M.M[i][i - 1] = 1; M.M[100][100] = 1;
    scanf("%d%d", &n, &x);
    for (int i = 0; i < n; ++i){
        int d; scanf("%d", &d); --d;
        M.M[99 - d][99] += 1;
    }
    for (int i = 0; i <= 100; ++i) M2.M[i][i] = 1;
    while (x){ //printf(" - %I64d\n", M2.M[99][99].x);
          if (x & 1) M2 *= M;
          M *= M;
          x >>= 1;
    }
    //for (int i = 0; i < x; ++i) M2 *= M;
    mint R = M2.M[99][99] + M2.M[100][99];
    printf("%I64d\n", R.x);
    return 0;
}