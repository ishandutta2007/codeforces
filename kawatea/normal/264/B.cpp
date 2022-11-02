#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, ans = 0, i, j;
    int a[100000];
    int b[100001] = {0};
    int c[100001] = {0};
    vector <int> v;
    
    c[2] = 1;
    v.push_back(2);
    
    for (i = 3; i <= 100000; i += 2) {
        for (j = 0; j < v.size(); j++) {
            if (i % v[j] == 0) break;
        }
        
        if (j == v.size()) {
            c[i] = 1;
            v.push_back(i);
        }
    }
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    
    if (n == 1 && a[0] == 1) {
        puts("1");
        
        return 0;
    }
    
    for (i = 0; i < n; i++) {
        int x = 0;
        vector <int> w;
        
        for (j = 0; j < v.size() && v[j] * v[j] <= a[i]; j++) {
            if (a[i] % v[j] == 0) {
                w.push_back(v[j]);
                
                while (a[i] % v[j] == 0) a[i] /= v[j];
            }
        }
        
        if (c[a[i]] == 1) w.push_back(a[i]);
        
        for (j = 0; j < w.size(); j++) x = max(x, b[w[j]] + 1);
        
        for (j = 0; j < w.size(); j++) b[w[j]] = x;
    }
    
    for (i = 0; i <= 100000; i++) ans = max(ans, b[i]);
    
    printf("%d\n", ans);
    
    return 0;
}