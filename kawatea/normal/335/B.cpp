#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int dp[50001][101];
int dp2[50001][101][2];

int main()
{
    int n, i, j, k;
    char s[50001];
    vector <int> v[26];
    vector <int> w[26];
    
    scanf("%s", s);
    
    n = strlen(s);
    
    for (i = 0; i < n; i++) {
        v[s[i] - 'a'].push_back(i);
        w[s[i] - 'a'].push_back(-i);
    }
    
    for (i = 0; i < 26; i++) reverse(w[i].begin(), w[i].end());
    
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= 100; j++) {
            dp[i][j] = -1;
            dp2[i][j][0] = dp2[i][j][1] = -1;
        }
    }
    
    dp[0][0] = n;
    
    for (i = 0; i < n; i++) {
        for (j = 0; j <= 100; j++) {
            int z;
            
            if (dp[i][j] == -1) continue;
            
            if (j == 100) {
                int x, y, p = 0;
                char ans[101];
                
                x = i;
                y = j;
                
                while (1) {
                    int nx = dp2[x][y][0];
                    int ny = dp2[x][y][1];
                    
                    if (nx == -1 && ny == -1) break;
                    
                    if (y != ny) {
                        ans[50 + p] = ans[49 - p] = s[nx];
                        
                        p++;
                    }
                    
                    x = nx;
                    y = ny;
                }
                
                ans[100] = '\0';
                
                printf("%s\n", ans);
                
                return 0;
            }
            
            if (dp[i + 1][j] < dp[i][j]) {
                dp[i + 1][j] = dp[i][j];
                dp2[i + 1][j][0] = i;
                dp2[i + 1][j][1] = j;
            }
            
            if (j % 2 == 1) continue;
            
            if (i >= dp[i][j]) continue;
            
            z = upper_bound(w[s[i] - 'a'].begin(), w[s[i] - 'a'].end(), -dp[i][j]) - w[s[i] - 'a'].begin();
            
            z = -w[s[i] - 'a'][z];
            
            if (z > i) {
                if (dp[i + 1][j + 2] < z) {
                    dp[i + 1][j + 2] = z;
                    dp2[i + 1][j + 2][0] = i;
                    dp2[i + 1][j + 2][1] = j;
                }
            }
            
            dp[i + 1][j + 1] = i;
            dp2[i + 1][j + 1][0] = i;
            dp2[i + 1][j + 1][1] = j;
        }
    }
    
    for (i = 100; i >= 0; i--) {
        if (dp[n][i] != -1) {
            int x, y, p = 0;
            char ans[101];
            
            x = n;
            y = i;
            
            while (1) {
                int nx = dp2[x][y][0];
                int ny = dp2[x][y][1];
                
                if (nx == -1 && ny == -1) break;
                
                if (y != ny) {
                    if (i % 2 == 1 && p == 0) {
                        ans[i / 2] = s[nx];
                    } else if (i % 2 == 1) {
                        ans[i / 2 + p] = ans[i / 2 - p] = s[nx];
                    } else {
                        ans[i / 2 + p] = ans[i / 2 - p - 1] = s[nx];
                    }
                    
                    p++;
                }
                
                x = nx;
                y = ny;
            }
            
            ans[i] = '\0';
            
            printf("%s\n", ans);
            
            break;
        }
    }
    
    return 0;
}