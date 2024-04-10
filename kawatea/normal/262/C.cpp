#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int m, n, p = 1e9, sum = 0, i, j;
    vector <int> v;
    
    scanf("%d", &m);
    
    for (i = 0; i < m; i++) {
        int x;
        
        scanf("%d", &x);
        
        p = min(p, x);
    }
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        int x;
        
        scanf("%d", &x);
        
        v.push_back(x);
    }
    
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    
    p += 2;
    
    for (i = 0; i < n; i++) {
        if (i % p < p - 2) sum += v[i];
    }
    
    printf("%d\n", sum);
    
    return 0;
}