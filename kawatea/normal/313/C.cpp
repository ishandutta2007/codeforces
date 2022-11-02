#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, p = 1, c = 0, i, j;
    long long sum = 0;
    vector <int> v;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        int x;
        
        scanf("%d", &x);
        
        v.push_back(x);
    }
    
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    
    for (i = 0; ; i++) {
        if (p == n) break;
        
        p *= 4;
        c++;
    }
    
    p = 1;
    
    for (i = 0, j = 0; i <= c; i++) {
        for (; j < p; j++) sum += (long long)v[j] * (c - i + 1);
        
        p *= 4;
    }
    
    printf("%I64d\n", sum);
    
    return 0;
}