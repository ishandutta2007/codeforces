#include <cstdio>
#include <vector>

using namespace std;

int a[200000];
int f[200000];

int main() {
    int n, c = 1, ans = 0, i;
    vector <int> v, w;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    
    for (i = 0; i < n; i++) {
        int x = i;
        
        if (f[i] > 0) continue;
        
        while (1) {
            f[x] = c;
            
            if (f[a[x] - 1] > 0) {
                if (f[a[x] - 1] == c) {
                    if (x == a[x] - 1) {
                        v.push_back(x);
                    } else {
                        w.push_back(x);
                    }
                }
                
                break;
            }
            
            x = a[x] - 1;
        }
        
        c++;
    }
    
    if (v.size() == 0) {
        ans = w.size();
        
        for (i = 0; i < w.size(); i++) a[w[i]] = w[0] + 1;
    } else {
        ans = v.size() + w.size() - 1;
        
        for (i = 0; i < v.size(); i++) a[v[i]] = v[0] + 1;
        for (i = 0; i < w.size(); i++) a[w[i]] = v[0] + 1;
    }
    
    printf("%d\n", ans);
    
    for (i = 0; i < n; i++) {
        if (i > 0) putchar(' ');
        
        printf("%d", a[i]);
    }
    puts("");
    
    return 0;
}