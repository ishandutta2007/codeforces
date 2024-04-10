#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int a[4000][4000];
vector <int> v[4000];

int main()
{
    int n, m, ans = 1e9, i, j, k;
    
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < m; i++) {
        int x, y;
        
        scanf("%d %d", &x, &y);
        
        x--;
        y--;
        
        a[x][y] = a[y][x] = 1;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < v[i].size(); j++) {
            for (k = j + 1; k < v[i].size(); k++) {
                if (a[v[i][j]][v[i][k]] == 1) {
                    ans = min(ans, (int)v[i].size() + (int)v[v[i][j]].size() + (int)v[v[i][k]].size() - 6);
                }
            }
        }
    }
    
    if (ans == 1e9) {
        puts("-1");
    } else {
        printf("%d\n", ans);
    }
    
    return 0;
}