#include <cstdio>

using namespace std;

const long long MOD = 1000000007LL;

long long pot(long long a, long long b){
     if (b == 0) return 1;
     long long r = pot(a, b / 2);
     r = (r * r) % MOD;
     if (b & 1) r = (r * a) % MOD;
     return r;
}

class mint{
      public:
      long long x;
      mint(long long a){x = a;}
      mint operator+(mint a){
           return (x + a.x) % MOD;
      }
      mint operator-(mint a){
           return (MOD + x - a.x) % MOD;
      }
      mint operator*(mint a){
           return (x * a.x) % MOD;
      }
      mint operator/(mint a){
           return (x * pot(a.x, MOD - 2)) % MOD;
      }
};

int n;
long long s;
long long f[25];

mint choose(mint a, mint b){
     //printf("%I64d %I64d\n", a.x, b.x);
     mint r = 1;
     mint rr = 1;
     for (int i = 1; i <= b.x; ++i) rr = rr * i;
     //printf("%I64d\n", rr.x);
     r = r / rr;
     for (int i = 0; i < b.x; ++i) r = r * (a - i);
     return r;
}

mint pick(long long x){
     if (x < 0) return 0;
     if (x == 0) return 1;
     return choose(x + n - 1, (long long)n - 1);
}

int main(){
    //n = 2;
    //printf("%I64d\n", pick(1).x);
    scanf("%d%I64d", &n, &s);
    for (int i = 0; i < n; ++i) scanf("%I64d", f + i);
    mint r = 0;
    for (int i = 0; i < (1 << n); ++i){
        long long cs = s;
        for (int j = 0; j < n; ++j) if (i & (1 << j)) cs = cs - f[j] - 1;
        if (__builtin_popcount(i) & 1) r = r - pick(cs);
        else r = r + pick(cs);
    }
    printf("%I64d\n", r.x);
    return 0;
}