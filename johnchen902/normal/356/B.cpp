#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

long long n, m;
char x[1000001], y[1000001];
int lx, ly;

int cnt[1000001][26];

int main(){
    scanf("%I64d%I64d%s%s", &n, &m, x, y);
    lx = strlen(x);
    ly = strlen(y);
    int gcd = __gcd(lx, ly);
    for(int i = 0; i < ly; i++)
        cnt[i % gcd][y[i] - 'a']++;

    long long hamming = n * 1ll * lx;
    for(int i = 0; i < lx; i++)
        hamming -= (long long) cnt[i % gcd][x[i] - 'a'] * n / (ly / gcd);
    printf("%I64d\n", hamming);
}