#include <cstdio>
#include <vector>

using namespace std;

int a[100000];
int b[100000];
vector <int> v[100000];
vector <int> w;

void dfs(int x, int y, int z1, int z2)
{
    int i;
    
    if (z1 == 0) {
        if (a[x] != b[x]) {
            z1 = 1 - z1;
            w.push_back(x);
        }
    } else {
        if (a[x] == b[x]) {
            z1 = 1 - z1;
            w.push_back(x);
        }
    }
    
    for (i = 0; i < v[x].size(); i++) {
        if (v[x][i] == y) continue;
        
        dfs(v[x][i], x, z2, z1);
    }
}

int main()
{
    int n, i;
    
    scanf("%d", &n);
    
    for (i = 0; i < n - 1; i++) {
        int x, y;
        
        scanf("%d %d", &x, &y);
        
        x--;
        y--;
        
        v[x].push_back(y);
        v[y].push_back(x);
    }
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    for (i = 0; i < n; i++) scanf("%d", &b[i]);
    
    dfs(0, -1, 0, 0);
    
    printf("%d\n", w.size());
    
    for (i = 0; i < w.size(); i++) printf("%d\n", w[i] + 1);
    
    return 0;
}