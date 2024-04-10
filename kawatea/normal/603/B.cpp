#include <cstdio>

using namespace std;

int par[1000000];
int c[1000000];

int find(int x) {
    if (par[x] == x) return x;
    
    return par[x] = find(par[x]);
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);
    
    if (x == y) return;
    
    par[x] = y;
}

int main()
{
    int p, k, m = 1000000007, i;
    long long ans = 1;
    
    scanf("%d %d", &p, &k);
    
    if (k == 0) {
        for (i = 0; i < p - 1; i++) ans = ans * p % m;
        
        printf("%I64d\n", ans);
        
        return 0;
    }
    
    for (i = 0; i < p; i++) par[i] = i;
    
    for (i = 0; i < p; i++) unite((long long)k * i % p, i);
    
    for (i = 0; i < p; i++) c[find(i)]++;
    
    for (i = 0; i < p; i++) {
        if (find(0) == i) {
            if (k == 1) {
                ans = ans * p % m;
            }
        } else if (c[i] > 0) {
            ans = ans * p % m;
        }
    }
    
    printf("%I64d\n", ans);
    
    return 0;
}