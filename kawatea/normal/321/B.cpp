#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, m, ans = 0, i, j;
    int a[100] = {0};
    vector <int> v, w, z;
    
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < n; i++) {
        int x;
        char s[5];
        
        scanf("%s %d", s, &x);
        
        if (s[0] == 'A') {
            v.push_back(x);
        } else {
            w.push_back(x);
        }
    }
    
    for (i = 0; i < m; i++) {
        int x;
        
        scanf("%d", &x);
        
        z.push_back(x);
    }
    
    sort(v.begin(), v.end());
    sort(w.begin(), w.end());
    sort(z.begin(), z.end());
    
    for (i = 1; i <= v.size(); i++) {
        int sum = 0;
        
        if (i > z.size()) break;
        
        for (j = 0; j < i; j++) {
            if (z[z.size() - j - 1] < v[j]) break;
            
            sum += z[z.size() - j - 1] - v[j];
        }
        
        if (j == i) ans = max(ans, sum);
    }
    
    if (n < m) {
        int sum = 0;
        
        for (i = 0; i < w.size(); i++) {
            for (j = 0; j < z.size(); j++) {
                if (a[j] == 1) continue;
                
                if (z[j] > w[i]) {
                    a[j] = 1;
                    
                    break;
                }
            }
            
            if (j == z.size()) break;
        }
        
        if (i == w.size()) {
            for (i = 0; i < v.size(); i++) {
                for (j = 0; j < z.size(); j++) {
                    if (a[j] == 1) continue;
                    
                    if (z[j] >= v[i]) {
                        a[j] = 1;
                        
                        sum += z[j] - v[i];
                        
                        break;
                    }
                }
                
                if (j == z.size()) break;
            }
            
            if (i == v.size()) {
                for (i = 0; i < z.size(); i++) {
                    if (a[i] == 0) sum += z[i];
                }
                
                ans = max(ans, sum);
            }
        }
    }
    
    printf("%d\n", ans);
    
    return 0;
}