#include <cstdio>
#include <algorithm>

using namespace std;

int n;
long long l, r;

unsigned int cc;
int pc(long long a){
    return __builtin_popcount(a & cc) + __builtin_popcount(a >> 32);
}

long long merge(long long a, long long b){
     int x = pc(a), y = pc(b);
     if (x != y){if (x < y) return b; return a;}
     return min(a, b);
}

long long memo[105][2][2]; bool bio[105][2][2];
long long dp(int pos, bool b1, bool b2){
     if (pos < 0) return 0;
     long long &r = memo[pos][b1][b2];
     if (bio[pos][b1][b2]++) return r;
     bool bl = ((l >> pos) & 1), br = ((::r >> pos) & 1);
     if (!bl && br) return r = merge(dp(pos - 1, b1, false), dp(pos - 1, false, b2) | (1LL << pos));
     if (bl && br){
        r = (dp(pos - 1, b1, b2) | (1LL << pos));
        if (!b1) r = merge(r, dp(pos - 1, false, false));
        return r;
     }
     if (!bl && !br){
        r = dp(pos - 1, b1, b2);
        if (!b2){/*printf("A"); */r = merge(r, dp(pos - 1, false, false) | (1LL << pos));}
        return r;
     }
     // bl = 1; br = 0;
     if (!b2) r = (dp(pos - 1, b1, b2) | (1LL << pos));
     if (!b1) r = merge(r, dp(pos - 1, b1, b2));
     return r;
}

int main(){
    cc = ~0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i){
        scanf("%I64d%I64d", &l, &r);
        printf("%I64d\n", dp(60, true, true));
        for (int i = 0; i <= 100; ++i) for (int j = 0; j < 2; ++j) for (int k = 0; k < 2; ++k) memo[i][j][k] = bio[i][j][k] = 0;
    }
    return 0;
}