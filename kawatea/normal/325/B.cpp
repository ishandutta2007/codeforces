#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    long long n, i;
    vector <long long> v;
    
    scanf("%I64d", &n);
    
    for (i = 0; i < 62; i++) {
        long long x, y;
        
        x = 1 - ((1LL << i) - 1) * 2;
        
        y = sqrt((long double)x * x + (long double)8 * n);
        
        if ((y + x) % 2 == 1) continue;
        
        y = (y + x) / 2;
        
        if (y % 2 == 0) continue;
        
        if (((1LL << i) - 1) * y / y != ((1LL << i) - 1)) continue;
        if (((1LL << i) - 1) * y + y * (y - 1) / 2 != n) continue;
        
        v.push_back(y * (1LL << i));
    }
    
    sort(v.begin(), v.end());
    
    if (v.size() == 0) {
        puts("-1");
    } else {
        for (i = 0; i < v.size(); i++) printf("%I64d\n", v[i]);
    }
    
    return 0;
}