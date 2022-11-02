#include <cstdio>

using namespace std;

int main()
{
    int n, m, ans = 0, i, j;
    char s[1000][1001];
    int a[1000] = {0};
    
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < n; i++) scanf("%s", s[i]);
    
    for (i = 0; i < n; i++) {
        int x = -1;
        
        for (j = 0; j < m; j++) {
            if (s[i][j] == 'G') {
                x = j;
            } else if (s[i][j] == 'S') {
                if (x == -1) {
                    puts("-1");
                    
                    return 0;
                }
                
                a[j - x] = 1;
                
                break;
            }
        }
    }
    
    for (i = 0; i < m; i++) ans += a[i];
    
    printf("%d\n", ans);
    
    return 0;
}