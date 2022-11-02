#include <cstdio>
#include <algorithm>

using namespace std;

int a[5000][5001];
int c[5001];
char s[5000][5001];

int main()
{
    int n, m, ans = 0, i, j;
    
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < n; i++) scanf("%s", s[i]);
    
    for (i = 0; i < n; i++) {
        for (j = m - 1; j >= 0; j--) {
            if (s[i][j] == '0') {
                a[i][j] = 0;
            } else {
                a[i][j] = a[i][j + 1] + 1;
            }
        }
    }
    
    for (i = 0; i < m; i++) {
        int x = 0;
        
        for (j = 0; j <= m; j++) c[j] = 0;
        
        for (j = 0; j < n; j++) c[a[j][i]]++;
        
        for (j = m; j >= 0; j--) {
            x += c[j];
            
            ans = max(ans, x * j);
        }
    }
    
    printf("%d\n", ans);
    
    return 0;
}