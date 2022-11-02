#include <cstdio>
#include <vector>

using namespace std;

vector <int> v[100000];
vector <int> w;
int a[100000];
int b[100000];
int c[100000];

int main()
{
    int n, m, i, j;
    
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < m; i++) {
        int x, y;
        
        scanf("%d %d", &x, &y);
        
        x--;
        y--;
        
        v[x].push_back(y);
        v[y].push_back(x);
    }
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    
    for (i = 0; i < n; i++) {
        b[i] = 1;
        c[i] = v[i].size() + 1;
        
        w.push_back(i);
    }
    
    while (1) {
        int f = 0;
        vector <int> z;
        
        for (i = 0; i < w.size(); i++) {
            if (c[w[i]] < a[w[i]]) {
                f = 1;
            } else if (c[w[i]] == a[w[i]]) {
                b[w[i]] = 0;
                
                for (j = 0; j < v[w[i]].size(); j++) c[v[w[i]][j]]--;
                
                c[w[i]] = -1;
                
                f = 1;
            } else {
                z.push_back(w[i]);
            }
        }
        
        if (f == 0 || z.size() == 0) break;
        
        w = z;
    }
    
    w.clear();
    
    for (i = 0; i < n; i++) {
        if (c[i] == a[i]) {
            puts("-1");
            
            return 0;
        }
        
        if (b[i] == 1) w.push_back(i + 1);
    }
    
    printf("%d\n", w.size());
    
    for (i = 0; i < w.size(); i++) {
        if (i > 0) putchar(' ');
        
        printf("%d", w[i]);
    }
    
    puts("");
    
    return 0;
}