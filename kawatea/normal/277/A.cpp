#include <cstdio>
#include <vector>

using namespace std;

int par[100];

int find(int x)
{
    if (par[x] == x) return x;
    
    return par[x] = find(par[x]);
}

void unite(int x, int y)
{
    x = find(x);
    y = find(y);
    
    if (x == y) return;
    
    par[x] = y;
}

int main()
{
    int n, m, sum = 0, f = 0, i, j, k;
    vector <int> v[100];
    int c[100] = {0};
    
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < n; i++) par[i] = i;
    
    for (i = 0; i < n; i++) {
        int x;
        
        scanf("%d", &x);
        
        if (x > 0) f = 1;
        
        for (j = 0; j < x; j++) {
            int y;
            
            scanf("%d", &y);
            
            v[y - 1].push_back(i);
        }
    }
    
    for (i = 0; i < m; i++) {
        for (j = 0; j < (int)v[i].size(); j++) {
            for (k = j + 1; k < (int)v[i].size(); k++) {
                unite(v[i][j], v[i][k]);
            }
        }
    }
    
    for (i = 0; i < n; i++) c[find(i)]++;
    
    for (i = 0; i < n; i++) {
        if (c[i] > 0) sum++;
    }
    
    if (f == 0) sum++;
    
    printf("%d\n", sum - 1);
    
    return 0;
}