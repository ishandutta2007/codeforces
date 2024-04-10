#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

long long a[100000];

long long gcd(long long a, long long b)
{
    if (a % b == 0) return b;
    
    return gcd(b, a % b);
}

int main()
{
    int n, i;
    long long sum = 0, g;
    vector <long long> v;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        int x;
        
        scanf("%d", &x);
        
        v.push_back(x);
    }
    
    sort(v.begin(), v.end());
    
    for (i = 1; i < v.size(); i++) a[i] = a[i - 1] + (v[i] - v[i - 1]) * i;
    
    for (i = 0; i < v.size(); i++) sum += a[i] * 2 + v[i];
    
    g = gcd(sum, n);
    
    printf("%I64d %I64d\n", sum / g, n / g);
    
    return 0;
}