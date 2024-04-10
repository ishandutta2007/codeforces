#include <stdio.h>

int a[52];
int dp[2][52][52][52][52];

int hash(char s[3])
{
    int x = 0;
    
    if (s[0] >= '2' && s[0] <= '9') {
        x = s[0] - '1';
    } else if (s[0] == 'T') {
        x = 9;
    } else if (s[0] == 'J') {
        x = 10;
    } else if (s[0] == 'Q') {
        x = 11;
    } else if (s[0] == 'K') {
        x = 12;
    }
    
    if (s[1] == 'S') {
        x += 13;
    } else if (s[1] == 'D') {
        x += 26;
    } else if (s[1] == 'H') {
        x += 39;
    }
    
    return x;
}

int ok(int a, int b)
{
    if (a / 13 == b / 13 || a % 13 == b % 13) {
        return 1;
    } else {
        return 0;
    }
}

int check(int n)
{
    int tmp;
    
    if (n == 0) return 1;
    
    if (n == 3 && ok(a[0], a[3])) {
        tmp = a[0];
        a[0] = a[3];
        
        if (check(n - 1) == 1) return 1;
        
        a[3] = a[0];
        a[0] = tmp;
    }
    
    if (ok(a[n - 1], a[n])) {
        tmp = a[n - 1];
        a[n - 1] = a[n];
        
        if (check(n - 1) == 1) return 1;
        
        a[n] = a[n - 1];
        a[n - 1] = tmp;
    }
    
    return 0;
}

int main()
{
    int n, i, j, k, l, m;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        char s[3];
        
        scanf("%s", s);
        
        a[i] = hash(s);
    }
    
    if (n < 4) {
        if (check(n) == 1) {
            puts("YES");
        } else {
            puts("NO");
        }
        
        return 0;
    }
    
    dp[(n - 1) % 2][a[n - 4]][a[n - 3]][a[n - 2]][a[n - 1]] = 1;
    
    for (i = n - 1; i >= 4; i--) {
        for (j = 0; j < 52; j++) {
            for (k = 0; k < 52; k++) {
                for (l = 0; l < 52; l++) {
                    for (m = 0; m < 52; m++) {
                        if (dp[i % 2][j][k][l][m] == 0) continue;
                        
                        if (ok(j, m)) {
                            dp[(i - 1) % 2][a[i - 4]][m][k][l] = 1;
                        }
                        
                        if (ok(l, m)) {
                            dp[(i - 1) % 2][a[i - 4]][j][k][m] = 1;
                        }
                        
                        dp[i % 2][j][k][l][m] = 0;
                    }
                }
            }
        }
    }
    
    for (i = 0; i < 52; i++) {
        for (j = 0; j < 52; j++) {
            for (k = 0; k < 52; k++) {
                for (l = 0; l < 52; l++) {
                    if (dp[1][i][j][k][l] == 1) {
                        a[0] = i;
                        a[1] = j;
                        a[2] = k;
                        a[3] = l;
                        
                        if (check(3) == 1) {
                            puts("YES");
                            
                            return 0;
                        }
                    }
                }
            }
        }
    }
    
    puts("NO");
    
    return 0;
}