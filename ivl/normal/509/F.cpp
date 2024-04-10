#include <cstdio>

using namespace std;

const long long MOD = 1000000007;

class mint{
      public:
      long long x;
      mint(long long y = 0){y %= MOD; if (y < 0) y += MOD; x = y;}
      mint operator+(mint a){return mint(x + a.x);}
      mint operator-(mint a){return mint(x - a.x);}
      mint operator*(mint a){return mint(x * a.x);}
      mint operator=(mint a){x = a.x; return a;}
      void operator+=(mint a){*this = *this + a;}
      void operator-=(mint a){*this = *this - a;}
      void operator*=(mint a){*this = *this * a;}
};

int n;
int b[505];

mint memo[505][505];
bool bio[505][505];
mint dp(int lo, int hi){ // [lo,hi] = set podstabla bez podroota
     if (lo >= hi) return 1;
     mint &r = memo[lo][hi];
     if (bio[lo][hi]++) return r;
     
     int x = b[lo];
     for (int i = lo; i <= hi; ++i){
         if (i != hi && b[i + 1] < x) continue;
         r += dp(lo + 1, i) * dp(i + 1, hi);
     }
     
     return r;
     
}

int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", b + i);
    printf("%I64d\n", dp(1, n - 1).x);
    return 0;
}