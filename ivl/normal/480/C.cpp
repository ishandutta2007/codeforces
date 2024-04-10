#include <cstdio>
#include <algorithm>

using namespace std;

int limit;

long long memo[5005][5005]; bool bio[5005][5005];
long long dp(int a, int k){
     if (a <= 0) return 0;
     long long &r = memo[a][k];
     if (bio[a][k]++) return r;
     if (k == 0) return r = a;
     return r = (dp(a - 1, k) + dp(min(a * 2 - 1, limit), k - 1) - dp(a, k - 1) + dp(a - 1, k - 1) + 1000000007) % 1000000007;
}

int n, a, b, k;

int main(){
    scanf("%d%d%d%d", &n, &a, &b, &k);
    int x = b - a; if (x < 0) x = -x;
    if (a > b) limit = n - b; else limit = b - 1;
    printf("%I64d\n", (dp(x, k) - dp(x - 1, k) + 1000000007) % 1000000007);
    return 0;
}