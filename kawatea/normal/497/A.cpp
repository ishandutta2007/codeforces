#include <cstdio>

using namespace std;

int a[1000];
char s[1000][1001];

int main()
{
    int n, m, ans = 0, i, j;
    
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < n; i++) scanf("%s", s[i]);
    
    for (i = 0; i < m; i++) {
        for (j = 0; j < n - 1; j++) {
            if (a[j] == 1) continue;
            
            if (s[j][i] > s[j + 1][i]) break;
        }
        
        if (j < n - 1) {
            ans++;
            
            continue;
        }
        
        for (j = 0; j < n - 1; j++) {
            if (s[j][i] < s[j + 1][i]) a[j] = 1;
        }
    }
    
    printf("%d\n", ans);
    
    return 0;
}