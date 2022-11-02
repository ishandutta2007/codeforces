#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char s1[5001];
char s2[5001];
int a[5001][5001];
int b[5001][5001];
int c[5001][5001];
int d[5000];
int e[5000];

int main()
{
    int n, m, ans = 1e9, i, j;
    
    scanf("%s", s1);
    scanf("%s", s2);
    
    n = strlen(s1);
    m = strlen(s2);
    
    for (i = n - 1; i >= 0; i--) {
        for (j = n - 1; j >= 0; j--) {
            if (s1[i] == s1[j]) {
                a[i][j] = a[i + 1][j + 1] + 1;
            } else {
                a[i][j] = 0;
            }
        }
    }
    
    for (i = m - 1; i >= 0; i--) {
        for (j = m - 1; j >= 0; j--) {
            if (s2[i] == s2[j]) {
                b[i][j] = b[i + 1][j + 1] + 1;
            } else {
                b[i][j] = 0;
            }
        }
    }
    
    for (i = n - 1; i >= 0; i--) {
        for (j = m - 1; j >= 0; j--) {
            if (s1[i] == s2[j]) {
                c[i][j] = c[i + 1][j + 1] + 1;
            } else {
                c[i][j] = 0;
            }
        }
    }
    
    for (i = 0; i < n; i++) {
        int x = 0;
        
        for (j = 0; j < n; j++) {
            if (i == j) continue;
            
            x = max(x, a[i][j]);
        }
        
        d[i] = x;
    }
    
    for (i = 0; i < m; i++) {
        int x = 0;
        
        for (j = 0; j < m; j++) {
            if (i == j) continue;
            
            x = max(x, b[i][j]);
        }
        
        e[i] = x;
    }
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            int x = max(d[i], e[j]);
            
            if (c[i][j] > x) ans = min(ans, x + 1);
        }
    }
    
    if (ans == 1e9) ans = -1;
    
    printf("%d\n", ans);
    
    return 0;
}