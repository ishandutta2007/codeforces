#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int a[200000];
int b[200000];
int c[400000];
vector <int> v[200000];

int gcd(int a, int b) {
    if (a % b == 0) return b;
    
    return gcd(b, a % b);
}

int main()
{
    int n, i, j;
    long long ans = 0;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    
    for (i = 1; i < n; i++) v[gcd(i, n)].push_back(i);
    
    for (i = 1; i < n; i++) {
        if (v[i].size() == 0) continue;
        
        for (j = 0; j < i; j++) b[j] = 0;
        for (j = 0; j < n * 2; j++) c[j] = 0;
        
        for (j = 0; j < n; j++) b[j % i] = max(b[j % i], a[j]);
        
        for (j = 0; j < n; j++) {
            if (b[j % i] == a[j]) c[j] = c[j + n] = 1;
        }
        
        for (j = n * 2 - 1; j >= 0; j--) {
            if (c[j] > 0) c[j] += c[j + 1];
        }
        
        for (j = 0; j < n; j++) ans += upper_bound(v[i].begin(), v[i].end(), c[j]) - v[i].begin();
    }
    
    printf("%I64d\n", ans);
    
    return 0;
}