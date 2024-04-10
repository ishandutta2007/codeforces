#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int a[500000];

int main()
{
    int n, i, j;
    long long ans = 0;
    vector <int> v;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    
    for (i = 0; i < n; i++) {
        while (v.size() > 1) {
            if (a[i] < v.back()) break;
            if (v.back() > v[v.size() - 2]) break;
            
            v.pop_back();
            
            ans += min(v.back(), a[i]);
        }
        
        v.push_back(a[i]);
    }
    
    for (i = 1; i < v.size() - 1; i++) {
        if (v[i] > a[0] && v[i] > a[n - 1]) {
            for (i = 0, j = v.size() - 1; ; ) {
                if (i + 1 == j) break;
                
                ans += min(v[i], v[j]);
                
                if (v[i] < v[j]) {
                    i++;
                } else {
                    j--;
                }
            }
            
            printf("%I64d\n", ans);
            
            return 0;
        }
    }
    
    if (v[0] > v.back()) {
        for (i = 1; i < v.size() - 1; i++) ans += v[i + 1];
    } else {
        for (i = 1; i < v.size() - 1; i++) ans += v[i - 1];
    }
    
    printf("%I64d\n", ans);
    
    return 0;
}