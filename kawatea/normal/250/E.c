#include <stdio.h>

int abs(int a)
{
    if (a < 0) return -a;
    
    return a;
}

int main()
{
    int n, m, y = 1, z = 1, p, q, i, j;
    long long sum = 0;
    char s[100][10003];
    
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < n; i++) scanf("%s", &s[i][1]);
    
    for (i = 0; i < n; i++) s[i][0] = s[i][m + 1] = '#';
    
    for (i = 0; i < n - 1; i++) {
        int f = 0, c = 0;
        
        for (p = y; ; p--) {
            if (s[i][p] != '.') break;
        }
        
        for (q = y; ; q++) {
            if (s[i][q] != '.') break;
        }
        
        for (j = y; ; j += z) {
            if (s[i][j] != '.') break;
            
            if (s[i + 1][j] == '.') {
                f = 1;
                
                break;
            }
        }
        
        if (f == 1) {
            sum += abs(y - j);
            
            y = j;
            
            continue;
        }
        
        for (j = y; ; j -= z) {
            if (s[i][j] != '.') break;
            
            if (s[i + 1][j] == '.') {
                f = 1;
                
                break;
            }
        }
        
        if (f == 1) {
            if (z == 1) {
                sum += (q - y) * 2 - 1 + y - j;
            } else {
                sum += (y - p) * 2 - 1 + j - y;
            }
            
            y = j;
            z = -z;
            
            continue;
        }
        
        while (f == 0) {
            if (z == 1) {
                sum += q - y;
                
                y = q - 1;
                z = -z;
                
                if (s[i][q] == '+') {
                    for (q++; ; q++) {
                        if (s[i][q] != '.') break;
                    }
                    
                    for (j = y + 1; j < q; j++) {
                        if (s[i + 1][j] == '.') {
                            sum += y - p + j - p - 1;
                            
                            y = j;
                            z = -z;
                            
                            f = 1;
                            
                            break;
                        }
                    }
                    
                    c = 0;
                } else {
                    c++;
                }
            } else {
                sum += y - p;
                
                y = p + 1;
                z = -z;
                
                if (s[i][p] == '+') {
                    for (p--; ; p--) {
                        if (s[i][p] != '.') break;
                    }
                    
                    for (j = y - 1; j > p; j--) {
                        if (s[i + 1][j] == '.') {
                            sum += q - y + q - j - 1;
                            
                            y = j;
                            z = -z;
                            
                            f = 1;
                            
                            break;
                        }
                    }
                    
                    c = 0;
                } else {
                    c++;
                }
            }
            
            if (c == 2) {
                puts("Never");
                
                return 0;
            }
        }
    }
    
    printf("%I64d\n", sum + n - 1);
    
    return 0;
}