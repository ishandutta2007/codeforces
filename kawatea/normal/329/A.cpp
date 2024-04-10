#include <cstdio>

using namespace std;

char s[100][101];
int a[100];
int b[100];

int main()
{
    int n, i, j;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) scanf("%s", s[i]);
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (s[i][j] == '.') {
                a[i] = 1;
                b[j] = 1;
            }
        }
    }
    
    for (i = 0; i < n; i++) {
        if (a[i] == 0) break;
    }
    
    if (i == n) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (s[i][j] == '.') {
                    printf("%d %d\n", i + 1, j + 1);
                    
                    break;
                }
            }
        }
        
        return 0;
    }
    
    for (i = 0; i < n; i++) {
        if (b[i] == 0) break;
    }
    
    if (i == n) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (s[j][i] == '.') {
                    printf("%d %d\n", j + 1, i + 1);
                    
                    break;
                }
            }
        }
        
        return 0;
    }
    
    puts("-1");
    
    return 0;
}