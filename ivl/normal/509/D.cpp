#include <cstdio>
#include <algorithm>

using namespace std;

long long gcd(long long a, long long b){
     if (a < 0) a = -a;
     if (b < 0) b = -b;
     while (b){a %= b; swap(a, b);}
     return a;
}

int n, m;
long long w[105][105];

long long a[105], b[105];

int main(){
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            scanf("%I64d", w[i] + j);
    a[0] = 0;
    for (int i = 0; i < m; ++i) b[i] = w[0][i];
    for (int i = 0; i < n; ++i) a[i] = w[i][0] - b[0];
    
    long long k = 0;
    
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            k = gcd(k, w[i][j] - a[i] - b[j]);
    
    if (k == 0) k = 1000000000000000000LL;
    
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (w[i][j] >= k){printf("NO\n"); return 0;}
    
    printf("YES\n");
    printf("%I64d\n", k);
    
    for (int i = 0; i < n; ++i){
        a[i] %= k;
        if (a[i] < 0) a[i] += k;
        printf("%I64d ", a[i]);
    } printf("\n");
    
    for (int i = 0; i < m; ++i){
        b[i] %= k;
        if (b[i] < 0) b[i] += k;
        printf("%I64d ", b[i]);
    } printf("\n");
    
    return 0;
}