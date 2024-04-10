#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int a[100000][2];
vector <int> vx[100001];
vector <int> vy[100001];

int main()
{
    int n, ans = 0, i, j;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        int x, y;
        
        scanf("%d %d", &x, &y);
        
        a[i][0] = x;
        a[i][1] = y;
        vx[x].push_back(y);
        vy[y].push_back(x);
    }
    
    for (i = 0; i <= 100000; i++) {
        sort(vx[i].begin(), vx[i].end());
        sort(vy[i].begin(), vy[i].end());
    }
    
    for (i = 0; i < n; i++) {
        int x = a[i][0];
        int y = a[i][1];
        int p, q;
        
        p = lower_bound(vx[x].begin(), vx[x].end(), y) - vx[x].begin();
        q = lower_bound(vy[y].begin(), vy[y].end(), x) - vy[y].begin();
        
        if (vx[x].size() - p < vy[y].size() - q) {
            for (j = p + 1; j < vx[x].size(); j++) {
                int y2 = vx[x][j];
                
                if (binary_search(vy[y].begin(), vy[y].end(), x + y2 - y) && binary_search(vy[y2].begin(), vy[y2].end(), x + y2 - y)) ans++;
            }
        } else {
            for (j = q + 1; j < vy[y].size(); j++) {
                int x2 = vy[y][j];
                
                if (binary_search(vx[x].begin(), vx[x].end(), y + x2 - x) && binary_search(vx[x2].begin(), vx[x2].end(), y + x2 - x)) ans++;
            }
        }
    }
    
    printf("%d\n", ans);
    
    return 0;
}