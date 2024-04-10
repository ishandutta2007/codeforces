#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int a[3000][3000];
vector <int> v[3000];

int main()
{
    int n, m, i, j, k;
    long long ans = 0;
    
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < m; i++) {
        int x, y;
        
        scanf("%d %d", &x, &y);
        
        v[x - 1].push_back(y - 1);
    }
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < v[i].size(); j++) {
            int x = v[i][j];
            
            for (k = 0; k < v[x].size(); k++) a[i][v[x][k]]++;
        }
    }
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i == j) continue;
            
            ans += a[i][j] * (a[i][j] - 1) / 2;
        }
    }
    
    printf("%I64d\n", ans);
    
    return 0;
}