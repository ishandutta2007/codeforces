#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int a[10000];
int sum[1000];

int main()
{
    int n, m, i, j;
    vector <int> v, w, z;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        int x;
        
        scanf("%d", &x);
        
        v.push_back(x);
    }
    
    a[0] = a[1] = 1;
    
    for (i = 2; i * i <= 1e7; i++) {
        if (a[i] == 0) {
            int c = 0;
            
            for (j = i * 2; (long long)j * j <= 1e7; j += i) a[j] = 1;
            
            for (j = 0; j < n; j++) {
                if (v[j] % i == 0) {
                    while (v[j] % i == 0) v[j] /= i;
                    
                    c++;
                }
            }
            
            w.push_back(i);
            sum[w.size()] = sum[w.size() - 1] + c;
        }
    }
    
    for (i = 0; i < n; i++) {
        if (v[i] > 1) z.push_back(v[i]);
    }
    
    sort(z.begin(), z.end());
    
    scanf("%d", &m);
    
    for (i = 0; i < m; i++) {
        int x, y, ans;
        
        scanf("%d %d", &x, &y);
        
        ans = sum[upper_bound(w.begin(), w.end(), y) - w.begin()] + (upper_bound(z.begin(), z.end(), y) - z.begin()) - sum[lower_bound(w.begin(), w.end(), x) - w.begin()] - (lower_bound(z.begin(), z.end(), x) - z.begin());
        
        printf("%d\n", ans);
    }
    
    return 0;
}