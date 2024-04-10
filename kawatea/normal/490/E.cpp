#include <cstdio>
#include <cstring>

using namespace std;

int a[100000];
char s[100000][10];

int main()
{
    int n, i, j, k;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) scanf("%s", s[i]);
    
    for (i = 0; i < n; i++) a[i] = strlen(s[i]);
    
    for (i = 0; i < a[0]; i++) {
        if (s[0][i] == '?') {
            if (i == 0) {
                s[0][i] = '1';
            } else {
                s[0][i] = '0';
            }
        }
    }
    
    for (i = 1; i < n; i++) {
        if (a[i] < a[i - 1]) {
            puts("NO");
            
            return 0;
        }
        
        if (a[i] > a[i - 1]) {
            for (j = 0; j < a[i]; j++) {
                if (s[i][j] == '?') {
                    if (j == 0) {
                        s[i][j] = '1';
                    } else {
                        s[i][j] = '0';
                    }
                }
            }
        } else {
            for (j = 0; j < a[i]; j++) {
                if (s[i][j] == '?') {
                    int x = 0, y = 0;
                    
                    for (k = j + 1; k < a[i]; k++) {
                        x = x * 10 + s[i - 1][k] - '0';
                        y *= 10;
                        
                        if (s[i][k] == '?') {
                            y += 9;
                        } else {
                            y += s[i][k] - '0';
                        }
                    }
                    
                    if (x < y) {
                        s[i][j] = s[i - 1][j];
                    } else if (s[i - 1][j] == '9') {
                        puts("NO");
                        
                        return 0;
                    } else {
                        s[i][j] = s[i - 1][j] + 1;
                        
                        break;
                    }
                } else if (s[i][j] < s[i - 1][j]) {
                    puts("NO");
                    
                    return 0;
                } else if (s[i][j] > s[i - 1][j]) {
                    break;
                }
            }
            
            if (j == a[i]) {
                puts("NO");
                
                return 0;
            }
            
            for (; j < a[i]; j++) {
                if (s[i][j] == '?') s[i][j] = '0';
            }
        }
    }
    
    puts("YES");
    
    for (i = 0; i < n; i++) printf("%s\n", s[i]);
    
    return 0;
}