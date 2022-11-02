#include <cstdio>
#include <vector>

using namespace std;

vector <int> v[100000];

int main()
{
    int n, m, k, p = 0, i, j;
    int a[100000];
    int b[100000];
    
    scanf("%d %d %d", &n, &m, &k);
    
    for (i = 0; i < m; i++) {
        int x, y;
        
        scanf("%d %d", &x, &y);
        
        x--;
        y--;
        
        v[x].push_back(y);
        v[y].push_back(x);
    }
    
    for (i = 0; i < n; i++) b[i] = -1;
    
    a[0] = 0;
    b[0] = 0;
    
    while (1) {
        for (i = 0; i < v[a[p]].size(); i++) {
            if (b[v[a[p]][i]] == -1) {
                a[p + 1] = v[a[p]][i];
                b[v[a[p]][i]] = p + 1;
                
                break;
            }
        }
        
        if (i == v[a[p]].size()) {
            for (i = 0; i < v[a[p]].size(); i++) {
                if (b[v[a[p]][i]] <= p - k) {
                    printf("%d\n", p - b[v[a[p]][i]] + 1);
                    
                    for (j = b[v[a[p]][i]]; j <= p; j++) {
                        if (j > b[v[a[p]][i]]) putchar(' ');
                        
                        printf("%d", a[j] + 1);
                    }
                    
                    puts("");
                    
                    return 0;
                }
            }
        }
        
        p++;
    }
    
    return 0;
}