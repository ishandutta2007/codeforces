#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int a[3000];
int b[3000];

int main()
{
    int n, m, c = 0, i;
    vector <pair<int, int> > v;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        
        a[i]--;
    }
    
    scanf("%d", &m);
    
    for (i = 0; i < n; i++) {
        if (b[i] == 0) {
            int x = i;
            
            while (1) {
                if (b[x] == 1) break;
                
                b[x] = 1;
                x = a[x];
            }
            
            c++;
        }
    }
    
    c = n - c;
    
    while (c < m) {
        int x = 0;
        
        for (i = 0; i < n; i++) b[i] = 0;
        
        while (1) {
            if (b[x] == 1) break;
            
            b[x] = 1;
            x = a[x];
        }
        
        for (i = 0; i < n; i++) {
            if (b[i] == 0) {
                swap(a[0], a[i]);
                v.push_back(make_pair(1, i + 1));
                
                break;
            }
        }
        
        c++;
    }
    
    while (c > m) {
        for (i = 0; i < n; i++) b[i] = 0;
        
        for (i = 0; i < n; i++) {
            int x = i, m = 1e9;
            
            while (1) {
                if (b[x] == 1) break;
                
                if (x != i) m = min(m, x);
                b[x] = 1;
                x = a[x];
            }
            
            if (m != 1e9) {
                swap(a[i], a[m]);
                v.push_back(make_pair(i + 1, m + 1));
                
                break;
            }
        }
        
        c--;
    }
    
    printf("%d\n", v.size());
    
    for (i = 0; i < v.size(); i++) {
        if (i > 0) putchar(' ');
        
        printf("%d %d", v[i].first, v[i].second);
    }
    
    puts("");
    
    return 0;
}