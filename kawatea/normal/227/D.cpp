#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, q, i;
    long long p = 0;
    vector <int> v;
    vector <long long> s;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        int x;
        
        scanf("%d", &x);
        
        v.push_back(x);
    }
    
    sort(v.begin(), v.end());
    
    s.push_back(0);
    
    for (i = 0; i < v.size(); i++) s.push_back(s.back() + v[i]);
    
    for (i = 0; i < v.size() - 1; i++) p += (long long)v[i] * (n - i - 1);
    
    scanf("%d", &q);
    
    for (i = 0; i < q; i++) {
        int k;
        long long sum = 0;
        
        scanf("%d", &k);
        
        if (k == 1) {
            sum = p;
        } else {
            int x = n - 2;
            int y = max(0, x - k + 1);
            int t = 1;
            
            while (x >= 0) {
                long long z;
                
                sum += (s[x + 1] - s[y]) * t;
                
                z = (long long)(x - y + 1) * k;
                
                x = y - 1;
                y = max(0LL, x - z + 1);
                
                t++;
            }
        }
        
        if (i > 0) putchar(' ');
        
        printf("%I64d", sum);
    }
    
    puts("");
    
    return 0;
}