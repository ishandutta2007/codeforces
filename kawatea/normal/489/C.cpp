#include <cstdio>

using namespace std;

int dp[101][901];
char s1[101];
char s2[101];

int main()
{
    int m, s, i, j, k;
    
    scanf("%d %d", &m, &s);
    
    if (m == 1 && s == 0) {
        puts("0 0");
        
        return 0;
    }
    
    dp[0][0] = 1;
    
    for (i = 0; i < m; i++) {
        for (j = 0; j <= s; j++) {
            if (dp[i][j] == 0) continue;
            
            for (k = 0; k < 10; k++) {
                if (j + k > s) break;
                
                if (i == m - 1 && k == 0) continue;
                
                dp[i + 1][j + k] = 1;
            }
        }
    }
    
    if (dp[m][s] == 0) {
        puts("-1 -1");
    } else {
        int x = s;
        
        for (i = 0; i < m; i++) {
            for (j = 0; j < 10; j++) {
                if (x - j < 0) continue;
                
                if (i == 0 && j == 0) continue;
                
                if (dp[m - i - 1][x - j] == 1) {
                    s1[i] = j + '0';
                    x -= j;
                    
                    break;
                }
            }
        }
        
        x = s;
        
        for (i = 0; i < m; i++) {
            for (j = 9; j >= 0; j--) {
                if (x - j < 0) continue;
                
                if (dp[m - i - 1][x - j] == 1) {
                    s2[i] = j + '0';
                    x -= j;
                    
                    break;
                }
            }
        }
        
        printf("%s %s\n", s1, s2);
    }
    
    return 0;
}